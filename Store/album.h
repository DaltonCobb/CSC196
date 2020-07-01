#pragma once
#include "product.h"
#include <string>

class Album : public Product
{
public:
	enum class eGenre
	{
		ROCK,
		HIPHOP,
		COUNTRY,
		RNB,
		RAP

	};


public:
	Album() 
	{
		id = uniqueId++;
	}

	Album(std::string title_, int releaseYear_, float price_, int numberOfSongs_, std::string author_, eGenre genre_) : Product(title, releaseYear, price)
	{
		numberOfSongs = numberOfSongs_;
		author = author_;
		genre = eGenre::ROCK;


	}



public:
	eType getType() { return eType::ALBUM; }

	int getNumberOfSongs() { return numberOfSongs; }


	std::string getAuthor() { return author; }

	std::string getStringFromEnum(eGenre genre);


	void Read(std::istream& istream,std::ostream& ostream);
	void Write(std::ostream& ostream);

	void Read(std::ifstream& istream);
	void Write(std::ofstream& ostream);



protected:
	int numberOfSongs;
	std::string author;
	eGenre genre;
	int id;

};
