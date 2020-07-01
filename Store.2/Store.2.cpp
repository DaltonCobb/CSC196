// Store.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "album.h"

#include <iostream>


using namespace std;


int main()
{

	Album theIncubus("The Incubus", 12, 9.99, 2016, "Famous Last Words");
	theIncubus.Write();

	Album album();

	album().Read();
	album().Write();
}
