#ifndef __SV_PARSER_PARSER_IPP__
#define __SV_PARSER_PARSER_IPP__
#pragma once

#include <string>
#include <iostream>

#include "sv/common.hpp"
#include "sv/parser/parser.hpp"

namespace sv
{

template<class Subject>
template<class Char, class Depot>
bool basic_parser<Subject>::operator()(const Char* format, Depot& depot)
{
  return subject(format, depot);
}

template<class Subject, class InputFeeder, class...Args>
void run_parser(InputFeeder&& feeder, Args&&...args)
{
  basic_parser<Subject> parser;

  std::string input;
  while (feeder(input))
  {
    fmt::print(fmt::fg(fmt::color::green), "{}", input);

    if (input.empty()) continue;
    if (input == "quit") break;
    
    // std::list<double> result;
    typename Subject::result_type result;
    if (!parser(input, result))
    {
      fmt::print(fmt::fg(fmt::color::red), "\ninput format error\n");
      continue;
    }

    fmt::print(fmt::fg(fmt::color::yellow), "\nmatched!\n");
    fmt::print(fmt::fg(fmt::color::white), "{}\n", fmt::join(result, "\n"));
  }
}

} // namespace sv

#endif // __SV_PARSER_PARSER_IPP__