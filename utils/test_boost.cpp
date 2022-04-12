#include "test_boost.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

// to store queries results
#include <vector>

// just for output
#include <iostream>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

typedef bg::model::point<float, 2, bg::cs::cartesian> point;

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




void test_boost()
{
    bnu::vector<double> b(2);
    b(0) = 1.;  b(1) = (-1);
    bnu::matrix<double> A(2, 2);
    A(0, 0) = 1.;
    A(0, 1) =0;
    A(1, 0) = 0;
    A(1, 1) = -1;
    std::cout << b << std::endl;
    std::cout << A << std::endl;
    /*bnu::permutation_matrix<double> b;
    bnu::lu_factorize(A, b);
    bnu::lu_substitute(A, b, x);
    std::cout << x << std::endl;*/
    /*auto Ainv = bnu::identity_matrix<float>(A.size1());
    bnu::permutation_matrix<size_t> pm(A.size1());
    bnu::lu_factorize(A, pm);
    bnu::lu_substitute(A, pm, Ainv);
    bnu::inplace_solve(A, b, bnu::unit_lower_tag());
    bnu::inplace_solve(A, b, bnu::upper_tag());
    auto x = prod(Ainv, b);
    std::cout << x << std::endl;*/
    

    auto combinations = comb(5, 3);
    for (auto a : combinations)
    {
        for (int i = 0; i < a.size(); i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    bgi::rtree <point, bgi::quadratic<4>> rt;
    std::vector <point> points, result;
    points.push_back(point(1., 1.)); points.push_back(point(2., 2.));
    rt.insert(points.begin(), points.end());
    rt.query(bgi::nearest(point(0., 0.), 1), std::back_inserter(result));

    std::cout << "knn query point:" << std::endl;
    std::cout << bg::wkt<point>(point(0., 0.)) << std::endl;
    std::cout << "knn query result:" << std::endl;
    BOOST_FOREACH(point const& v, result)
        std::cout << bg::wkt<point>(v) << std::endl;

}
