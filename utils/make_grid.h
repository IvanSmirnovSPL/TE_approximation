#pragma once

#include <vector>
#include <string>

#include "utils.h"


/*form grid with giving name of said scale and return nodes
 *also save this grid in <name>.msh
 *
 *Input:
 * - name -- name of grid
 * - scale -- scale of grid
 *Output:
 * - rez -- vector of 2D points
 * 
 * */
std::vector <Point> get_grid(std::string name, double scale);


