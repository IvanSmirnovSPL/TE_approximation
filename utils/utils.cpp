#include "utils.h"

Point point2Point(point p)
{
    Point P;
    P.x = bg::get<0>(p);
    P.y = bg::get<1>(p);
    return P;
}

point Point2point(Point P)
{
    point p;
    bg::set<0>(p, P.x);
    bg::set<1>(p, P.y);
    return p;
}

std::string point2string(point p)
{
    return std::to_string(bg::get<0>(p)) + " " + std::to_string(bg::get<1>(p));
}

std::string Point2string(Point P)
{
    return std::to_string(P.x) + " " + std::to_string(P.y);
}

void calculate_tau(double Time, int N, double *tau)
{
    if (N > 1)
    {
        *tau = Time / (N - 1);
    }
    else
    {
         *tau = 0.;
    }
}