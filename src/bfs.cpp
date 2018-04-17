/*
 * bfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <unistd.h>
#include "../inc/graph.hh"

std::shared_ptr< std::queue<int> > graph::bfs(int _ID_source, int _ID_end){
	std::shared_ptr< std::queue<int> > route = new std::queue<int>;

	int u;

	route->push(_ID_source);
/*
	std::queue<int> Q;
	Q.push(_ID_source);

	while(!Q.empty()){

		u = Q.front();
			for(int i=0;i<=this->stops[u]->get_number_of_connections()-1;i++){

				Q.push(this->stops[u]->get_connection_ID(i));
				std::cout<<this->stops[u]->get_connection_ID(i)<<std::endl;
				sleep(1);
			}
			}*/

	while(u != _ID_end){

	}

	return route;
}
