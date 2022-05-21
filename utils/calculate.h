#pragma once

#include <vector>
#include <filesystem>
#include <functional>

#include "utils.h"

void calculate_grid(std::function<double(Point)> F, const std::vector <Point>& grid,
 double lamb_x, double lamb_y, double Time, int N, int order, std::filesystem::path name);
 