#include "sv/common.hpp"
#include "sv/parser.hpp"

#include <fstream>

int main(int argc, const char **argv)
{
  try
  {
    sv::run_parser<sv::number_parser>(sv::from_console());

    sv::run_parser<sv::request_parser>(sv::from_filelist("request.list"));
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}