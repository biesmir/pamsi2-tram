/*
 * a_star.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"
#include <stack>

int heuristic(const std::shared_ptr<tram_stop> stop1, const std::shared_ptr<tram_stop> stop2){
	return 394 * int(Sdistance(stop1, stop2));
}

bool operator < (const std::shared_ptr<tram_stop> stop1, const std::shared_ptr<tram_stop> stop2){
	extern std::shared_ptr<tram_stop> destination;
	if(heuristic(stop1, destination) < heuristic(stop2, destination))
			return 1;
	else return 0;

}



std::stack<int> graph::A_star(int _ID_source, int _ID_end){
	extern std::shared_ptr<tram_stop> destination;
	destination = this->stops[_ID_end];
	std::shared_ptr<tram_stop> tmp;
	std::stack<int> route;
	std::priority_queue< std::shared_ptr<tram_stop > > Q;
	Q.push( this->stops[_ID_source]);

	std::shared_ptr<tram_stop > u = this->stops[_ID_source];
	std::shared_ptr<tram_stop > s;

	bool end=false;

	u->colour='b';

	while(!Q.empty() && !end){

		u = Q.top();
		Q.pop();

		for(int i=0;i<u->get_number_of_connections();i++){
			s=this->stops[u->get_connection_ID(i)];

			if(s== this->stops[_ID_end]){

					s->parent = u;

					end=true;

					break;
			}
			if(s->colour =='w'){
						Q.push(s);

						s->colour = 'b';



						s->parent = u;

						s->conn_from_parent= i;


			}


			}

	}

tmp = s;

route.push(tmp->get_ID());

while( tmp->parent != NULL){
		tmp = tmp -> parent;
		route.push(tmp->get_ID());
	}



	return route;
}
