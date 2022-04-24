project(MegaLibrary)

set(SOURCES utils.cpp make_grid.cpp initial_conditions.cpp calculate.cpp approximation.cpp)
set(HEADERS utils.h make_grid.h initial_conditions.h calculate.h approximation.h)
add_library(lib ${SOURCES} ${HEADERS})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
