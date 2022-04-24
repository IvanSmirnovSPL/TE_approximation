#include "./utils/make_grid.h"
#include "./utils/utils.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "./utils/initial_conditions.h"
#include <cstdlib>
#include<fstream>
#include "./utils/calculate.h"

#include <iostream>


std::vector<std::string> figures{"wave", "cone", "cube", "fig_1", "fig_2", "fig_3", "fig_4"};
int grids_num = 4;
std::vector <double> grid_scales{0.2, 0.1, 0.05, 0.025, 0.0125, 0.00625};
double lamb_x = 0, lamb_y = 5; double Time = 1; int N = 11;


int main(int argc, char **argv)
{
    std::system("rm -r ../rez && mkdir ../rez"); /*make rez directory*/
    std::system("mkdir ../rez/meshes");          /*make meshes directory*/

    std::vector<std::vector<Point>> grid_dots(grids_num); /*make grids*/
    for (int i = 0; i < grids_num; i++)
    {
        get_grid("../rez/meshes/grid" + std::to_string(i + 1), grid_scales[i], grid_dots[i]);
    }

    for (int figure = 0; figure < 1 /*figures.size()*/; figure++)
    {
        double (*F_initial)(Point) = NULL;
        F_initial = get(figures[figure]); /*get F(x, y) function*/
        std::string figure_dir = "mkdir ../rez/" + figures[figure];
        std::system(figure_dir.c_str());/*make directory for figure*/
        for (int i = 3; i < 4; i++)
        {
            std::string grid_dir = "mkdir ../rez/" + figures[figure] + "/grid" + std::to_string(i + 1);
            std::system(grid_dir.c_str());/*make directory for grid*/
            std::string path = "../rez/" + figures[figure] + "/grid" + std::to_string(i + 1) + "/";
            calculate_grid(get(figures[figure]), grid_dots[i], lamb_x, lamb_y, Time, N, path);
        }
    }


    return 0;
}

