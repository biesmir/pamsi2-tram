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
plik.open(file_name);

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
        Graph.add_stop(word);  //dodanie drugiego przystanku
        Graph.add_connection(word2,word,time,line);   //dodanie pierwszego polaczenia z txt

        while(plik>>word)
        {


            if (word=="X") {
            	plik.close();
            	return 1;
            }

            plik>>word2;
            Graph.add_stop(word2);
            plik>>line; // linia
            plik>>time; // czas
            plik>>word; // id
            plik>>word; // nazwa
            Graph.add_stop(word);
            Graph.add_connection(word2,word,time,line);



            plik>>line; // linia
            plik>>time; // czas
            plik>>word; // id
            plik>>word; // nazwa
            Graph.add_stop(word);
            Graph.add_connection(word2,word,time,line);
        }

	}
else
    {
		cerr<<"Nie uda³o siê otworzyæ pliku";
		return 0;
    }

return -1;
}

int parsall(graph & Graph){
	parsing(czy_dojade, "../Data/1.txt");
	parsing(czy_dojade, "../Data/4.txt");
	parsing(czy_dojade, "../Data/0p.txt");
	parsing(czy_dojade, "../Data/0l.txt");
	parsing(czy_dojade, "../Data/2.txt");
	parsing(czy_dojade, "../Data/3.txt");
	parsing(czy_dojade, "../Data/5.txt");
	parsing(czy_dojade, "../Data/6.txt");
	parsing(czy_dojade, "../Data/7.txt");
	parsing(czy_dojade, "../Data/8.txt");
	parsing(czy_dojade, "../Data/9.txt");
	parsing(czy_dojade, "../Data/10.txt");
	parsing(czy_dojade, "../Data/11.txt");
	parsing(czy_dojade, "../Data/14.txt");
	parsing(czy_dojade, "../Data/15.txt");
	parsing(czy_dojade, "../Data/17.txt");
	parsing(czy_dojade, "../Data/20.txt");
	parsing(czy_dojade, "../Data/23.txt");
	parsing(czy_dojade, "../Data/24.txt");
	parsing(czy_dojade, "../Data/31.txt");
	parsing(czy_dojade, "../Data/32.txt");
	parsing(czy_dojade, "../Data/33.txt");

	return 1;
}

