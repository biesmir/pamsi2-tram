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
czy_dojade.make_random_graph(15);
czy_dojade.all_stops(std::cout);
std::queue<int> route = czy_dojade.bfs(1,4);
//std::cout<<route.back();

	return 0;
}


