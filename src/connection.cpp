/*
 * connection.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "../inc/connection.hh"


std::shared_ptr<tram_stop> connection::get_second_stop(int _ID){
	if(_ID == stop1_ID)
		return stop2;
	else return stop1;
}
