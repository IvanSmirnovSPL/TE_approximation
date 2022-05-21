#pragma once

#include "utils.h"
#include <vector>

void make_value(const std::vector <Point>& K_nearest, const std::vector <double>&  Values_k_nearest, 
Point Target, double &value, int order);
