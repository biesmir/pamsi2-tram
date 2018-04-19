/*
 * tram_stop.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include <iostream>

#include "../inc/tram_stop.hh"



tram_stop::tram_stop(int _ID, std::string _name)
:ID(_ID),
 name(_name)
{

}


bool tram_stop::operator == (int _ID){
	if(_ID==this->ID)
		return 1;
	else return 0;
}






bool make_connection(unsigned short int _time, int _line,std::shared_ptr<tram_stop> begin ,std::shared_ptr<tram_stop> end){

	if(_line<-1||_line>33){
		std::cerr<<"błąd dodawania połączenia: błędny numer linii"<<std::endl;
		return 0;
	}
	connection tmp1((begin->get_ID() * 1000 + end->get_ID()),_time, _line, end, end->get_ID());
	connection tmp2((end->get_ID() * 1000 + begin->get_ID()),_time, _line, begin, begin->get_ID());
	begin->conn.push_back(tmp1);
	begin->conn.push_back(tmp2);
	return 1;

}


std::shared_ptr<tram_stop> tram_stop::get_connection(int i){
	return this->conn[i].get_second_stop();
}

int tram_stop::get_connection_ID(int i){
	return this->conn[i].get_second_stop()->get_ID();
}
