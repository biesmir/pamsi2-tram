/*
 * tram_stop.hh
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_TRAM_STOP_HH_
#define INC_TRAM_STOP_HH_

#include <iostream>
#include <list>

#include "connection.hh"

class tram_stop{
private:
	const int ID1;
	const int ID2;
	const std::string name;
	std::list<connection*> conn;

public:
 tram_stop(int ID1, int ID2, std::string _name);


 bool operator == (int ID);


};




#endif /* INC_TRAM_STOP_HH_ */
