#ifndef __SV_PARSER_NUMBER_PARSER_IPP__
#define __SV_PARSER_NUMBER_PARSER_IPP__
#pragma once

#include "sv/parser/number_parser.hpp"
#include <boost/spirit/include/classic.hpp>

namespace sv
{
namespace detail
{

template<class Char, class Depot>
bool number_subject::operator()(const Char* format, Depot& depot)
{
  using namespace boost::spirit::classic;

  return parse(
    format,
    (
      real_p[push_back_a(depot)]
      >>
      *
      (
        ',' >> real_p[push_back_a(depot)]
      )
    ),
    space_p
  ).full;
}

} // namespace sv::detail
} // namespace sv

#endif // __SV_PARSER_NUMBER_PARSER_IPP__