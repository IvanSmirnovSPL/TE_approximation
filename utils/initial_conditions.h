#pragma once

#include <cmath>
#include <string>
#include <iostream>
#include <functional>

#include "utils.h"

double wave(Point p);
double cone(Point p);

std::function<double(Point)> get(std::string name);

Point boundary_conditions(Point P);
