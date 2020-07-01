#include "album.h"
#include <iostream>

using namespace std;

void Album::Write(ostream& ostream)
{
	Product::Write(ostream);
	ostream << "Number of songs: " << numberOfSongs << endl;
	ostream << "Author: " << author << endl;
	ostream << "Genre: " << getStringFromEnum(genre) << endl;


}

void Album::Read(istream& istream, ostream& ostream)
{
	Product::Read(istream ,ostream );

	ostream << "Number Of Songs: ";
	istream >> numberOfSongs;
	istream.ignore(80, '\n');
	ostream << "Author: ";
	std::getline(std::cin, author);
	ostream << "Please enter genre (1 ROCK , 2 HIPHOP, 3 COUNTRY, 4 RNB, 5 RAP)";
	int input;
	istream >> input;
	genre = static_cast<eGenre>(input);

}

void Album::Read(ifstream& istream)
{
	istream >> id;
	istream.ignore(80, '\n');
	istream >> numberOfSongs;
	istream.ignore(80, '\n');
	getline(istream, author);
	int input;
	istream >> input;
	genre = static_cast<eGenre>(input);
	istream.ignore(80, '\n');

}
void Album::Write(ofstream& ostream)
{
	ostream << id << endl;
	ostream << numberOfSongs << endl;
	ostream << author << endl;
	ostream << static_cast<int>(eGenre::ROCK) << endl;

}


string Album::getStringFromEnum(eGenre genre)
{
	switch (genre)
	{
	case Album::eGenre::ROCK:
		return "Rock";
		break;
	case Album::eGenre::HIPHOP:
		return "HipPop";
		break;
	case Album::eGenre::COUNTRY:
		return "Country";
		break;
	case Album::eGenre::RNB:
		return "RnB";
		break;
	case Album::eGenre::RAP:
		return "Rap";
		break;
	default:
		break;
	}
	return "";
};





