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
	parsing(Graph, "../Data/1.txt");
	parsing(Graph, "../Data/4.txt");
	parsing(Graph, "../Data/0p.txt");
	parsing(Graph, "../Data/0l.txt");
	parsing(Graph, "../Data/2.txt");
	parsing(Graph, "../Data/3.txt");
	parsing(Graph, "../Data/5.txt");
	parsing(Graph, "../Data/6.txt");
	parsing(Graph, "../Data/7.txt");
	parsing(Graph, "../Data/8.txt");
	parsing(Graph, "../Data/9.txt");
	parsing(Graph, "../Data/10.txt");
	parsing(Graph, "../Data/11.txt");
	parsing(Graph, "../Data/14.txt");
	parsing(Graph, "../Data/15.txt");
	parsing(Graph, "../Data/17.txt");
	parsing(Graph, "../Data/20.txt");
	parsing(Graph, "../Data/23.txt");
	parsing(Graph, "../Data/24.txt");
	parsing(Graph, "../Data/31.txt");
	parsing(Graph, "../Data/32.txt");
	parsing(Graph, "../Data/33.txt");

	return 1;
}

int load_coor(graph & Graph)
{
	ifstream plik;
	plik.open("stops.txt");

	if(plik.is_open())
		{
		    string word, line;
		    double lat,lon;
		    getline(plik,line); //pierwsz linia niewazna

		    while(plik>>word)
		        {
		    	plik >> lat;
		    	plik >> lon;
		    	Graph.add_coor(word,lat,lon);   //dodaj wspolrzedne do wczytanego przystanku, jezeli istnieje
		        }
		}
	else
	    {
			cout<<"Nie udalo sie wczytac z pliku";
	    }
	plik.close();
	return 1;
}
