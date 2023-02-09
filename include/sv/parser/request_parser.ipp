#ifndef __SV_PARSER_REQUEST_PARSER_IPP__
#define __SV_PARSER_REQUEST_PARSER_IPP__
#pragma once

#include "sv/parser/request_parser.hpp"
#include <boost/spirit/include/classic.hpp>

namespace sv
{
namespace detail
{

template<class Char, class Depot>
bool request_subject::operator()(const Char* format, Depot& depot) const
{
  using namespace boost::spirit::classic;
  
  return parse(
    format,
    (
      *((any_p[push_back_a(depot)] | ~"\r\n") >> "\r\n")
      >> "\r\n"
      >> *(any_p[push_back_a(depot)])
    )
  ).full;
}

} // namespace sv::detail
} // namespace sv

#endif // __SV_PARSER_REQUEST_PARSER_IPP__