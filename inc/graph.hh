/*
 * graph.hh
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_GRAPH_HH_
#define INC_GRAPH_HH_

#include <vector>
#include <queue>
#include <memory>
#include <iostream>
#include <cstdlib>

#include "tram_stop.hh"

class graph{
private:
	int size;
	std::vector< std::shared_ptr<tram_stop> > stops;

public:

	bool add_stop(std::string name);
	void add_stop(tram_stop tram);

	bool add_connection(int ID1, int ID2, unsigned short int time, int line);

	bool add_connection(std::string _stop1, std::string _stop2, unsigned short int time, int line);

	void make_random_graph(int _size);

	void all_stops(std::ostream&);

	graph():size(0){
	}

	std::queue<int> bfs(int _ID_begin, int _ID_end);

	std::queue< int >dfs(int source, int end);

};


#endif /* INC_GRAPH_HH_ */
