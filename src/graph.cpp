/*
 * graph.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"



void graph::add_stop(std::string name){

	for(unsigned int i=0;i<this->stops.size();i++)
		if(this->stops[i]->get_name()==name)
			return;

	std::shared_ptr<tram_stop> tmp_ptr = std::make_shared<tram_stop>(size++,name);
	this->stops.push_back(tmp_ptr);

}


void graph::make_random_graph(int _size){
	std::string city[]={"	Wadowice (MP)","    Wałbrzych (DŚ)","    Wałcz (ZP)","    Warka (MZ)","    Warszawa (MZ)","    Warta (ŁD)","    Wasilków (PL)","    Wąbrzeźno (KP)","    Wąchock (ŚK)","    Wągrowiec (WP)","    Wąsosz (DŚ)","    Wejherowo (PM)","    Węgliniec (DŚ)","    Węgorzewo (WM)","    Węgorzyno (ZP)","    Węgrów (MZ)","    Wiązów (DŚ)","    Wieleń (WP)","    Wielichowo (WP)","    Wieliczka (MP)","    Wieluń (ŁD)","    Wieruszów (ŁD)","    Więcbork (KP)","    Wilamowice (ŚL)","    Wisła (ŚL)","    Wiślica (ŚK)","    Witkowo (WP)","    Witnica (LS)","    Wleń (DŚ)","    Władysławowo (PM)","    Włocławek (KP)","    Włodawa (LB)",    "Włoszczowa (ŚK)"};
	for(int i=0;i<_size;i++){
		this->add_stop(city[i]);

	}
	for(int i=0;i<(_size-1)*2;i++){

		this->add_connection(i/2,rand()%(size-1),9,20);

	}

	for(int i=0;i<(_size-1)*2;i++){

		this->add_connection(rand()%(size-1),rand()%(size-1),9,20);

	}

}


bool graph::add_connection(int ID1, int ID2, unsigned short int _time, int _line){
	int j,i;
	i=j=0;

	while( this->stops[i]->get_ID() != ID1  &&  i<=size)
		i++;

	while( this->stops[j]->get_ID() != ID2  &&  j<=size)
		j++;


	make_connection(_time,_line, this->stops[i], this->stops[j]);

//std::cout<<size<<std::endl;
	return 0;
	//else return 1;
}

void graph::all_stops(std::ostream& strm){
	for(int i=0;i<this->size;i++)
		strm<< this->stops[i]->get_name()<<std::endl;
}

bool graph::add_connection(std::string _stop1, std::string _stop2, unsigned short int _time, int _line){
	int j,i;
	i=j=0;

	while( this->stops[i]->get_name() != _stop1  &&  i<=size) //do to
		i++;

	while( this->stops[j]->get_name() != _stop2  &&  j<=size)
		j++;


	make_connection(_time, _line, this->stops[i], this->stops[j]);

	return 1;
}
