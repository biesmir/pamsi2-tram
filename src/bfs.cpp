/*
 * bfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <unistd.h>
#include "../inc/graph.hh"
#include "../inc/tree.hh"

std::queue<int> graph::bfs(int _ID_source, int _ID_end){
	std::queue<int>  route;
	tree search_tree;

	for(int i = 0; i < this->size-1; i++){
		this->stops[i]->colour='w';
	}
	int u = _ID_source;
	int s;
	this->stops[u]->colour='b';
	bool end=false;

	route.push(_ID_source);

	std::queue<int> Q;
	Q.push(_ID_source);

	while(!Q.empty() && !end){

		u = Q.front();
		Q.pop();
		std::cout<<"u: "<<u<<std::endl;
		for(int i=0;i<=this->stops[u]->get_number_of_connections()-1;i++){
			s=this->stops[u]->get_connection_ID(i);

			if(s==_ID_end){
					std::cout<<"znaleziono"<<std::endl;
					end=true;
					break;
			}
			if(this->stops[s]->colour =='w'){
						Q.push(s);
						this->stops[s]->colour='b';
						search_tree.add_node(u,s);
						std::cout<<s<<std::endl;
						sleep(1);
			}


			}

	}


	//while(u != _ID_end){

	//}

	return route;
}
