#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Product
{
public:
	enum class eType
	{
		MOVIE,
		ALBUM
	};
public:
	Product()
	{
		id = uniqueId++;
	}
	Product(std::string title_, int releaseYear_, float price_ = 19.99f)
	{
		this->title = title_;
		this->releaseYear = releaseYear_;
		this->price = price_;


	}

public:
	virtual eType getType() { return eType::MOVIE; }

	std::string getTitle() { return title; }
	void setTitle(std::string title) { this->title = title; }

	int getReleaseYear() { return releaseYear; }
	void setReleaseYear(int releaseYear) { this->releaseYear = releaseYear; }

	float getPrice() { return price; }
	void setPricce(float price) { this->price = price; }

	int getId() { return id; }
	  


	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);

protected:
	std::string title;
	int releaseYear;
	float price;
	int id;
	static int uniqueId;

};
