/*
 * line.hh
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_LINIA_HH_
#define INC_LINIA_HH_

#include <iostream>

class line{


public:
	line(const int nr) :line_ID(nr)
			{}

	std::string line_name()const;

//	line operator = (line tram, int numer){
	//	tram.line_ID=numer;
		//tram._nazwa_linii=
		//return line;
//	}

private:
	const int line_ID;	//0L to -1, 0P to 0

};

std::ostream & operator << (std::ostream & Strm , const line & _linia);


#endif /* INC_LINIA_HH_ */
