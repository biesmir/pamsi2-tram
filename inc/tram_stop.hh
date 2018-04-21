/*
 * tram_stop.hh
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_TRAM_STOP_HH_
#define INC_TRAM_STOP_HH_

#include <iostream>
#include <vector>
#include <memory>


#include "connection.hh"


class tram_stop: std::enable_shared_from_this<tram_stop>{

private:
	const int ID;
	const std::string name;
	std::vector< connection > conn;

public:
	char colour;
	std::shared_ptr<tram_stop> parent;
	int time;

 tram_stop(int ID, std::string _name);
 tram_stop();

 bool operator == (int _ID);

friend bool make_connection(unsigned short int _time, int _line,std::shared_ptr<tram_stop> begin ,std::shared_ptr<tram_stop> end);


 int get_ID(){
	 return this->ID;
 }

std::string get_name(){
	return this->name;
}

int get_number_of_connections(){
	return conn.size();
}

int get_connection_ID(int i);
int get_connection_time(int i){
	return time;
}

std::shared_ptr<tram_stop> get_connection(int i);

};




#endif /* INC_TRAM_STOP_HH_ */
