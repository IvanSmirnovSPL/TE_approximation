#ifndef INITIAL_CONDITIONS_H

#define INITIAL_CONDITIONS_H

#include "utils.h"
#include <cmath>
#include <string>
#include <iostream>

double wave(Point p);
double cone(Point p);


double (*get(std::string name))(Point p);

void boundary_conditions(Point *P);

#define INITIAL_CONDITIONS_H

#endif //INITIAL_CONDITIONS_H