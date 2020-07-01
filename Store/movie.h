#pragma once
#include "product.h"
#include <string>

class Movie : public Product
{
public:
	enum class eGenre
	{
		HORROR,
		COMEDY,
		ACTION,
		DRAMA,
		SCINCEFICTION,
		ADVENTURE,
		ROMANCE,
		THRILLER
	};
public:
	Movie() 
	{
		id = uniqueId++;
	}

	Movie(int lengthOfMovie_, std::string director_, eGenre genre) : Product(title, releaseYear, price)
	{
		lengthOfMovie = lengthOfMovie_;
		director = director_;
		genre = eGenre::HORROR;
	}
public:
	int getLengthOfMovie() { return lengthOfMovie; }

	 eType getType() { return eType::MOVIE; }

	std::string getDirector() { return director; }


	std::string getStringFromEnum(eGenre genre);

	void Read(std::istream& istream,std::ostream& ostream);
	void Write(std::ostream& ostream);

	void Read(std::ifstream& istream);
	void Write(std::ofstream& ostream);


protected:
	int lengthOfMovie;
	std::string director;
	eGenre genre;
	int id;
};
