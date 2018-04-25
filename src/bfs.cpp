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

	for(int i = 0; i < this->size-1; i++){
		this->stops[i]->colour='w';
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

		for(int i=0;i<=this->stops[u]->get_number_of_connections()-1;i++){
			s=this->stops[u]->get_connection_ID(i);

			if(s==_ID_end){
					std::cout<<"znaleziono"<<std::endl;
					this->stops[s]->parent = this->stops[u];

					end=true;

					break;
			}
			if(this->stops[s]->colour =='w'){
						Q.push(s);

						this->stops[s]->colour = 'b';

						std::cout<<s<<std::endl;

						this->stops[s]->parent = this->stops[u];




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
