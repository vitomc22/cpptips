cmake_minimum_required(VERSION 3.26)

project(cppsv
    LANGUAGES CXX
    VERSION 0.0.1
)

add_compile_options(-Wall -Werror -Wextra -Wpedantic)
set(CMAKE_CXX_STANDARD 23)
add_executable(a.out main.cpp)

find_package(fmt)
target_link_libraries(a.out PRIVATE fmt::fmt-header-only)
