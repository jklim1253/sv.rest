#ifndef __SV_PARSER_INPUT_FEEDER_IPP__
#define __SV_PARSER_INPUT_FEEDER_IPP__
#pragma once

#include "sv/parser/input_feeder.hpp"

#include <string>
#include <iostream>

namespace sv
{

template<class Path>
from_filelist::from_filelist(Path& path)
  : filelist_()
{
  filelist_.open(path, std::ios::in);
  if (!filelist_.good()) throw std::runtime_error("file not found");
}

bool from_filelist::operator()(std::string& input)
{
  fmt::print(fmt::fg(fmt::color::gray), "filepath:> ");
  std::string filepath;
  if (!std::getline(filelist_, filepath))
  {
    return false;
  }
  fmt::print(fmt::fg(fmt::color::gray), "{}\n", filepath);

  std::fstream file(filepath, std::ios::in | std::ios::binary);
  if (!file.good())
  {
    input = filepath;
    return true;
  }

  file.seekg(0, std::ios::end);
  auto length = file.tellg();
  file.seekg(0, std::ios::beg);

  input.resize(length);
  file.read(&input[0], length);

  return true;
}

bool from_console::operator()(std::string& input)
{
  return (std::cout << "input:> ") && std::getline(std::cin, input);
}

} // namespace sv

#endif // __SV_PARSER_INPUT_FEEDER_IPP__