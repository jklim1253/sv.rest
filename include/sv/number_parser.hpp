#ifndef __SV_NUMBER_PARSER_HPP__
#define __SV_NUMBER_PARSER_HPP__
#pragma once

#include "sv/parser.hpp"
#include <string>

namespace sv
{

namespace detail
{
class number_subject
{
public:
  template<class Char, class Depot>
  bool operator()(const Char* format, Depot& depot) const;

  template<class Char, class Depot>
  bool operator()(std::basic_string<Char> const& format, Depot& depot) const
  {
    return (*this)(format.c_str(), depot);
  }
};

} // namespace sv::detail

using number_parser = basic_parser<detail::number_subject>;

} // namespace sv

#include "sv/number_parser.ipp"

#endif // __SV_NUMBER_PARSER_HPP__