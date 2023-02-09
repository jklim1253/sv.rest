#ifndef __SV_COMMON_LOAD_FILELIST_HPP__
#define __SV_COMMON_LOAD_FILELIST_HPP__
#pragma once

#include <list>
#include <string>
#include <fstream>

namespace sv
{

template<class Char, class Container>
void load_filelist(const Char* filename, Container& filelist, bool reset = false)
{
  std::fstream file(filename, std::ios::in);
  if (!file.good())
  {
    throw std::runtime_error("file not found");
  }

  if (reset)
    filelist.clear();

  std::string line;
  while (std::getline(file, line))
  {
    if (line.empty()) continue;

    filelist.push_back(line);
  }
}

} // namespace sv

#endif // __SV_COMMON_LOAD_FILELIST_HPP__