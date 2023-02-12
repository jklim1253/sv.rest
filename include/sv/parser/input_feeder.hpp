#ifndef __SV_PARSER_INPUT_FEEDER_HPP__
#define __SV_PARSER_INPUT_FEEDER_HPP__
#pragma once

#include <string>
#include <fstream>

namespace sv
{

struct from_filelist
{
  template<class Path>
  from_filelist(Path& path);

  inline bool operator()(std::string& input);

private:
  std::fstream filelist_;
};

struct from_console
{
  inline bool operator()(std::string& input);
};

} // namespace sv

#include "sv/parser/input_feeder.ipp"

#endif // __SV_PARSER_INPUT_FEEDER_HPP__