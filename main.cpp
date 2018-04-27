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
//parsing(czy_dojade, "../Data/0p.txt");
parsing(czy_dojade, "../Data/2.txt");
//parsing(czy_dojade, "../Data/0l.txt");
parsing(czy_dojade, "../Data/5.txt");
parsing(czy_dojade, "../Data/6.txt");

//find(czy_dojade, 'b', 8, 16);
czy_dojade.prepare_search();
/*
auto begin = std::chrono::high_resolution_clock::now();
//uint32_t iterations =1;

find(czy_dojade, 'b', rand()%70, rand()%70);
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
	std::cout << duration ;

*/
	czy_dojade.prepare_search();
find_and_print(czy_dojade, 'b', 8, 36);

	return 0;
}


