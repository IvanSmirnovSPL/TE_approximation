#include <functional>

#include "initial_conditions.h"


double wave (Point p)
    {
        double rez = 0;
        if (sqrt(pow(p.x, 2) + pow(p.y, 2)) < 1)
        {
            rez =  pow(cos(sqrt(pow(p.x, 2) + pow(p.y, 2)) *  std::numbers::pi / 2), 2);
        }
        return rez;
    }

double cone (Point p)
    {
        double rez = 0;
        if (sqrt(pow(p.x, 2) + pow(p.y, 2)) < 1)
        {
            rez =  pow(cos(sqrt(pow(p.x, 2) + pow(p.y, 2)) *  std::numbers::pi / 2), 2);
        }
        return rez;
    }



std::function<double(Point)> get(std::string name)
{
    if (name == "wave")
    {
        return wave;
    }

    return wave;

}

int sign(double x)
{
    return x >= 0 ? 1 : -1;
}


Point boundary_conditions(Point P)
{
    double T = 2;
    P.x = P.x - sign(P.x) * int((std::abs(P.x) / T)) * T;
    if (std::abs(P.x) > 1)
    {
        P.x -= sign(P.x) * T;
    }

    P.y = P.y - sign(P.y) * int((std::abs(P.y) / T)) * T;
    if (std::abs(P.y) > 1)
    {
        P.y -= sign(P.y) * T;
    }
    
    return P;
}
