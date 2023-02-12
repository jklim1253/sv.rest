#include "sv/common.hpp"
#include "sv/parser.hpp"

namespace test
{

void test_parser()
{
  sv::run_parser<sv::number_parser>(sv::from_console());
  sv::run_parser<sv::request_parser>(sv::from_filelist("request.list"));
}

} // namespace test