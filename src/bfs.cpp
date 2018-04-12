/*
 * bfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "../inc/graph.hh"

std::shared_ptr< std::queue<int> > graph::bfs(int _ID_begin, int _ID_end){
	std::shared_ptr< std::queue<int> > route;
	route->push(_ID_begin);

	return route;
}
