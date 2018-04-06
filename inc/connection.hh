/*
 * connection.hh
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_POLACZENIE_HH_
#define INC_POLACZENIE_HH_

#include "./line.hh"
class tram_stop;

class connection{
private:

	static int number;
	int time;
	int ID;
	tram_stop *stop1, *stop2;
	line trams[];


public:

connection(int _time, int linie[],tram_stop *_stop1,tram_stop *_stop2)
:time(_time), ID(number++), stop1(_stop1), stop2(_stop2)

{

}

connection(int _time, int linia,tram_stop *_stop1,tram_stop *_stop2)
:time(_time), ID(number++), stop1(_stop1), stop2(_stop2)

{

}

};

#endif /* INC_POLACZENIE_HH_ */
