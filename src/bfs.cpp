/*
 * bfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <unistd.h>
#include "../inc/graph.hh"
#include <stack>


std::stack<int> graph::bfs(int _ID_source, int _ID_end){
	std::shared_ptr<tram_stop> tmp;
	std::stack<int> route;

	std::cout<<"Z: "<<this->stops[_ID_source]->get_name()<<std::endl;
	std::cout<<"do "<<this->stops[_ID_end]->get_name()<<std::endl;

	if(_ID_source == _ID_end){
		std::cerr<<"Przystanek poczatkowy musi byc rozny od koncowego";
	return route;
	}


	int u = _ID_source;
	int s;
	this->stops[u]->colour='b';
	bool end=false;


	std::queue<int> Q;
	Q.push(_ID_source);

	while(!Q.empty() && !end){

		u = Q.front();
		Q.pop();

		for(int i=0;i<this->stops[u]->get_number_of_connections();i++){
			s=this->stops[u]->get_connection_ID(i);

			if(s==_ID_end){

					this->stops[s]->parent = this->stops[u];

					end=true;

					break;
			}
			if(this->stops[s]->colour =='w'){
						Q.push(s);

						this->stops[s]->colour = 'b';



						this->stops[s]->parent = this->stops[u];

						this->stops[s]->conn_from_parent= i;


			}


			}

	}

tmp = this->stops[s];

route.push(tmp->get_ID());

while( tmp->parent != NULL){
		tmp = tmp -> parent;
		route.push(tmp->get_ID());
	}



	return route;
}
