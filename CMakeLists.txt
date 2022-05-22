cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS "-std=c++20")
project(TE VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)

add_subdirectory(utils)
target_link_libraries(main lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
