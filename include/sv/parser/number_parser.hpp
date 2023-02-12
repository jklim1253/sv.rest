#ifndef __SV_PARSER_NUMBER_PARSER_HPP__
#define __SV_PARSER_NUMBER_PARSER_HPP__
#pragma once

#include "sv/parser/parser.hpp"
#include <string>

namespace sv
{
namespace detail
{
class number_subject
{
public:
  using result_type = std::list<double>;

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

using number_parser = basic_parser<detail::number_subject>;

} // namespace sv

#include "sv/parser/number_parser.ipp"

#endif // __SV_PARSER_NUMBER_PARSER_HPP__