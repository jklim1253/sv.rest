#ifndef __SV_PARSER_REQUEST_PARSER_HPP__
#define __SV_PARSER_REQUEST_PARSER_HPP__
#pragma once

#include "sv/parser/parser.hpp"
#include <string>
#include <list>

namespace sv
{
namespace detail
{

class request_subject
{
public:
  using result_type = std::list<std::string>;

public:
  template<class Char, class Depot>
  bool operator()(const Char* format, Depot& depot);

  template<class Char, class Depot>
  bool operator()(std::basic_string<Char> const& format, Depot& depot)
  {
    return (*this)(format.c_str(), depot);
  }
};

} // namespace sv::detail

using request_parser = basic_parser<detail::request_subject>;

} // namespace sv

#include "sv/parser/request_parser.ipp"

#endif // __SV_PARSER_REQUEST_PARSER_HPP__