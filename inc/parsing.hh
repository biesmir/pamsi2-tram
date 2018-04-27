/*
 * parsing.hh
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_PARSING_HH_
#define INC_PARSING_HH_

#include "graph.hh"

#include <iostream>
#include <fstream>
//#include <string>
#include <cstdlib>

int parsing(graph & Graph, std::string file_name);

int parsall(graph & Graph);

#endif /* INC_PARSING_HH_ */
