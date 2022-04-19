#ifndef MAKE_VTU_H

#define MAKE_VTU_H

#include <string>
#include <vector>
#include <map>
#include "utils.h"

void save_vtu(std::string filename, std::vector<Point> Points,
 std::map <std::string, double> values);

#endif