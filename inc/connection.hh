/*
 * connection.hh
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_POLACZENIE_HH_
#define INC_POLACZENIE_HH_


#include <iostream>
#include <vector>
#include <memory>

class tram_stop;


class connection{
private:

//	static int number; //current number of connections
	int time;
	int ID;
	std::shared_ptr<tram_stop> stop1, stop2;
	int stop1_ID, stop2_ID;
	int trams[];


public:

/*connection(int _time, int linie[],std::shared_ptr<tram_stop> _stop1,std::shared_ptr<tram_stop> _stop2)
:time(_time), ID(number), stop1(_stop1), stop2(_stop2)

{

}*/

connection(int _ID, int _time, int linia,std::shared_ptr<tram_stop> _stop1, std::shared_ptr<tram_stop> _stop2)
:time(_time), ID(_ID), stop1(_stop1), stop2(_stop2)

{

}

connection(int _ID, int _time, int linia,std::shared_ptr<tram_stop> _stop1, std::shared_ptr<tram_stop> _stop2, int ID_stop1, int ID_stop2)
:time(_time), ID(_ID), stop1(_stop1), stop2(_stop2),stop1_ID(ID_stop1),stop2_ID(ID_stop2)

{

}

std::shared_ptr<tram_stop> get_second_stop(int _ID);

};

#endif /* INC_POLACZENIE_HH_ */
