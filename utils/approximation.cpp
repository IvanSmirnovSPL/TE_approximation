#include "approximation.h"
#include "utils.h"


// to store queries results
#include <vector>


#include <algorithm>
#include <string>




auto comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    std::vector <unsigned int> tmp;
    std::vector <std::vector <unsigned int>> result;

    // print integers and permute bitmask
    do {
        tmp.clear();
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            
            if (bitmask[i])
            {
                //std::cout << " " << i;
                tmp.push_back(i);
            }
                
        }
        //std::cout << std::endl;
        result.push_back(tmp);

    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return result;
}

void make_frame(std::vector <Point> Points, double &k_x, double &k_y, Point &Center)
{
    std::vector <double> x, y;
    for (auto P: Points){x.push_back(P.x); y.push_back(P.y);}
    std::sort(x.begin(), x.end()); std::sort(y.begin(), y.end());
    k_x = (x.back() - x.at(0)) > 0 ? (x.back() - x.at(0)) : 1e-6;
    k_y = (y.back() - y.at(0)) > 0 ? (y.back() - y.at(0)) : 1e-6;
    Center.x = x.at(0);
    Center.y = y.at(0);   
}

void solve_SLAE(std::vector<std::vector <double>> A_,
 std::vector <double> b_, std::vector <double> &x_)
 {

    VectorXd b; vector2VectorXd(b_, b);
    MatrixXd A; matrix2MatrixXd(A_, A); 
    VectorXd x = A.colPivHouseholderQr().solve(b);
    VectorXd2vector(x, x_);
 }

void make_A_b(std::vector <Point> P, std::vector <double> v,
     std::vector <std::vector <double>> &A, std::vector <double> &b)
{

    /*for (int i = 0; i < 6; i++)
    {
        std::vector <double> tmp{pow(P[i].x, 2), pow(P[i].y, 2),
             P[i].x * P[i].y, P[i].x, P[i].y, 1};
        A.push_back(tmp);
        b.push_back(v[i]);
    }*/
    for (int i = 0; i < 3; i++)
    {
        std::vector <double> tmp{P[i].x, P[i].y, 1};
        A.push_back(tmp);
        b.push_back(v[i]);
    }

}



void make_value(std::vector <Point> K_nearest,
 std::vector <double> Values_k_nearest, Point Target, double &value)
{
    std::vector <Point> ksi;
    double k_x, k_y; Point Center;
    make_frame(K_nearest, k_x, k_y, Center);
    for (auto P: K_nearest){ksi.push_back(Point((P.x - Center.x) / k_x, (P.y - Center.y) / k_y));}
    //std::vector <Point> interpol_dots(6); std::vector <double> interpol_value(6);
    std::vector <Point> interpol_dots(3); std::vector <double> interpol_value(3);
    double max_determinant = 0; std::vector <unsigned int> max_comb;
    //auto combinations = comb(K_nearest.size(), 6);
    auto combinations = comb(K_nearest.size(), 3);
    for (auto a: combinations)
    {
        //for (int i = 0; i < 6; i++) {interpol_dots[i] = ksi[a[i]];}
        for (int i = 0; i < 3; i++) {interpol_dots[i] = ksi[a[i]];}
        std::vector <double> b; std::vector <std::vector <double>> A;
        make_A_b(interpol_dots, interpol_value, A, b);
        MatrixXd engine_A; matrix2MatrixXd(A, engine_A);
        if (engine_A.determinant() > max_determinant)
        {
            max_determinant = engine_A.determinant();
            max_comb = a;

        }
        if (engine_A.determinant() >= 1e-1){break;}
    }
    for (int i = 0; i < 3/*6*/; i++) 
    {
        interpol_dots[i] = ksi[max_comb[i]]; 
        interpol_value[i] = Values_k_nearest[max_comb[i]];
    }
    std::vector <double> b; std::vector <std::vector <double>> A;
    make_A_b(interpol_dots, interpol_value, A, b);
    MatrixXd engine_A; matrix2MatrixXd(A, engine_A);
    std::vector <double> coef;
    solve_SLAE(A, b, coef);
    Point ksiTarget = Point((Target.x - Center.x) / k_x, (Target.y - Center.y) / k_y);
    /*value = coef[0] * pow(ksiTarget.x, 2) + coef[1] * pow(ksiTarget.y, 2)
            + coef[2] * ksiTarget.x * ksiTarget.y + coef[3] * ksiTarget.x + 
            coef[4] * ksiTarget.y + coef[5];*/
    value = coef[0] * ksiTarget.x + coef[1] * ksiTarget.y + coef[2];
            
    sort(interpol_value.begin(), interpol_value.end());
    if (value > interpol_value.back())
    {
        value = interpol_value.back();
    } 
    if (value < interpol_value[0])
    {
        value = interpol_value[0];
    }
}

