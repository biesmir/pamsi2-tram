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



bool tram_stop::add_connection(unsigned short int _time, int _line, std::shared_ptr<tram_stop> next){
	if(_line<-1||_line>40){  	//add max tram number there
		std::cerr<<"błąd dodawania połączenia: błędny numer linii"<<std::endl;
		return 0;
	}

		std::shared_ptr<connection> tmp_ptr = std::make_shared<connection> ((this->get_ID() * 1000 + next->get_ID()),_time, _line, this->shared_from_this(), next);
	conn.push_back(tmp_ptr);
		next->add_connection(tmp_ptr); //adding connection to second stop list of connections
	return 1;

}


void make_connection(unsigned short int _time, int _line,std::shared_ptr<tram_stop> begin ,std::shared_ptr<tram_stop> end){

	std::shared_ptr<connection> tmp_ptr = std::make_shared<connection> ((begin->get_ID() * 1000 + end->get_ID()),_time, _line, begin, end);

	begin->add_connection(tmp_ptr);
	end->add_connection(tmp_ptr);
}


int tram_stop::get_connection(int i){
	return this->conn[i]->get_second_stop(ID)->get_ID();
	return 0;
}
