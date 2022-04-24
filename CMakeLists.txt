cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS "-std=c++17")
project(TE VERSION 0.1.0)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonDataModel
  vtkFiltersGeneral
  vtkIOXML
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

if (NOT VTK_FOUND)
  message("Skipping WriteVTU: ${VTK_NOT_FOUND_MESSAGE}")
  return()
else()
   include_directories (SYSTEM ${VTK_INCLUDE_DIR}) 
   message (STATUS "VTK_VERSION: ${VTK_VERSION}")
endif()


find_package (Boost REQUIRED COMPONENTS system filesystem)

if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})
    #message(STATUS "Boost_INCLUDE_DIRS = " ${Boost_INCLUDE_DIR})
endif ()

include(CTest)
enable_testing()

add_executable(main main.cpp ./utils/make_vtu.cpp)

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
	IMPORTED_LOCATION "/home/ivan/gmsh-git-Linux64-sdk/lib/libgmsh.so"
	INTERFACE_INCLUDE_DIRECTORIES "/home/ivan/gmsh-git-Linux64-sdk/include"
)
set(GMSH_LIBRARY gmsh)


add_subdirectory(utils)
target_link_libraries(main lib ${GMSH_LIBRARY} ${VTK_LIBRARIES} ${Boost_LIBRARIES} ${Eigen_LIBRARIES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
