#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Inventory
{
	public:
		Inventory();
		void outputInventory();
	private:
		string item;
};

Inventory::Inventory()
{
	item = "";
}

void Inventory::outputInventory()
{
	cout<<"Items in Inventory:"<<endl;

	ifstream fin("inventory.txt", ios::in);
	//string temp;
	while (getline(fin, item, '\n')) {
		cout << "  - " << item << endl;
	}
	fin.close();
}