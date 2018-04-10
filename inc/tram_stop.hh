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
#include <memory>

#include "connection.hh"


class tram_stop: std::enable_shared_from_this<tram_stop>{

private:
	const int ID;
	const std::string name;
	std::list< std::shared_ptr<connection> > conn;

public:
 tram_stop(int ID, std::string _name);
 tram_stop();

 bool operator == (int _ID);

 bool add_connection(unsigned short int _time, int line, std::shared_ptr<tram_stop> next);

 void add_connection(std::shared_ptr<connection> new_connection){
 	this->conn.push_back(new_connection);
 }

 int get_ID(){
	 return this->ID;
 }


};




#endif /* INC_TRAM_STOP_HH_ */
