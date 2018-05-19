/*
 * graph.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"



bool graph::add_stop(std::string name){

	for(unsigned int i=0;i<this->stops.size();i++)
		if(this->stops[i]->get_name()==name)
			return 0;

	std::shared_ptr<tram_stop> tmp_ptr = std::make_shared<tram_stop>(size++,name);
	this->stops.push_back(tmp_ptr);
	return 1;
}

void graph::add_coor(std::string name, double lat, double lon){
	for(unsigned int i=0;i<this->stops.size();i++)  //szuka we wszystkich przystankach nazwe wywolanego
			if(this->stops[i]->get_name()==name){
				//dodaj wspolrzedne do przystanku
				this->stops[i]->change_latitude(lat);
				this->stops[i]->change_longitude(lon);
			}

}


void graph::make_random_graph(int _size){
	std::string city[]={"	Wadowice (MP)","    WaĹ‚brzych (DĹš)","    WaĹ‚cz (ZP)","    Warka (MZ)","    Warszawa (MZ)","    Warta (Ĺ�D)","    WasilkĂłw (PL)","    WÄ…brzeĹşno (KP)","    WÄ…chock (ĹšK)","    WÄ…growiec (WP)","    WÄ…sosz (DĹš)","    Wejherowo (PM)","    WÄ™gliniec (DĹš)","    WÄ™gorzewo (WM)","    WÄ™gorzyno (ZP)","    WÄ™grĂłw (MZ)","    WiÄ…zĂłw (DĹš)","    WieleĹ„ (WP)","    Wielichowo (WP)","    Wieliczka (MP)","    WieluĹ„ (Ĺ�D)","    WieruszĂłw (Ĺ�D)","    WiÄ™cbork (KP)","    Wilamowice (ĹšL)","    WisĹ‚a (ĹšL)","    WiĹ›lica (ĹšK)","    Witkowo (WP)","    Witnica (LS)","    WleĹ„ (DĹš)","    WĹ‚adysĹ‚awowo (PM)","    WĹ‚ocĹ‚awek (KP)","    WĹ‚odawa (LB)",    "WĹ‚oszczowa (ĹšK)"};
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
	strm<<this->stops.size()<<" przystankow"<<std::endl;
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


void find_and_print(graph map, char algoritm, int source, int end){
	std::stack<int> route;
	int i = 0;
	int tmp;
	int counter = 0;
	int time=0;

	switch(algoritm){

	case 'd':	//depth first search
			route = map.dfs(source,end);
			break;

	case 'b':	//breadth first search

		route = map.bfs(source,end);
		break;

	default:
		std::cerr<<"bĹ‚Ä™dna opcja"<<std::endl;
		break;
	}

		tmp = map.stops[route.top()]->get_ID();

			std::cout<<"Na przystanku: ";
			std::cout<< map.stops[route.top()]->get_name() <<std::endl;
			time += map.stops[tmp]->get_time( map.stops[route.top()]->conn_from_parent);
			route.pop();
			std::cout<<" wsiÄ…dĹş w tramwaj linii: ";

			while(!map.stops[tmp]->check_connection( map.stops[route.top()]->conn_from_parent, i))
				i++;
			if(i==0)
				std::cout<<"0p";
			else if(i==34)
				std::cout<<"0l";
			else
				std::cout<<i;

			std::cout<<std::endl;



			while(!route.empty()){
				while(map.stops[tmp]->check_connection( map.stops[route.top()]->conn_from_parent, i)&& !route.empty()){
					counter++;
				tmp = map.stops[route.top()]->get_ID();
				time += map.stops[tmp]->get_time( map.stops[route.top()]->conn_from_parent);
				route.pop();

				}
				if(counter>4)
					std::cout<<"przejedĹş "<<counter <<" przystankĂłw"<<std::endl;
				else if(counter>1)
					std::cout<<"przejedĹş "<<counter <<" przystanki"<<std::endl;
				else if(counter==1)
					std::cout<<"przejedĹş "<<counter <<" przystanek"<<std::endl;

				if(!route.empty() && route.top() != end){
					std::cout<<"Na przystanku: "<<map.stops[route.top()]->get_name()<<" przesiÄ…dĹş siÄ™ w tramwaj linii: ";

					i=0;
					while(!map.stops[tmp]->check_connection( map.stops[route.top()]->conn_from_parent, i))
						i++;

				if(i==0)
					std::cout<<"0p";
				else if(i==34)
					std::cout<<"0l";
				else std::cout<<i;
				std::cout<<std::endl;
				}
				else break;
			}


std::cout<<"Przejazd do przystanku: "<<	map.stops[tmp]->get_name()<<" potrwa Ĺ‚Ä…cznie: "<<time<<" minut"<<std::endl;
std::cout<<"dystans katowy to: "<<std::fixed<<Sdistance(map.stops[source], map.stops[end])<<std::endl;


}


void find(graph map, char algoritm, int source, int end){
	std::stack<int> route;

	switch(algoritm){

	case 'b':	//breadth first search

		route = map.bfs(source,end);

		break;

	case 'd':	//depth first search

		route = map.dfs(source,end);
		break;

	default:
		std::cerr<<"bĹ‚Ä™dna opcja"<<std::endl;
		break;

	}

/*
	while(!route.empty()){
std::cout<<map.stops[route.top()]->get_name()<<" ";
route.pop();
	}


std::cout<<std::endl;
*/
}

void graph::prepare_search(){
	for(unsigned i =0; i< this->stops.size(); i++){
		this->stops[i]->colour = 'w';
		this->stops[i]->conn_from_parent = -2;
		this->stops[i]->parent = NULL;
	}
}
