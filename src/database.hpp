#ifndef __SV_DATABASE_HPP__
#define __SV_DATABASE_HPP__

namespace sv
{

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
  ~basic_database()
  {

  }

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

} // namespace sv

#endif // __SV_DATABASE_HPP__