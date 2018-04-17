/*
 * bfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <unistd.h>
#include "../inc/graph.hh"

std::shared_ptr< std::queue<int> > graph::bfs(int _ID_source, int _ID_end){
	std::shared_ptr< std::queue<int> > route;
	int u;
	std::cout<<"ok"<<std::endl;
	//route->push(_ID_source);
	std::cout<<"ok"<<std::endl;
	std::queue<int> Q;
	std::cout<<"ok"<<std::endl;
	Q.push(_ID_source);
std::cout<<"ok"<<std::endl;
	while(!Q.empty()){
			u = Q.front();
			for(int i=0;i<=this->stops[u]->get_number_of_connections()-1;i++){

				Q.push(this->stops[u]->get_connection_ID(i));
				std::cout<<this->stops[u]->get_connection_ID(i)<<std::endl;
				sleep(1);
			}
			}

	return route;
}
