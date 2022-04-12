#ifndef MAKE_GRID_H

#define MAKE_GRID_H

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
void get_grid(std::string name, double scale, std::vector <Point>& rez);

#endif //MAKE_GRID_H
