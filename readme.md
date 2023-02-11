# sv.rest

## About

C++ library for REST API.

- [ ] easy to manage uri.
- [ ] easy to maintain method handler.

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
