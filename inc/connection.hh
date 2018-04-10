/*
 * connection.hh
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_POLACZENIE_HH_
#define INC_POLACZENIE_HH_

#include "./line.hh"
#include "tram_stop.hh"
class tram_stop;

class connection{
private:

//	static int number; //current number of connections
	int time;
	int ID;
	std::shared_ptr<tram_stop> stop1, stop2;
	int trams[];


public:

/*connection(int _time, int linie[],std::shared_ptr<tram_stop> _stop1,std::shared_ptr<tram_stop> _stop2)
:time(_time), ID(number), stop1(_stop1), stop2(_stop2)

{

}*/

connection(int _ID, int _time, int linia,std::shared_ptr<tram_stop> _stop1, std::shared_ptr<tram_stop> _stop2)
:time(_time), ID(_ID), stop2(_stop2)

{

}

};

#endif /* INC_POLACZENIE_HH_ */
