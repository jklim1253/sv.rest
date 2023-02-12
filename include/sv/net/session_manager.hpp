#ifndef __SV_NET_SESSION_MANAGER_HPP__
#define __SV_NET_SESSION_MANAGER_HPP__
#pragma once

#include "sv/net/config.hpp"

namespace sv
{

template<class Session>
class session_manager
{
public:
  using self = session_manager<Session>;
  using session_type = Session;
  using session_ptr = std::shared_ptr<session_type>;
  using protocol_type = typename session_type::protocol_type;
  using transport_protocol_type = typename session_type::transport_protocol_type;
  using endpoint_type = asio::ip::basic_endpoint<transport_protocol_type>;
  using acceptor_type = asio::basic_socket_acceptor<transport_protocol_type>;

public:
  session_manager(asio::io_context& ioc)
    : r_ioc_(ioc)
    , acceptor_(r_ioc_)
  {
  }

  void start(endpoint_type ep)
  {
    acceptor_.open(ep.protocol());
    acceptor_.bind(ep);
    acceptor_.listen();

    asio::post(r_ioc_, std::bind(&self::do_accept, this));
  }

  void stop()
  {
    if (acceptor_.is_open())
    {
      acceptor_.close();
    }
  }

private:
  void do_accept()
  {
    std::this_thread::sleep_for(1s);
  }

private:
  asio::io_context& r_ioc_;
  acceptor_type acceptor_;
};

} // namespace sv

#endif // __SV_NET_SESSION_MANAGER_HPP__