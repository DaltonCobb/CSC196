// Review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//pointer swap (4a)
void swap(int* v1, int* v2)// -> v1 = &i2 (0x1234), v2 = &i3 (0x1238)
{
	int temp = *v1; //-> v1 = &i2 (0x1234) -> [23]
	*v1 = *v2; // -> v2 = &i3 (0x1238) -> [45]
	*v2 = temp;
}

//reference swap (7a)
void swap(int& v1, int& v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

//template (11)
//template<typename T>
// ? max_value? v1,v2)
template<typename T>
T max_value(T v1 , T v2)
{
	if (v1 < v2)
	{
		return v2;
	}
	else
		return v1;
}

//animal class
class Animal
{
public:
	Animal() {}
	Animal(const string& name, int lifespan) : name(name), lifespan(lifespan) {}

	string getName() { return name; }
	void setName(const string& name) { this->name = name; }

	int getLifespan() { return lifespan; }
	void setLifespan(int lifespan) { this->lifespan = lifespan; }

	virtual string Say() { return ""; }

	friend ostream& operator << (ostream& stream, const Animal& animal)
	{
		stream << animal.name << endl;
		return stream;
	}

	/*{
		stream << animal->name << endl;
		return stream;
	}*/

	friend bool operator == (const Animal* animal, const string& name)
	{
		return (animal->name == name);
	}

protected:
	string name;
	int lifespan;
};

// derived animal class 1
class Cat : public Animal
{
public:
	Cat() {}
	Cat(const string& name, int lifespan, int lives) : Animal(name, lifespan), lives(lives) {}

	string Say() override { return "MEOW"; }

protected:
	int lives;
};

// derived animal class 2
class Duck : public Animal
{
public:
	Duck() {}
	Duck(const string& name, int lifespan) : Animal(name, lifespan) {}

	string Say() override { return "QUACK"; }

protected:
	bool iFemale;
};

int main()
{
	//POINTER

	//1) create a pointer (ptr1) that points to i1
	int i1 = 10;
	int* ptr1 = &i1;

	//2) change the value of i1 to 20 by a pointer derefence of ptr1
	// 2b) print the dereference of ptr1
	ptr1 + 10;
	cout << i1 << endl;


	// 3) create a pointer (ptr2) and set it to point at what ptr1 points at


	//cout << &i5 << endl;
	//cout << &ref1 << endl;

	//4a) create a function to swap i2 and i3 with pointers
	//4b)print the values of i2 and i3 after the swap
	int i2 = 23;
	int i3 = 45;

	swap(&i2, &i3);
	cout << i2 << " " << i3 << endl;

	//REFERENCE

	//5) create a refeence (ref1) that references i5 
	int i5 = 30;
	int& ref1 = i5;



	//6a) change the value of i5 using the reference variable 
	//6b) print i5 to show that a change was made 
	ref1 = 14;
	cout << i5 << endl;

	//7a)create a function to swap i2 and i3 with references
	//7b)print the values of i2 and i3 after the swap
	swap(i2, i3);
	cout << i2 << "" << i3 << endl;

	//DYNAMIC MENMORY (HEAP)

	//8) Create a pointer (ptr3) that points to an array of 10 ints that are created on the heap(new)
	int* ptr3 = new int[10];

	//9a)iterate through the array with the pointer (ptr3[]) and set them to a random number between 1 and 10
	for (int i = 0; i < 10; i++)
	{
		ptr3[i] = (rand() % 10) + 1;
		cout << ptr3[i] << " ";
	}
	cout << endl;

	//9b) iterate though the array with the pointer (ptr3[]) and print out only even values (use the %2 to determine if it is even)
	for (int i = 0; i < 10; i++)
	{
		if (ptr3[i] % 2 == 0) cout << ptr3[i] << " ";
	}
	cout << endl;

	//10) free the memory of ptr3 (when deleting an array use delete[])
	delete[] ptr3;

	//TEMPLATE

	//11a) create a template function called max_value to return the max value of two types
	//11b) call the template funtion with two float values and display answer
	cout << max_value<float>(34.5f, 12.0f) << endl;




	//POLYMORPHISM
	//14a) Create a list<> of Animal*
	vector<Animal*> animals;




	Animal* animal;
	animal = new Cat("Fuffy", 16, 9);
	animals.push_back(animal);
	animal = new Duck("Donald", 8);
	animals.push_back(animal);

	for (Animal* animal : animals)
	{
		cout << animal;
	}


	const float PI = 3.1415f;




	//String name("dog")
	auto iter = find(animals.begin(), animals.end(), static_cast<string>("Felix"));
	cout << (*iter);
	for (Animal* animal : animals)
	{
		cout << animal;
	}



	for (Animal* animal : animals)
	{
		delete animal;
	}
	animals.clear();






}


