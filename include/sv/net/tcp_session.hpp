#ifndef __SV_NET_TCP_SESSION_HPP__
#define __SV_NET_TCP_SESSION_HPP__

#include "sv/net/config.hpp"

SV_NET_NS_BEGIN

template<class Protocol>
class tcp_session : public std::enable_shared_from_this<tcp_session>
{
public:
  using self = tcp_session;
  using ptr = std::shared_ptr<self>;
  using wptr = std::weak_ptr<self>;
  using socket_type = tcp::socket;
  using protocol_type = Protocol;

  template<class...Args>
  static ptr make(Args&&...args)
  {
    return ptr(new self(std::forward<Args>(args)...));
  }

private:
  session(asio::io_context& ioc)
    : r_ioc(ioc)
    , socket_(r_ioc)
    , read_buffer_()
    , write_buffer_()
    , read_stream_(&read_buffer_)
    , write_stream_(&write_buffer_)
  {
  }

public:
  ~session()
  {
  }

  socket_type& socket()
  {
    return socket_;
  }

  socket_type& socket() const
  {
    return socket_;
  }

  void start()
  {
    asio::post(r_ioc, std::bind(&self::do_read, shared_from_this()));
  }
  void stop()
  {
    if (socket_.is_open())
    {
      socket_.close();
    }
  }

private:
  void do_read()
  {
    asio::post(r_ioc, std::bind(&self::do_read_header, shared_from_this()));
  }
  void do_read_header()
  {
    protocol_type;

  }
  void do_read_body()
  {

  }
  std::size_t on_completion(error_code const& ec, std::size_t bytes, std::size_t total)
  {
    if (ec)
    {
      on_error(ec, "on_completion");
      return 0ULL;
    }

    return total - bytes;
  }
  void on_read_header(error_code const& ec, std::size_t bytes)
  {

  }
  void on_read_body(error_code const& ec, std::size_t bytes)
  {

  }

  void on_error(error_code const& ec, const char* tag)
  {
    fmt::print("[error:{}:{}]{}\n", tag, ec.value(), ec.message());
  }

private:
  asio::io_context& r_ioc;
  socket_type socket_;

  asio::streambuf read_buffer_;
  asio::streambuf write_buffer_;

  std::istream read_stream_;
  std::ostream write_stream_;
};

SV_NET_NS_END

#endif // __SV_NET_TCP_SESSION_HPP__