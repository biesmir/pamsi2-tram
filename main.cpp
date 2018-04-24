/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

int main(){


graph czy_dojade;
std::cout<<parsing(czy_dojade, "1.txt")<<std::endl;

//czy_dojade.all_stops(std::cout);
std::stack<int> route = czy_dojade.bfs(10,14);
while(!route.empty()){
	std::cout<<route.top()<<" ";
	route.pop();
}
std::cout<<std::endl;
	return 0;
}


