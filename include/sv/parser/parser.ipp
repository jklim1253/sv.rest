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
bool basic_parser<Subject>::operator()(const Char* format, Depot& depot) const
{
  return subject(format, depot);
}

template<class Subject, class Expression, class...Args>
void run_parser(Expression expr, Args&&...args)
{
  std::string input;
  while ((std::cout << "input:>") && string_feeder<Expression>(expr, input))
  {
    if (input.empty()) continue;
    if (input == "quit") break;
    
    std::list<double> result;
    if (!basic_parser<Subject>()(input, result))
    {
      println("input format error");
      continue;
    }

    fmt::print("matched!\n{}\n", fmt::join(result, "\n"));
  }
}

} // namespace sv

#endif // __SV_PARSER_PARSER_IPP__