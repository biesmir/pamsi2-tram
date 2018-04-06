/*
 * graph.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: Jakub Cebulski
 */

#include "../inc/graph.hh"



void graph::add_stop(int ID1, int ID2, std::string name){
tram_stop * tmp_ptr = new tram_stop(ID1,ID2,name);
this->stops.push_back(*tmp_ptr);
size++;
}
