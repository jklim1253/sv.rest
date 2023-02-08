#ifndef __SV_PARSER_IPP__
#define __SV_PARSER_IPP__
#pragma once

#include <string>
#include <iostream>

#include "sv/common.hpp"

namespace sv
{

template<class Subject>
template<class Char, class Depot>
bool basic_parser<Subject>::operator()(const Char* format, Depot& depot) const
{
  return subject(format, depot);
}

template<class Subject>
void run_parser()
{
  std::string input;
  while ((std::cout << "input:>") && std::getline(std::cin, input))
  {
    if (input.empty()) continue;
    if (input == "quit") break;
    
    std::list<double> result;
    if (!basic_parser<Subject>()(input, result))
    {
      println("input format error");
      continue;
    }

    println("matched!\n{}", result);
  }
}

} // namespace sv

#endif // __SV_PARSER_IPP__