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

template<class Adapter>
struct basic_database
{
  using self = basic_database<Adapter>;
  using ptr = std::shared_ptr<self>;

  template<class...Args>
  static ptr make(Args&&...args)
  {
    return ptr(new self(std::forward<Args>(args)...));
  }

private:
  basic_database(std::string const& conn)
    : adapter_(conn)
  {
  }

public:
  ~basic_database() {}

  template<class Table>
  typename std::list<Table::record_type>
  select_all()
  {
    return adapter_.select_all();
  } 

  template<class Table>
  typename Table::record_type
  select(typename Table::key_type const& key)
  {
    return adapter_.select(key);
  }

  template<class Table>
  typename Table::record_type
  insert(typename Table::record_type const& record)
  {
    return adapter_.insert(record);
  }

  template<class Table>
  typename Table::record_type
  update(
    typename Table::key_type const& key,
    typename Table::record_tyep const& record)
  {
    return adapter_.update(key, record);
  }
    
  template<class Table>
  typename Table::record_type
  remove(typename Table::key_type const& key)
  {
    return adapter_.remove(key);
  }
    
private:
  Adapter adapter_;
};

void test_interface()
{



}

} // namespace sv