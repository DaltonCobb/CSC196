#include "product.h"
#include <iostream>
using namespace std;

int Product::uniqueId = 0;


void Product::Read(istream& istream, ostream& ostream)
{
	ostream << "Title: ";
	getline(istream, title);
	istream.ignore(80, '\n');
	ostream << "Year: ";
	istream >> releaseYear;
	ostream << "Price: ";
	istream >> price;
	istream.ignore(80, '\n');
}
void Product::Write(ostream& ostream)
{
	ostream << "ID: " << id << endl;
	ostream << "Title: " << title << endl;
	ostream << "Year: " << releaseYear << endl;
	ostream << "Price: " << price << endl;
}
void Product::Read(ifstream& istream)
{
	istream >> id;
	istream.ignore(80, '\n');
	getline(istream, title);
	istream >> releaseYear;
	istream.ignore(80, '\n');
	istream >> price;
	istream.ignore(80, '\n');
}
void Product::Write(ofstream& ostream)
{
	ostream << id << endl;
	ostream << title << endl;
	ostream << releaseYear << endl;
	ostream << price << endl;
}
