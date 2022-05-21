#ifndef MAKE_VTU_H

#define MAKE_VTU_H

#include <string>
#include <vector>
#include <map>
#include <filesystem>

#include "utils.h"

void save_vtu(std::filesystem::path filename, std::vector<Point> Points,
 std::map <std::string, double> values);

#endif