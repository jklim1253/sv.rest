# sv.rest

---

- [sv.rest](#svrest)
  - [About](#about)
  - [Design](#design)
  - [Directories](#directories)
  - [Build](#build)
  - [Dependencies](#dependencies)

---

## About

~~C++ header only library for REST API~~(**UNDER CONSTRUCTION**).

## Design

- [ ] easy to manage uri.
- [ ] easy to maintain method handler.
- challenge interface

  ```cpp
  using namespace sv;

  using restapi_t = basic_server<simple_restapi>;
  using db_t = basic_database<postgresql_adapter>;
  
  ...
  
  auto api = restapi_t::make();
  auto db = db_t::make(from_conf("db.conf"));

  *api
    << GET<user_table>("/sv/user",
          []()
          -> response::ptr
          {
            auto users = db->select_all<user_table>();
            return {status::ok, users};
          })
    << GET<user_table>("/sv/user/{id}",
          [](typename user_table::key_type id)
          -> response::ptr
          {
            auto user = db->select<user_table>(id);
            return {status::ok, user};
          })
    << POST<user_table>("/sv/user", 
          [](typename user_table::record_type user)
          -> response::ptr
          {
            if (auto created = db->insert<user_table>(user))
            {
              return {status::created, created};
            }

            return {status::failed};
          })
    << PUT<user_table>("/sv/user/{id}",
          [](typename user_table::key_type id, typename user_table::record_type user)
          -> response::ptr
          {
            if (auto result = db->update<user_table>(id, user))
            {
              return {status::updated, result};
            }

            return {status::failed};
          })
    << DELETE<user_table>("/sv/user/{id}",
          [](typename user_table::key_type id)
          -> response::ptr
          {
            if (auto result = db->remove<user_table>(id))
            {
              return {status::deleted};
            }

            return {status::failed};
          });

  api->start(8888);
  ```

## Directories

- src
  - main.cpp
- include
  - sv.rest sources
- data
  - input sample data

## Build

- vcpkg

  ```bash
  vcpkg install fmt:x64-windows
  vcpkg install boost:x64-windows
  ```

- environment(require administrative permission)

  ```bash
  setx VCPKG_ROOT="D:\usr\vcpkg"
  ```

## Dependencies

- C++17
- fmtlib
- boost::spirit
