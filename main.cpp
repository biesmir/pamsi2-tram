/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

int main(){


graph czy_dojade;
//parsing(czy_dojade, "/tmp/1.txt");
czy_dojade.make_random_graph(9);
czy_dojade.all_stops(std::cout);
czy_dojade.bfs(3,1);


	return 0;
}


