#include "products.h"
#include "movie.h"
#include "album.h"
#include <fstream> 
#include <iostream>
using namespace std;



void Products::Load(const std::string& filename)
{
	//read from file
	ifstream ifile(filename);
	if (ifile.is_open())
	{
		while (!ifile.eof())
		{
			if (ifile.peek() == EOF)break;

			int itype;
			ifile >> itype;

			Product::eType type = static_cast<Product::eType>(itype);

			Product* pProduct = new Product;
			pProduct->Read(ifile);
			products.push_back(pProduct);
		}
		ifile.close();
	}
}

void Products::Save(const std::string& filename)
{
	//write to file
	ofstream ofile(filename);
	if (ofile.is_open())
	{
		for (Product* product : products)
		{
			ofile << static_cast<int>(product->getType()) << endl;

			product->Write(ofile);

		}
		ofile.close();
	}
}

void Products::DisplayAll()
{
	//write to console
	for (Product* product : products)
	{
		product->Write(cout);
	}
}

void Products::Display(Product::eType type)
{

	for (Product* product : products)
	{
		if (product->getType() == type)
		{
			product->Write(cout);
		}
	}
}

void Products::Display(int id)
{
	for (Product* product : products)
	{
		if (product->getId() == id)
		{
			product->Write(cout);
		}
	}
}

Product* Products::Create(Product::eType type)
{
	Product* product = nullptr;

	switch (type)
	{
	case Product::eType::MOVIE:
		product = new Movie;
		break;
	case Product::eType::ALBUM:
		product = new Album;
		break;
	default:
		break;
	}

	return product;
}

void Products::Add(Product* product)
{
	products.push_back(product);
}

void Products::RemoveAll()
{
	for (Product* product : products)
	{
		delete product;
	}

	products.clear();
}

void Products::Remove(int id)
{
	for (list<Product*>::iterator iter = products.begin(); iter != products.end(); iter++)
	{
		if ((*iter)->getId() == id)
		{
			delete* iter;
			iter = products.erase(iter);
		}
	}
}
