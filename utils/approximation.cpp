#include "approximation.h"
#include "utils.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

// to store queries results
#include <vector>

// just for output
#include <iostream>
#include <boost/foreach.hpp>

#include <algorithm>
#include <string>

#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/operation.hpp>

namespace bnu = boost::numeric::ublas;

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

void solve_SLAE(std::vector<std::vector <double>> A_,
 std::vector <double> b_, std::vector <double> *x_)
 {
    bnu::vector<double> b(b_.size());
    for (int i = 0; i< b_.size(); i++){b(i) = b_[i];}
    
    bnu::matrix<double> A(A_.size(), A_.size());
    for (int i = 0; i < A_.size(); i++)
    {
        for (int j = 0; j < A_.size(); j++)
        {
            A(i, j) = A_[i][j];
        }
    }

    bnu::matrix<double> Ainv = bnu::identity_matrix<float>(A.size1());
    bnu::permutation_matrix<size_t> pm(A.size1());
    bnu::lu_factorize(A,pm);
    bnu::lu_substitute(A, pm, Ainv); 
    bnu::vector<double> x = prod(Ainv, b);
    for (auto a: x)
    {
        x_->push_back(a);
    }
 }


void make_value(std::vector <Point> K_nearest,
 std::vector <double> Values_k_nearest, Point Target, double *value)
{

}


void test()
{
    

    std::vector <double>b{1, -1}, tmp1{1, 0}, tmp2{0, -1};
    std::vector <std::vector <double>> A;
    A.push_back(tmp1);
    A.push_back(tmp2);

    std::vector <double> x;
    solve_SLAE(A, b, &x);
    std::cout << x[0] <<" "<<x[1]<<std::endl;


    /*auto combinations = comb(5, 3);
    for (auto a : combinations)
    {
        for (int i = 0; i < a.size(); i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }*/
}
