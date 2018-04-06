/*
 * polaczenie.hh
 *
 *  Created on: 3 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_POLACZENIE_HH_
#define INC_POLACZENIE_HH_

#include "./linia.hh"

class polaczenie{
private:

	int czas_przejazdu;
	int ID;
	linia tramwaje[];

public:

polaczenie(int czas, int _ID, int linie[])
:czas_przejazdu(czas), ID(_ID)

{
for(int i=0; i < int(sizeof(linie)/sizeof(int)) ;i++){
	tramwaje[i]=linie[i];
}
}

};

#endif /* INC_POLACZENIE_HH_ */
