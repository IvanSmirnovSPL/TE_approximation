#ifndef UTILS_H

#define UTILS_H

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include <eigen3/Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;

namespace bnu = boost::numeric::ublas;

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
typedef bg::model::point<float, 2, bg::cs::cartesian> point;

class Point
{
    public:
    
    double x, y;
    Point (): x(0.0), y(0.0)
	{
	}

	Point(double x, double y ): x(x), y(y)
	{
	}

};

Point point2Point(point p);

point Point2point(Point P);

std::string Point2string(Point P);

std::string point2string(point P);

void calculate_tau(double Time, int N, double *tau);

void vector2VectorXd(std::vector <double> v, VectorXd &V);
void VectorXd2vector(VectorXd V, std::vector <double> &v);
void matrix2MatrixXd(std::vector<std::vector <double>> m, MatrixXd &M);
void MatrixXd2matrix(MatrixXd &M, std::vector<std::vector <double>> &m);
 


#endif //UTILS_H
