/*
 * line.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/line.hh"


std::string	line::line_name()const{

	if(this->line_ID == 0)
		return "0P";
	else return "0L";

}

	std::ostream & operator << (std::ostream & Strm , const line & _linia){
	Strm<<_linia.line_name();
	return Strm;
}
