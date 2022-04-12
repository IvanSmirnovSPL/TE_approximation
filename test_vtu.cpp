#include "test_vtu.h"

#include "vtkActor.h"
#include <vtkCellArray.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTetra.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkXMLUnstructuredGridWriter.h>

#include <iostream>
#include <cmath>
#include <vector>

#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkStructuredGrid.h>
#include <vtkSmartPointer.h>

class Point_
{
public:
  double x, y, z;
  Point_() : x(0.0), y(0.0), z(0.0)
  {
  }

  Point_(double x, double y, double z) : x(x), y(y), z(z)
  {
  }
};

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
