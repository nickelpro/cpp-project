cmake_minimum_required(VERSION 3.22)
set(CMAKE_TOOLCHAIN_FILE
  ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file"
)

project(strugatsky CXX)

find_path(ztd_include ztd REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(strugatsky)
target_compile_features(strugatsky PRIVATE cxx_std_20)
target_compile_options(strugatsky PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_include_directories(strugatsky PRIVATE ${ztd_include})
target_link_libraries(strugatsky PRIVATE fmt::fmt)

add_subdirectory(src)
