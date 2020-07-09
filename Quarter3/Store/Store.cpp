#include "album.h"
#include "movie.h"
#include "products.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

enum class eAction
{
	QUIT,
	LOAD,
	SAVE,
	DISPLAY_ALL,
	DISPLAY_TYPE,
	DISPLAY_ID,
	ADD,
	REMOVE,
	REMOVE_ALL
};

int main()
{
	Products products;

	bool quit = false;
	do {
		cout << "Menu\n";
		cout << "0) Quit\n";
		cout << "1) Load\n";
		cout << "2) Save\n";
		cout << "3) Display All\n";
		cout << "4) Display Type\n";
		cout << "5) Display Id\n";
		cout << "6) Add\n";
		cout << "7) Remove\n";
		cout << "8 ) Remove All\n";


		int select;
		cin >> select;
		cin.ignore(80, '\n');

		eAction action = static_cast<eAction>(select);

		switch (action)
		{
		case eAction::QUIT:
			quit = true;
			break;
		case eAction::LOAD:
		{
			string filename;
			cout << "Enter filename: ";
			getline(cin, filename);
			products.Load(filename);
		}
		break;
		case eAction::SAVE:
		{
			string filename;
			cout << "Enter filename: ";
			getline(cin, filename);
			products.Save(filename);
		}
		break;
		case eAction::DISPLAY_ALL:
			products.DisplayAll();
			break;
		case eAction::DISPLAY_TYPE:
		{
			cout << "Enter type(0 = Movie, 1= Album): ";
			int select;
			cin >> select;
			cin.ignore(80, '\n');
			Product::eType type = static_cast<Product::eType>(select);
			products.Display(type);
		}
		break;
		case eAction::DISPLAY_ID:
		{
			cout << "Enter id: ";
			int id;
			cin >> id;
			cin.ignore(80, '\n');
			products.Display(id);
		}
		break;
		case eAction::ADD:
		{
			//create product
			cout << "Enter type(0 = Movie, 1= Album): ";
			int select;
			cin >> select;
			cin.ignore(80, '\n');
			Product::eType type = static_cast<Product::eType>(select);
			Product* product = products.Create(type);			
			//read product from console
			product->Read(cin, cout);
			//add product to poducts
			products.Add(product);
		}
		break;
		case eAction::REMOVE:
		{
			cout << "Enter id: ";
			int id;
			cin >> id;
			cin.ignore(80, '\n');
			products.Remove(id);
		}
		break;
		case eAction::REMOVE_ALL:
			products.RemoveAll();
			break;
		default:
			break;
		}

	} while (!quit);


}
