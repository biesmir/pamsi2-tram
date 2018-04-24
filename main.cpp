/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

int main(){


graph czy_dojade;

parsing(czy_dojade, "../Data/1.txt");
parsing(czy_dojade, "../Data/4.txt");
parsing(czy_dojade, "../Data/0p.txt");
parsing(czy_dojade, "../Data/2.txt");


find(czy_dojade, 'b', 2, 30);

	return 0;
}


