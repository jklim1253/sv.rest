#ifndef __SV_NET_SERVER_HPP__
#define __SV_NET_SERVER_HPP__
#pragma once

#include "sv/net/config.hpp"
#include "sv/net/session_manager.hpp"

SV_NET_NS_BEGIN

template<class Session>
class basic_server
{
public:
  using self = basic_server<Session>;
  using session_type = Session;
  using session_ptr = std::shared_ptr<session_type>;
  using protocol_type = typename session_type::protocol_type;
  using transport_protocol_type = typename session_type::transport_protocol_type;
  using session_manager_type = sv::session_manager<session_type>;
  using session_manager_ptr = std::shared_ptr<session_manager_type>;

public:
  inline basic_server(asio::io_context& ioc);
  inline ~basic_server();

  inline void set_options();
  inline void start();
  inline void stop();

private:
  asio::io_context& r_ioc_;

  session_manager_ptr session_manager_;
};

SV_NET_NS_END

#include "sv/net/impl/server.hpp"

#endif // __SV_NET_SERVER_HPP__