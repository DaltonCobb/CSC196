// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "array.h"
#include "vector.h"
#include "list.h"
#include <iostream>
#include <list>
#include "main.h"

using namespace std;

void DisplayArray(const dc::array<int, 5>& a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void DisplayVector(const dc::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	
	dc::list<int> numbers{ 12, 78, 12, 34, 9 };
	numbers.push_back(10);
	numbers.push_front(8);
	numbers.write(cout);
	dc::list<int> copy;
	copy = numbers; 
	copy.pop_front();
	copy.pop_back(); 
	copy.pop_back(); 
	copy.write(cout);
	//copy.remove(12);
	copy.write(cout); 
	copy.resize(10, 99);
	copy.write(cout);
	//numbers.reverse(); 
	numbers.write(cout);

	cout << "front: " << numbers.front() << endl;
	cout << "back: " << numbers.back() << endl;
	cout << "size: " << numbers.size() << endl;
	cout << "empty: " << numbers.empty() << endl;
	//// array
	//nc::array<int, 5> numbers{ 23, 54, 6, 12, 92 };
	//numbers[0] = 23;
	//nc::array<int, 5> copy{ numbers };
	//DisplayArray(copy);

	//// vector
	//nc::vector<int> vnumbers{ 5, 67, 87, 99 };
	//vnumbers.push_back(12);
	//vnumbers.push_back(43);
	//vnumbers.resize(3, 8);

	//DisplayVector(vnumbers);
	//cout << "max size: " << vnumbers.max_size() << endl;

	//nc::vector<int> cvnumbers{ vnumbers };
	//cvnumbers.push_back(7);
	//DisplayVector(cvnumbers);

	//int i{ 1234 }; //(4 bytes)
	//char c{ static_cast<char>(i) }; //(1 byte) <- (4 bytes)
}




