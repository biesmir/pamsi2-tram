/*
 * tram_stop.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <iostream>

#include "../inc/tram_stop.hh"



tram_stop::tram_stop(int _ID1, int _ID2, std::string _name)
:ID1(_ID1),
 ID2(_ID2),
 name(_name)
{
std::cout<<"bus stop created"<<std::endl; //zakomentuj jeżeli będzie przeszkadzać, póki co powinno się przydać
}


bool tram_stop::operator == (int ID){
	if(ID==this->ID1||ID==this->ID2)
		return 1;
	else return 0;
}
