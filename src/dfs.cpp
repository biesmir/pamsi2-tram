/*
 * dfs.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */




#include <unistd.h>
#include "../inc/graph.hh"
#include <stack>


std::stack<int> graph::dfs(int _ID_source, int _ID_end){
	std::stack<int>  route;
	std::shared_ptr<tram_stop> tmp;

	for(int i = 0; i < this->size-1; i++){
		this->stops[i]->colour='w';
	}
	int u = _ID_source;
	int s;
	this->stops[u]->colour='b';
	bool end=false;



	std::stack<int> tmpSt;
	tmpSt.push(_ID_source);

	while(!tmpSt.empty() && !end){

		u = tmpSt.top();
		tmpSt.pop();
		if(u==_ID_end){
				std::cout<<"znaleziono"<<std::endl;
				s = tmpSt.top();
				tmpSt.push(u);

				this->stops[s]->parent = this->stops[u];
				std::cout<<s<<std::endl;
				end=true;
				break;
		}


		for(int i=this->stops[u]->get_number_of_connections()-1;i>=0;i--){
			s=this->stops[u]->get_connection_ID(i);

			if(this->stops[s]->colour =='w'){
				tmpSt.push(s);
						this->stops[s]->colour = 'b';
						std::cout<<s<<std::endl;
						this->stops[s]->parent = this->stops[u];
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
