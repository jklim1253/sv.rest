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
  using result_type = typename subject_type::result_type;

  template<class Char, class Depot>
  bool operator()(const Char* format, Depot& depot);

  template<class Char, class Depot>
  bool operator()(std::basic_string<Char> const& format, Depot& depot)
  {
    return (*this)(format.c_str(), depot);
  }

private:
  subject_type subject;
};

template<class Subject, class InputFeeder, class...Args>
void run_parser(InputFeeder&& feeder, Args&&...args);

} // namespace sv

#include "sv/parser/parser.ipp"

#endif // __SV_PARSER_PARSER_HPP__