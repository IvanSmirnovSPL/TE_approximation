project(MegaLibrary)


set(SOURCES make_grid.cpp test_boost.cpp)
set(HEADERS utils.h make_grid.h test_boost.h )
add_library(lib ${SOURCES} ${HEADERS})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
