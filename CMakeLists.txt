cmake_minimum_required(VERSION 3.10)
project(gem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(gem STATIC)
target_sources(gem PRIVATE "src/gem.cc")
target_compile_options(gem PUBLIC -fno-rtti -fno-exceptions -Wall -Wextra -pedantic -Werror)

add_executable(main)
target_sources(main PRIVATE "src/main.cc")
target_link_libraries(main PRIVATE gem)

