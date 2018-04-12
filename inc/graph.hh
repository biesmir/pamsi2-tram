/*
 * graph.hh
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_GRAPH_HH_
#define INC_GRAPH_HH_

<<<<<<< HEAD
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>
=======
#include <list>
>>>>>>> parent of b7e225f... started creating method for generating random graph

#include "tram_stop.hh"

class graph{
private:
	int size;
<<<<<<< HEAD
	std::vector< std::shared_ptr<tram_stop> > stops;

public:

	void add_stop(std::string name);
	bool add_connection(int ID1, int ID2, unsigned short int time, int line);

	void make_random_graph(int _size);

	void all_stops(std::ostream&);
=======
	std::list<tram_stop> stops;

public:

	void add_stop(int ID1, int ID2, std::string name);
>>>>>>> parent of b7e225f... started creating method for generating random graph

	graph():size(0){
	}

};


#endif /* INC_GRAPH_HH_ */
