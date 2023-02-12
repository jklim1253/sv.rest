#include "sv/net.hpp"
#include "sv/common.hpp"
#include <cstdint>

namespace test
{

using id_type = std::uint64_t;

template<class T>
struct _id_holder
{
  id_type id() const { return id_; }

protected:
  _id_holder() : id_(s_id_++) {}

private:
  id_type id_;
  inline static id_type s_id_ = 0ULL;
};

class message_protocol
{
public:
  using transport_protocol_type = tcp;

};

template<class Protocol>
class basic_session : public _id_holder<basic_session<Protocol>>
{
public:
  using protocol_type = Protocol;
  using transport_protocol_type = typename protocol_type::transport_protocol_type;

public:
  basic_session()
  {
  }
};

using message_session = basic_session<message_protocol>;

struct scheduler
{
  using self = scheduler;

  scheduler()
    : ioc_()
    , workguard_(ioc_.get_executor())
    , worker_([&]{ ioc_.run(); })
    , sig_(ioc_, SIGINT, SIGTERM)
  {
    sig_.async_wait(std::bind(&self::on_signal, this, _1, _2));
    fmt::print(fg(fmt::color::green_yellow), "press CTRL+C to terminate application...\n");
  }
  ~scheduler()
  {
    if (worker_.joinable())
    {
      worker_.join();
    }
  }

  asio::io_context& context()
  {
    return ioc_;
  }

private:
  void on_signal(error_code const& ec, int signum)
  {
    if (ec)
    {
      on_error(ec, "on_signal");
      return;
    }

    ioc_.stop();
    workguard_.reset();

    fmt::print(fg(fmt::color::yellow), "signal({}) is signalled\n", signum);
  }
  void on_error(error_code const& ec, const char* tag)
  {
    fmt::print(fg(fmt::color::red), "[error:{}:{}] {}\n", tag, ec.value(), ec.message());
  }

private:
  asio::io_context ioc_;
  asio::executor_work_guard<asio::io_context::executor_type> workguard_;
  std::thread worker_;
  asio::signal_set sig_;
};

void test_network()
{
  scheduler processor;

  sv::basic_server<message_session> demo(processor.context());
  demo.set_options();
  demo.start();
  demo.stop();
}

} // namespace test