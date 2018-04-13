/*
 * parsing.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: Jakub Cebulski
 */


#include "../inc/parsing.hh"

using namespace std;


int parsing(graph & Graph, std::string file_name){
ifstream plik;
plik.open("1.txt");

if(plik.is_open())
	{
	    string word, word2;
		unsigned short int time;
	    int line;
	    plik>>word;	    plik>>word2;
	    Graph.add_stop(word2);  //dodanie pierwszego przystanku
        plik>>line; // linia
        plik>>time; // czas
        plik>>word; // id
        plik>>word; // nazwa
        Graph.add_connection(word2,word,time,line);   //dodanie pierwszego polaczenia z txt

        while(plik>>word)
        {
            if (word=="X") {return 1;}
            plik>>word2;
            Graph.add_stop(word2);
            plik>>line; // linia
            plik>>time; // czas
            plik>>word; // id
            plik>>word; // nazwa
            Graph.add_connection(word2,word,time,line);

            plik>>line; // linia
            plik>>time; // czas
            plik>>word; // id
            plik>>word; // nazwa
            Graph.add_connection(word2,word,time,line);
        }

	}
else
    {
		cerr<<"Nie uda³o siê otworzyæ pliku";
    }

return 0;
}

