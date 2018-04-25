/*
 * connection.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "../inc/connection.hh"


void connection::add_line(short int _line){
	if(_line == -1)
		this->trams[34]=true;
	else
		this->trams[_line]=true;
}
