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
parsing(czy_dojade, "../Data/0l.txt");
parsing(czy_dojade, "../Data/5.txt");
parsing(czy_dojade, "../Data/6.txt");


find(czy_dojade, 'b', 2, 34);

find(czy_dojade, 'd', 2, 34);
std::cout<<czy_dojade.get_name(2)<<std::endl;
std::cout<<czy_dojade.get_name(34)<<std::endl;
	return 0;
}


