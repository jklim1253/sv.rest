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
bool request_subject::operator()(const Char* format, Depot& depot)
{
  using namespace boost::spirit::classic;
  
  strlit<> CRLF("\r\n");
  
  return parse
  (
    format,
    // begin grammar
    (
      +
      (
        (+(anychar_p - CRLF))[push_back_a(depot)] >> CRLF
      )
      >>
      *
      (
        CRLF >> (*anychar_p)[push_back_a(depot)]
      )
    )
    // end grammar
  ).full;
}

} // namespace sv::detail
} // namespace sv

#endif // __SV_PARSER_REQUEST_PARSER_IPP__