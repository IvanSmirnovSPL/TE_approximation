#ifndef CALCULATE_H

#define ICALCULATE_H

#include <vector>
#include <filesystem>
#include <functional>

#include "utils.h"

void calculate_grid(std::function<double(Point)> F, std::vector <Point> grid,
 double lamb_x, double lamb_y, double Time, int N, std::filesystem::path name);
 
#endif //CALCULATE_H