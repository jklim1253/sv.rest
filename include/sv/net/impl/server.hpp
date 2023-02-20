#ifndef __SV_NET_IMPL_SERVER_HPP__
#define __SV_NET_IMPL_SERVER_HPP__
#pragma once

#include "sv/net/server.hpp"

namespace sv
{

template<class Session>
basic_server<Session>::basic_server(asio::io_context& ioc)
  : r_ioc_(ioc)
{
}

template<class Session>
basic_server<Session>::~basic_server()
{

}

template<class Session>
void basic_server<Session>::set_options()
{

}

template<class Session>
void basic_server<Session>::start()
{
  session_manager_ = std::make_shared<session_manager_type>(r_ioc_);

  tcp::endpoint ep(asio::ip::make_address("0.0.0.0"), 12531);

  asio::post(r_ioc_, std::bind(&session_manager_type::start, session_manager_, ep));
}

template<class Session>
void basic_server<Session>::stop()
{

}

} // namespace sv

#endif // __SV_NET_IMPL_SERVER_HPP__