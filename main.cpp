/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

int main(){


graph czy_dojade;
//parsing(czy_dojade, "1.txt");
czy_dojade.make_random_graph(30);
czy_dojade.all_stops(std::cout);
std::queue<int> route = czy_dojade.bfs(2,22);
while(!route.empty()){
	std::cout<<route.back()<<" ";
	route.pop();
}
std::cout<<std::endl;
	return 0;
}


