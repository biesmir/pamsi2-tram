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


	const int time;
	const int ID;
	const std::shared_ptr<tram_stop> next;
	const int next_stop_ID;
	bool trams[35];


public:

/*connection(int _time, int linie[],std::shared_ptr<tram_stop> _stop1,std::shared_ptr<tram_stop> _stop2)
:time(_time), ID(number), stop1(_stop1), stop2(_stop2)

{

}*/

connection(int _ID, int _time, int _line,std::shared_ptr<tram_stop> _stop, int _next_ID)
:time(_time), ID(_ID), next(_stop), next_stop_ID(_next_ID)

{
	trams[_line]=true;
}



std::shared_ptr<tram_stop> get_second_stop(){
	return next;
}
};

#endif /* INC_POLACZENIE_HH_ */
