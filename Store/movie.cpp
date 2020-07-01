#include "movie.h"
#include <iostream>
#include <fstream>


using namespace std;


void Movie::Write(ostream& ostream)
{
	Product::Write(ostream);

	ostream << "Length of Movie: " << lengthOfMovie << endl;
	ostream << "Director: " << director << endl;
	ostream << "Genre: " << getStringFromEnum(genre) << endl;

}


void Movie::Read(istream& istream, ostream& ostream)
{
	Product::Read(istream,ostream);
	ostream << "Length of movie: ";
	istream >> lengthOfMovie;
	istream.ignore(80, '\n');
	ostream << "Director: ";
	std::getline(std::cin, director);
	ostream << "Please enter genre (1 = HORROR,2 = COMEDY,3 = ACTION, 4= DRAMA, 5= SCINCE FICTION, 6 = ADVENTURE, 7= ROMANCE, 8= THRILLER)";
	int input;
	istream >> input;
	genre = static_cast<eGenre>(input);


}

void Movie::Read(ifstream& istream)
{
	istream >> id;
	istream.ignore(80, '\n');
	istream >> lengthOfMovie;
	istream.ignore(80, '\n');
	getline(istream, director);
	int input;
	istream >> input;
	genre = static_cast<eGenre>(input);
	istream.ignore(80, '\n');

}

void Movie::Write(ofstream& ostream)
{
	ostream << id << endl;
	ostream << lengthOfMovie << endl;
	ostream << director << endl;
	ostream << static_cast<int>(eGenre::ACTION) << endl;

}




std::string Movie::getStringFromEnum(eGenre genre)
{
	switch (genre)
	{
	case Movie::eGenre::HORROR:
		return "Horror";
		break;
	case Movie::eGenre::COMEDY:
		return "Comedy";
		break;
	case Movie::eGenre::ACTION:
		return "Action";
		break;
	case Movie::eGenre::DRAMA:
		return "Drama";
		break;
	case Movie::eGenre::SCINCEFICTION:
		return "Scince Fiction";
		break;
	case Movie::eGenre::ADVENTURE:
		return "Adventure";
		break;
	case Movie::eGenre::ROMANCE:
		return "Romance";
		break;
	case Movie::eGenre::THRILLER:
		return "Thriller";
		break;
	default:
		break;
	}
	return "";
};
