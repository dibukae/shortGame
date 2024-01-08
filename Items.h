#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Items//I removed the inheritance stuff because I couldn't figure out how to code some stuff
{
	public:
		//adds item to inventory.txt
		void addItem(string);
		//deletes the line that had the item in inventory
		void useItem(string chosenItem);
};

void Items::addItem(string theItem)
{
	ofstream fout("inventory.txt", ios::app);
	fout<<endl<< theItem;
	fout.close();

	/*Inventory inv;
	  inv.addItem("Key");
	  
	  Items pItem("Key")*/
}



void Items::useItem(string chosenItem)
{
	ifstream fin("inventory.txt", ios::in);
	ofstream fout("temp.txt", ios::out);
	string line;

	while (getline(fin, line))
	{
		if (line != chosenItem)
		{
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	remove("inventory.txt");
	rename("temp.txt", "inventory.txt");
}
