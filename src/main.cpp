#include <iostream>
#include <vector>
#include <list>
#include <string>

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif // FMT_HEADER_ONLY
#include <fmt/format.h>

#include <boost/spirit/include/classic.hpp>

template<class Container>
bool
parse_numbers(const char* str, Container& depot)
{
  using namespace boost::spirit::classic;

  return parse(
    str,
    (
      int_p[push_back_a(depot)]
      >> *(',' >> int_p[push_back_a(depot)])
    ),
    space_p
  ).full;
}

template<class Format, class...Args>
void println(Format&& format, Args&&...args)
{
  auto new_format = fmt::format("{}\n", std::forward<Format>(format));
  fmt::print(fmt::runtime(new_format), std::forward<Args>(args)...);
}

int main(int argc, const char** argv)
{
  std::string line;
  while ((std::cout << "ps:>") && std::getline(std::cin, line))
  {
    if (line.empty()) continue;
    if (line == "quit") break;

    std::list<int> result;
    if (!parse_numbers(line.c_str(), result))
    {
      println("error");
      continue;
    }

    println("matched!");
    for (auto const& e : result)
      fmt::print("{} ", e);
    fmt::print("\n");
  }

  return 0;
}