/*
 * dfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */




#include <unistd.h>
#include "../inc/graph.hh"
#include <stack>


std::queue<int> graph::dfs(int _ID_source, int _ID_end){
	std::queue<int>  route;
	std::shared_ptr<tram_stop> tmp;
	std::stack<int> Rroute;

	for(int i = 0; i < this->size-1; i++){
		this->stops[i]->colour='w';
	}
	int u = _ID_source;
	int s,z;
	this->stops[u]->colour='b';
	bool end=false;



	std::stack<int> S;
	S.push(_ID_source);

	while(!S.empty() && !end){

		u = S.top();
		S.pop();
		if(u==_ID_end){
				std::cout<<"znaleziono"<<std::endl;
				/*
				s=this->stops[u]->get_connection_ID(???);
				this->stops[s]->parent = this->stops[u];

				this->stops[s]->time = this->stops[u]->get_connection_time(i);
				*/
				end=true;
				break;
		}


		for(int i=this->stops[u]->get_number_of_connections()-1;i>=0;i--){
			s=this->stops[u]->get_connection_ID(i);

			if(this->stops[s]->colour =='w'){
						S.push(s);
						this->stops[s]->colour = 'b';
						std::cout<<s<<std::endl;
						this->stops[s]->parent = this->stops[u];
						this->stops[s]->time = this->stops[u]->get_connection_time(i);
						std::cout<<s<<std::endl;
					//	sleep(1);
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
