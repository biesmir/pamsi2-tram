/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

int main(){


graph map;
std::string stop1, stop2;

parsall(map);

std::cout<<"Podaj przystanek początkowy: ";
std::cin>>stop1;
std::cout<<std::endl<<"Podaj przystanek końcowy: ";
std::cin>>stop2;

map.prepare_search();
find_and_print(map, 'b', map.get_ID(stop1), map.get_ID(stop2));
//find(map, 'd', map.get_ID(stop1), map.get_ID(stop2));
/*
auto begin = std::chrono::high_resolution_clock::now();
//uint32_t iterations =1;

find(map, 'b', rand()%70, rand()%70);
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
	std::cout << duration ;

*/



	return 0;
}


