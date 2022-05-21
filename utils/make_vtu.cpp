#include <iostream>
#include <cmath>
#include <vector>
#include <filesystem>

#include <vtkCellArray.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>

#include "utils.h"
#include "make_vtu.h"


void save_vtu(std::filesystem::path filename, const std::vector<Point>& Points,
 const std::map <std::string, double>& values)
{
  
  vtkSmartPointer<vtkUnstructuredGrid> UnstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  vtkSmartPointer<vtkPoints> dumpPoints = vtkSmartPointer<vtkPoints>::New();
  vtkNew<vtkCellArray> cellArray;

  //auto vertexes = vtkSmartPointer<vtkCellArray>::New();


  /*auto smth = vtkSmartPointer<vtkDoubleArray>::New();
  smth->SetName("smth");*/

  // Векторное поле на точках сетки
  /*auto vel = vtkSmartPointer<vtkDoubleArray>::New();
  vel->SetName("velocity");
  vel->SetNumberOfComponents(3);*/

  for(unsigned int i = 0; i < Points.size(); ++i) {
    // Вставляем новую точку в сетку VTK-снапшота
    dumpPoints->InsertNextPoint(Points[i].x, Points[i].y, values.at(Point2string(Points[i])));

    vtkIdType pid[1];
    pid[0] = i;
    cellArray->InsertNextCell(1, pid);

    // Добавляем значение векторного поля в этой точке
    /*double _vel[3] = {0 * i, 10 * i, 5 * i};
    vel->InsertNextTuple(_vel);*/

    // И значение скалярного поля тоже
    //smth->InsertNextValue(i);
   }


  UnstructuredGrid->SetPoints(dumpPoints);
  UnstructuredGrid->SetCells(VTK_VERTEX, cellArray);
  
  // Присоединяем векторное и скалярное поля к точкам
  //UnstructuredGrid->GetPointData()->AddArray(vel);
  //UnstructuredGrid->GetPointData()->AddArray(smth);

  // Создаём снапшот в файле с заданным именем
  vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
  writer->SetFileName(filename.c_str());
  writer->SetInputData(UnstructuredGrid);
  writer->Write();
}

/*
void test_vtu()
{

  std::vector <Point_> points;
  for (int i = 0; i < 9; i++)
  {
      int k = i / 3; int l = i % 3;
      points.push_back(Point_(k, l, 0));
  }


  std::string filename = "../test.vtu";

  vtkSmartPointer<vtkUnstructuredGrid> UnstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  vtkSmartPointer<vtkPoints> dumpPoints = vtkSmartPointer<vtkPoints>::New();
  vtkNew<vtkCellArray> cellArray;
  auto vertexes = vtkSmartPointer<vtkCellArray>::New();


  auto smth = vtkSmartPointer<vtkDoubleArray>::New();
  smth->SetName("smth");

  // Векторное поле на точках сетки
  auto vel = vtkSmartPointer<vtkDoubleArray>::New();
  vel->SetName("velocity");
  vel->SetNumberOfComponents(3);

  unsigned int number = (unsigned int)points.size();
  for(unsigned int i = 0; i < number; i++) {
      // Вставляем новую точку в сетку VTK-снапшота
      dumpPoints->InsertNextPoint(points[i].x, points[i].y, points[i].z);
      vtkIdType pid[1];
      pid[0] = i;
      cellArray->InsertNextCell(1, pid);
      //vertexes->InsertNextCell(1, pid);
      std::cout<<points[i].x<< " "<< points[i].y<< " "<< points[i].z<<std::endl; 
      // Добавляем значение векторного поля в этой точке
      double _vel[3] = {0 * i, 10 * i, 5 * i};
      vel->InsertNextTuple(_vel);

      // И значение скалярного поля тоже
      smth->InsertNextValue(i);
   }

  UnstructuredGrid->SetPoints(dumpPoints);


  UnstructuredGrid->SetCells(VTK_VERTEX, cellArray);
  //UnstructuredGrid->SetVerts(vertexes);

  // Присоединяем векторное и скалярное поля к точкам
  UnstructuredGrid->GetPointData()->AddArray(vel);
  UnstructuredGrid->GetPointData()->AddArray(smth);



        // Создаём снапшот в файле с заданным именем
        //string fileName = "cubic2d-step-" + std::to_string(snap_number) + ".vts";
        vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
        writer->SetFileName(filename.c_str());
        writer->SetInputData(UnstructuredGrid);
        writer->Write();



    	
}
*/