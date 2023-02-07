cmake_minimum_required(VERSION 3.1)

file(GLOB SOURCE_FILES *.cpp)
file(GLOB HEADER_FILES *.hpp)

add_executable(${CMAKE_PROJECT_NAME}
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

target_link_libraries(${CMAKE_PROJECT_NAME}
  PRIVATE
  fmt::fmt
)