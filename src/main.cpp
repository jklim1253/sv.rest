#include "sv/common.hpp"
#include "sv/parser.hpp"

namespace test
{

void test_parser();
void test_network();

} // namespace test

namespace sv
{

void test_interface();

} // namespace sv

int main(int argc, const char **argv)
{
  try
  {
    // test::test_parser();
    test::test_network();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}