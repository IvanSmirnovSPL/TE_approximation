#include "initial_conditions.h"

double wave (Point p)
    {
        double rez = 0;
        if (sqrt(pow(p.x, 2) + pow(p.y, 2)) < 1)
        {
            rez =  pow(cos(sqrt(pow(p.x, 2) + pow(p.y, 2)) * 0.5 * M_PI), 2);
        }
        return rez;
    }

double cone (Point p)
    {
        double rez = 0;
        if (sqrt(pow(p.x, 2) + pow(p.y, 2)) < 1)
        {
            rez =  pow(cos(sqrt(pow(p.x, 2) + pow(p.y, 2)) * 0.5 * M_PI), 2);
        }
        return rez;
    }

double (*get(std::string name))(Point p)
{
    if (name == "wave")
    {
        return &wave;
    }
}

int sign(double x)
{
    return x >= 0 ? 1 : -1;
}

void boundary_conditions(Point *P)
{
    double T = 2;
    P->x = P->x - sign(P->x) * int((fabs(P->x) / T)) * T;
    if (fabs(P->x) > 1)
    {
        P->x -= sign(P->x) * T;
    }

    P->y = P->y - sign(P->y) * int((fabs(P->y) / T)) * T;
    if (fabs(P->y) > 1)
    {
        P->y -= sign(P->y) * T;
    }

}