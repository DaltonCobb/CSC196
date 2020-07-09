#include "album.h"
#include <iostream>

using namespace std;

void Album::Write()
{
	cout << getTitle() << endl;
	cout << getNumberOfSongs() << endl;
	cout << getPrice() << endl;
	cout << getReleaseYear() << endl;
	cout << getAuthor() << endl;


}

void Album::Read()
{
	//int genre;
	//eGenre g = eGenre(genre);
	cout << "title: ";
	cin >> title;
	cout << "Number Of Songs: ";
	cin >> numberOfSongs;
	cout << "price:$ ";
	cin >> price;
	cout << " releaseYear: ";
	cin >> releaseYear;
	cout << "author: ";
	cin >> author;
	//cout << "Please enter genre (1 ROCK , 2 HIPHOP, 3 COUNTRY, 4 RNB, 5 RAP)";
	//cin >> genre;

}
