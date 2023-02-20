#include <cstdint>
#include <string>
#include <list>

namespace sv
{

using id_type = std::uint64_t;

struct user_table
{
  using key_type = id_type;
  using record_type = user_table;

  id_type id;
  std::string name;
  std::string group;
};

using user_t = user_table;

void test_interface()
{


}

} // namespace sv