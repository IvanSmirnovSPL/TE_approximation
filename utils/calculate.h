#ifndef CALCULATE_H

#define ICALCULATE_H
#include "utils.h"
#include <vector>
void calculate_grid(double(*F)(Point), std::vector <Point> grid,
 double lamb_x, double lamb_y, double Time, int N, std::string name);
#endif //CALCULATE_H