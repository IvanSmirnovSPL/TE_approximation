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

double calculate_tau(double Time, int N)
{
    if (N > 1)
        return Time / (N - 1);
    else
         return 0.;
}


void vector2VectorXd(std::vector <double> v, VectorXd &V)
{
    V.resize(v.size());
    for (int i = 0; i < v.size(); ++i)
    {
        V(i) = v[i];
    }
}

void VectorXd2vector(VectorXd V, std::vector <double> &v)
{
    v.resize(V.size());
    for (int i = 0; i < V.size(); ++i)
    {
        v[i] = V(i);
    }
}


void matrix2MatrixXd(std::vector<std::vector <double>> m, MatrixXd &M)
{
    M.resize(m.size(), m.size());
    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m.size(); ++j)
        {
            M(i, j) = m[i][j];
        }
    }
}

void MatrixXd2matrix(MatrixXd &M, std::vector<std::vector <double>> &m)
{
    m.resize(M.rows()); auto cols = M.cols();
    for (int i = 0; i < M.rows(); ++i)
    {
        m[i].resize(cols);
        for (int j = 0; j < M.cols(); ++j)
        {
            m[i][j] = M(i, j);
        }
    }
}