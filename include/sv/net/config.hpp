#ifndef __SV_NET_CONFIG_HPP__
#define __SV_NET_CONFIG_HPP__
#pragma once

#include <thread>
#include <memory>
#include <functional>
#include <chrono>

using namespace std::placeholders;
using namespace std::chrono_literals;

#ifndef BOOST_ASIO_NO_DEPRECATED
#define BOOST_ASIO_NO_DEPRECATED
#endif // BOOST_ASIO_NO_DEPRECATED
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif // _WIN32_WINNT
#include <boost/asio.hpp>

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif // FMT_HEADER_ONLY
#include <fmt/format.h>

// alias
namespace asio = boost::asio;
using error_code = boost::system::error_code;
using tcp = asio::ip::tcp;
using udp = asio::ip::udp;
using icmp = asio::ip::icmp;

#ifndef SV_NET_NS_BEGIN
#define SV_NET_NS_BEGIN \
namespace sv {\
inline namespace net {
#endif // SV_NET_NS_BEGIN

#ifndef SV_NET_NS_END
#define SV_NET_NS_END }}
#endif // SV_NET_NS_END

#endif // __SV_NET_CONFIG_HPP__