#include "sv/common.hpp"
#include "sv/parser.hpp"

int main(int argc, const char **argv)
{
  try
  {
    std::list<std::string> filelist;
    sv::load_filelist("request.list", filelist);

    fmt::print("{}\n", filelist);

    sv::run_parser<sv::request_parser>();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}