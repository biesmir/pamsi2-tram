/*
 * main.cpp
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "./inc/main.hh"

std::shared_ptr<tram_stop> destination;

int main(){
	char menu;
	char search = 'b';
	auto czas  = 0;
	srand(time(NULL));
	graph map;
	std::string stop1, stop2;
	int first, second;
	parsall(map);
	load_coor(map);
	//map.all_stops(std::cout);

	std::cout<<"l - wyswietl liste przystankow"<<std::endl;
	std::cout<<"w - wyszukaj trase"<<std::endl;
	std::cout<<"z - zmien algorytm wyszukiwania"<<std::endl;
	std::cout<<"m - wyswietl to menu"<<std::endl;

	while(1){
	std::cin>>menu;
	switch(menu){

		case 'l':
			map.all_stops(std::cout);
			break;

		case 'w':
			do{
				std::cout<<std::endl<<"Podaj przystanek początkowy: ";
				std::cin>>stop1;
			}while(map.get_ID(stop1) == -1);

			do{
				std::cout<<std::endl<<"Podaj przystanek końcowy: ";
				std::cin>>stop2;
			}while(map.get_ID(stop2) == -1);

			map.prepare_search();
			find_and_print(map, search, map.get_ID(stop1), map.get_ID(stop2));
			break;

		case 'z':
			std::cout<<"b - bfs"<<std::endl;
			std::cout<<"d - dfs"<<std::endl;
			std::cout<<"a - A*"<<std::endl;
			std::cin>>menu;
			search = menu;
			break;

		case 'm':
			std::cout<<"l - wyswietl liste przystankow"<<std::endl;
			std::cout<<"w - wyszukaj trase"<<std::endl;
			std::cout<<"z - zmien algorytm wyszukiwania"<<std::endl;
			std::cout<<"m - wyswietl to menu"<<std::endl;
			break;

		default:
			std::cerr<<"Błędna opcja"<<std::endl;
	}
}
	/*
do{
std::cout<<std::endl<<"Podaj przystanek początkowy: ";
std::cin>>stop1;
}while(map.get_ID(stop1) == -1);

do{
std::cout<<std::endl<<"Podaj przystanek końcowy: ";
std::cin>>stop2;
}while(map.get_ID(stop2) == -1);

map.prepare_search();
find_and_print(map, 'd', map.get_ID(stop1), map.get_ID(stop2));
*/
//find(map, 'd', map.get_ID(stop1), map.get_ID(stop2));

/*
for(int i=0; i<5000; i++){
	map.prepare_search();
	do{
	first = rand()%179; second = rand()%179;
	}while(first==second);

	auto begin = std::chrono::high_resolution_clock::now();
	//uint32_t iterations =1;



	find(map, 'b', first, second);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
	czas += duration;
}
std::cout<<"Sredni czas wyszukiwania bfs: "<<czas/5000<<" ns"<<std::endl;
*/

/*
do{
first = rand()%179; second = rand()%179;
}while(first==second);



find(map, 'b', first, second);
*/
	return 0;
}


