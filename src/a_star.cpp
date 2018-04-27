/*
 * a_star.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"
#include <stack>


std::stack<int> graph::A_star(int _ID_source, int _ID_end){

	std::shared_ptr<tram_stop> tmp;
	std::stack<int> route;
	std::queue<int> Q;
	Q.push(_ID_source);

	int u = _ID_source;
	int s;

	bool end=false;

	this->stops[u]->colour='b';




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



