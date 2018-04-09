/*
 * graph.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"


/*
 * nie mam pewności czy nie tworzy się podwójna ilość obiektów
 * przydało by się zamienić na inteligentne wskaźniki
 *
 * */
void graph::add_stop(int ID1, int ID2, std::string name){
	std::shared_ptr<tram_stop> tmp_ptr = std::make_shared<tram_stop>(ID1,ID2,name);
	this->stops.push_back(tmp_ptr);
	size++;
}

void graph::make_random_graph(int size){
	std::string city[]={"Wadowice (MP)","    Wałbrzych (DŚ)","    Wałcz (ZP)","    Warka (MZ)","    Warszawa (MZ)","    Warta (ŁD)","    Wasilków (PL)","    Wąbrzeźno (KP)","    Wąchock (ŚK)","    Wągrowiec (WP)","    Wąsosz (DŚ)","    Wejherowo (PM)","    Węgliniec (DŚ)","    Węgorzewo (WM)","    Węgorzyno (ZP)","    Węgrów (MZ)","    Wiązów (DŚ)","    Wieleń (WP)","    Wielichowo (WP)","    Wieliczka (MP)","    Wieluń (ŁD)","    Wieruszów (ŁD)","    Więcbork (KP)","    Wilamowice (ŚL)","    Wisła (ŚL)","    Wiślica (ŚK)","    Witkowo (WP)","    Witnica (LS)","    Wleń (DŚ)","    Władysławowo (PM)","    Włocławek (KP)","    Włodawa (LB)",    "Włoszczowa (ŚK)"};
	for(int i=0;i<size;i++){
		this->add_stop(i,size+i,city[i]);

	}
}


bool graph::add_connection(int ID1, int ID2, int time, int line){



	return 0;
	//else return 1;
}
