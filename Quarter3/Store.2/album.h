#pragma once
#pragma once
#include <string>

//enum class eGenre
//{
	//ROCK,
	//HIPHOP,
	//COUNTRY,
	//RNB,
	//RAP

//};
class Album
{

	Album()
	{
		setTitle("unknown");
		setNumberOfSongs(0);
		setPrice(0.00);
		setReleaseYear(0000);
		setAuthor("unknown");
		//eGenre ROCK;
	}
public:
	Album(std::string title_, int numberOfSongs_, double price_, int releaseYear_, std::string author_)
	{
		setTitle(title_);
		setNumberOfSongs(numberOfSongs_);
		setPrice(price_);
		setReleaseYear(releaseYear_);
		setAuthor(author_);
		//eGenre;
	}
public:

	void setTitle(std::string t) {
		title = t;
	};
	std::string getTitle() {
		return title;
	};

	void setNumberOfSongs(int n)
	{
		numberOfSongs = n;
	};
	int getNumberOfSongs()
	{
		return numberOfSongs;
	};

	void setPrice(double p)
	{
		price = p;
	};
	double getPrice()
	{
		return price;
	};

	void setReleaseYear(int r)
	{
		releaseYear = r;
	};
	int getReleaseYear()
	{
		return releaseYear;
	};
	void setAuthor(std::string a)
	{
		author = a;
	};
	std::string getAuthor()
	{
		return author;
	};
	void Write();
	void Read();


	std::string title;
	int numberOfSongs;
	double price;
	int releaseYear;
	std::string author;;


};