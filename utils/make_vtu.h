#pragma once

#include <string>
#include <vector>
#include <map>
#include <filesystem>

#include "utils.h"

void save_vtu(std::filesystem::path filename, const std::vector<Point>& Points,
  const std::map <std::string, double>& values);
