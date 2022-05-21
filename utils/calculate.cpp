#include <vector>
#include <iostream>
#include <map>
#include <filesystem>
#include <functional>

#include "utils.h"
#include "make_vtu.h"
#include "initial_conditions.h"
#include "approximation.h"
#include "calculate.h"

class KDTree
{
    public:
    bgi::rtree <point, bgi::quadratic<4>> rt;

    KDTree(std::vector <Point> grid)
    {
        std::vector <point> points;
        for (auto P: grid){points.push_back(Point2point(P));}
        rt.insert(points.begin(), points.end());
    }

    void find_k_nearest(Point Target, int K, std::vector <Point> *Rez)
    {
        point target = Point2point(Target); std::vector <point> k_nearest;
        rt.query(bgi::nearest(target, K), std::back_inserter(k_nearest));
        for (auto p: k_nearest){Rez->push_back(point2Point(p));}
    }
};

void make_values(KDTree kdtree, std::vector <Point> grid,
 std::function<double(Point)> F_initial, double tau, double lamb_x, double lamb_y,
  std::map <std::string, double> &time_lay)
{
    
    std::map <std::string, double> time_lay_prev, time_lay_cur;
    time_lay_prev = time_lay;
    for (int j = 0; j < 2; j++)
    {
        
        for (auto P: grid)
        {
            Point Target = j == 0 ? Point(P.x - lamb_x * tau, P.y)
             : Point(P.x, P.y - lamb_y * tau);
            boundary_conditions(&Target);
            std::vector <Point> K_nearest; 
            std::vector <double> Values_k_nearest;
            int approx_num = order == 1 ? 6 : 10;
            kdtree.find_k_nearest(Target, approx_num, &K_nearest);
            for (auto P: K_nearest){Values_k_nearest.push_back(time_lay_prev[Point2string(P)]);}
            double value;
            //value = time_lay->at(Point2string(P));
            make_value(K_nearest, Values_k_nearest, Target, value);
            time_lay_cur[Point2string(P)] = value;
        }
        time_lay_prev = time_lay_cur;
    }
    time_lay = time_lay_cur;
}

void calculate_grid(std::function<double(Point)> F_initial, std::vector <Point> grid,
 double lamb_x, double lamb_y, double Time, int N, std::filesystem::path name)
 {
    KDTree kdtree(grid); /*make k-distance tree*/

    double tau;
    calculate_tau(Time, N, &tau);

    std::map <std::string, double> time_lay;
    for (int n = 0; n < N; n++)
    {
        if (n == 0)
        {
            for(auto P: grid){time_lay[Point2string(P)] = F_initial(P);}
        }
        make_values(kdtree, grid, F_initial, tau, lamb_x, lamb_y, time_lay);
        std::string vtk_filename = "state_" + std::to_string(n) + ".vtk";
        std::filesystem::path vtk_file_path = name / vtk_filename;
        save_vtu(vtk_file_path, grid, time_lay);
    }
    
 }