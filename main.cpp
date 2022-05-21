#include <vector>
#include <algorithm>
//#include <format> /*No such file or directory*/
#include <filesystem> 
#include <functional>

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "make_grid.h"
#include "calculate.h"
#include "initial_conditions.h"
#include "utils.h"

std::vector<std::string> figures{"wave", "cone", "cube", "fig_1", "fig_2", "fig_3", "fig_4"};
int grids_num = 1;
std::vector <double> grid_scales{0.2, 0.1, 0.05, 0.025, 0.0125, 0.00625};
double lamb_x = 0, lamb_y = 5; double Time = 1; int N = 11;


int main(int argc, char **argv)
{
    int order = 1; 
    if (argc > 1)
    {
        if (atoi(argv[1]) == 1 || atoi(argv[1]) == 2)
        {
             order = atoi(argv[1]);
        }
    }


    std::filesystem::path home_path = std::filesystem::current_path().parent_path();
    std::filesystem::remove_all(home_path / "rez");
    std::filesystem::create_directory(home_path / "rez"); /*make rez directory*/
    std::filesystem::create_directory(home_path / "rez" / "meshes"); /*make meshes directory*/         

    std::vector<std::vector<Point>> grid_dots(grids_num); /*make grids*/
    for (int i = 0; i < grids_num; ++i)
    {
        //get_grid(std::format("../rez/meshes/grid{}", i + 1), grid_scales[i], grid_dots[i]);
        grid_dots[i] = get_grid("../rez/meshes/grid" + std::to_string(i + 1), grid_scales[i]);
    }

    for (int figure = 0; figure < 1 /*figures.size()*/; ++figure)
    {
        std::filesystem::path rez_figure_dir = home_path / "rez" / figures[figure];
        std::filesystem::create_directory(rez_figure_dir);
        
        for (int i = 0; i < 1; ++i)
        {
            std::string grid_file = "grid" + std::to_string(i + 1);
            std::filesystem::path grid_dir = rez_figure_dir / grid_file;
            std::filesystem::create_directory(grid_dir); /*make directory for grid*/
            calculate_grid(get(figures[figure]), grid_dots[i], lamb_x, lamb_y, Time, N, order, grid_dir);
        }
    }


    return 0;
}

