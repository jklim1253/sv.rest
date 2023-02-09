#ifndef __SV_PARSER_PARSER_HPP__
#define __SV_PARSER_PARSER_HPP__
#pragma once

#include <string>

namespace sv
{

template<class Subject>
struct basic_parser
{
  using subject_type = Subject;

  template<class Char, class Depot>
  bool operator()(const Char* format, Depot& depot) const;

  template<class Char, class Depot>
  bool operator()(std::basic_string<Char> const& format, Depot& depot) const
  {
    return (*this)(format.c_str(), depot);
  }

private:
  subject_type subject;
};

template<class Expression>
bool string_feeder(Expression expr, std::string& data)
{
  return expr(data);
}

template<class Subject, class Expression, class...Args>
void run_parser(Expression expr, Args&&...args);

} // namespace sv

#include "sv/parser/parser.ipp"

#endif // __SV_PARSER_PARSER_HPP__