project(MegaLibrary)

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

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
	IMPORTED_LOCATION "/home/ivan/gmsh-git-Linux64-sdk/lib/libgmsh.so"
	INTERFACE_INCLUDE_DIRECTORIES "/home/ivan/gmsh-git-Linux64-sdk/include"
)
set(GMSH_LIBRARY gmsh)

find_package (Boost REQUIRED COMPONENTS system filesystem)

if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})
endif ()

set(SOURCES utils.cpp make_grid.cpp initial_conditions.cpp calculate.cpp approximation.cpp make_vtu.cpp)
set(HEADERS utils.h make_grid.h initial_conditions.h calculate.h approximation.h make_vtu.h)

add_library(lib ${SOURCES} ${HEADERS})
target_link_libraries(lib ${VTK_LIBRARIES} ${GMSH_LIBRARY} ${Boost_LIBRARIES} ${Eigen_LIBRARIES})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
