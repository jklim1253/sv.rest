#ifndef __SV_COMMON_HPP__
#define __SV_COMMON_HPP__
#pragma once

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif // FMT_HEADER_ONLY
#include <fmt/format.h>
#include <fmt/ranges.h>

namespace sv
{

template<class Format, class...Args>
void println(Format&& format, Args&&...args)
{
  auto new_format = fmt::format("{}\n", std::forward<Format>(format));
  fmt::print(fmt::runtime(new_format), std::forward<Args>(args)...);
}

}

#endif // __SV_COMMON_HPP__