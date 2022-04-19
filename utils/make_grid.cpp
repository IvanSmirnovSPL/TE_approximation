#include "make_grid.h"

#include "gmsh.h"
#include <vector>
#include <string>
#include <iostream>

void get_grid(std::string name, double scale, std::vector <Point>& rez)
{
  gmsh::initialize();
  gmsh::model::add(name);

  double lc = 1;
  gmsh::model::geo::addPoint(-1, -1, 0, lc, 1);
  gmsh::model::geo::addPoint(-1, 1, 0, lc, 2);
  gmsh::model::geo::addPoint(1, 1, 0, lc, 3);
  gmsh::model::geo::addPoint(1, -1, 0, lc, 4);

  gmsh::model::geo::addLine(1, 2, 1);
  gmsh::model::geo::addLine(2, 3, 2);
  gmsh::model::geo::addLine(3, 4, 3);
  gmsh::model::geo::addLine(4, 1, 4);

  gmsh::model::geo::addCurveLoop({1, 2, 3, 4}, 1);
  gmsh::model::geo::addPlaneSurface({1}, 1);
  gmsh::model::geo::synchronize();

  gmsh::option::setNumber("Mesh.MeshSizeMax", scale);

  gmsh::model::mesh::generate(2);
  gmsh::write(name + ".msh");

  std::vector <std::size_t> nodeTags; std::vector <double> coord, parametricCoord;

  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, -1, -1, false, true);

  gmsh::finalize();
   
  for (int i = 0; i < nodeTags.size(); i++)
  {
      rez.push_back(Point(coord[i * 3], coord[i * 3 + 1]));
      //std::cout<< coord[i * 3]<<" "<< coord[i * 3 + 1]<<" "<<coord[i * 3 + 2]<<std::endl;
  }

}
