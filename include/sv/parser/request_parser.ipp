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
  
  return parse
  (
    format,
    // begin grammar
    (
      *
      (
        (*print_p)[push_back_a(depot)] >> "\r\n"
      )
      >> *("\r\n" >> (*anychar_p)[push_back_a(depot)])
    )
    // end grammar
  ).full;
}

} // namespace sv::detail
} // namespace sv

#endif // __SV_PARSER_REQUEST_PARSER_IPP__