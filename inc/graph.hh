/*
 * graph.hh
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_GRAPH_HH_
#define INC_GRAPH_HH_

#include <list>

#include "tram_stop.hh"

class graph{
private:
	int size;
	std::list<tram_stop> stops;

public:

	void add_stop(int ID1, int ID2, std::string name);

	graph():size(0){
	}

};


#endif /* INC_GRAPH_HH_ */
