#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

#include <eigen3/Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;


namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
using point = bg::model::point<float, 2, bg::cs::cartesian>;

struct Point
{
    double x = 0;
	double y = 0;
	Point(double x, double y): x(x), y(y) {}
	Point(): x(0), y(0) {}
};


Point point2Point(point p);

point Point2point(Point P);

std::string Point2string(Point P);

std::string point2string(point P);

double calculate_tau(double Time, int N);

void vector2VectorXd(std::vector <double> v, VectorXd &V);
void VectorXd2vector(VectorXd V, std::vector <double> &v);
void matrix2MatrixXd(std::vector<std::vector <double>> m, MatrixXd &M);
void MatrixXd2matrix(MatrixXd &M, std::vector<std::vector <double>> &m);
