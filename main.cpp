#include "./utils/make_grid.h"
#include "./utils/utils.h"
#include <vector>
#include <iostream>
#include "./utils/test_boost.h"
#include "test_vtu.h"




int main(int argc, char **argv)
{
    std::vector <Point> nodes;
    get_grid("grid_1", 1, nodes);

    for (auto a: nodes)
    {
        std::cout<<a.x<<" "<<a.y<<std::endl;
    }

    test_boost();

    test_vtu();




    return 0;
}
