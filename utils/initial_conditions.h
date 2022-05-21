#ifndef INITIAL_CONDITIONS_H

#define INITIAL_CONDITIONS_H

#include <cmath>
#include <string>
#include <iostream>

#include "utils.h"

#define order 1

double wave(Point p);
double cone(Point p);

double (*get(std::string name))(Point p);

void boundary_conditions(Point *P);

#define INITIAL_CONDITIONS_H

#endif //INITIAL_CONDITIONS_H