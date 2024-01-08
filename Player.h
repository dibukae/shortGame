#pragma once
#include <iostream>
#include "Items.h"
#include "Inventory.h"
using namespace std;

class Player
{
	private:
		string currentMap;
	public:
		Player();
		void movePlayer(int);
		string getMap();

		void addItems(string);
		bool itemInFile(const string& targetItem);
		void combineItems();
		void win();
};

Player::Player()
{
	currentMap = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|  @  +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";
}

//to move the player around the map
void Player::movePlayer(int choice)
{
	string item4 = "Key";
	string map1 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|  @  +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";
	string map2 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +@ +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";
	string map3 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|     @    _____     |\n         |         |___._|    |\n         |_.__________________|";
	string map4 = "          ____________________\n _____   |  @           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";
	string map5 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_@__________________|";
	string map6 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.___________@______|";
	string map7 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|          _____  @  |\n         |         |___._|    |\n         |_.__________________|";
	string map8 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |  @  |\n|     +  +   |_*_|      |__+__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";



	if (choice == 1)//north
	{
		if (currentMap == map1)
		{
		cout<< map1<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map1;
		}

		else if (currentMap == map2)
		{
		cout<<map2<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map3)
		{
		cout << map4 <<endl<<endl;
		cout<<"\tA bunch of tall grass..."<<endl;
		addItems("Rope(short)");
		currentMap = map4;
		}

		else if (currentMap == map4)
		{
		cout<< map4<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map4;
		}

		else if (currentMap == map5)
		{
		cout << map3 <<endl<<endl;
		cout<<"\tThere seems to be something down the well..."<<endl;
		//combineItems();
		currentMap = map3;
		}

		else if (currentMap == map6)
		{
			if (itemInFile(item4))
			{
				cout << map7 <<endl<<endl;
				cout<< "\tYou can now open the door..." <<endl;
				currentMap = map7;
			}
			
			else
			{
				cout << map7 <<endl<<endl;
				cout<< "\tIt's a door but it's locked..." <<endl;
				currentMap = map7;
			}
		}

		else if (currentMap == map7)
		{
			if (itemInFile(item4))
			{
				Items myItem;

				cout<< map8<< endl;
				cout<<endl<<"\tYou use the key and unlock the door."<<endl;
				myItem.useItem("Key");
				cout << "\tYou see a chest up ahead. You open the chest and find the Elegant Bangle."<< endl;
				addItems("Elegant Bangle");
				currentMap = map8;
			}

			else
			{
				cout<< map7<< endl;
				cout<<endl<<"\tThe door is locked..."<<endl;
				currentMap = map7;
			}
		}

		else if (currentMap == map8)
		{
		cout<< map8<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map8;
		}
	}

	else if (choice == 2)//south
	{
		if (currentMap == map1)
		{
		cout<< map1<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map1;
		}

		else if (currentMap == map2)
		{
		cout<< map2<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map3)
		{
		cout << map5 <<endl<<endl;
		cout<<"\tThere's a tree..."<<endl;
		addItems("Rope(long)");
		currentMap = map5;
		}

		else if (currentMap == map4)
		{
		cout<< map3<< endl;
		cout<<endl<< "\tThere seems to be something down the well..."<<endl;
		//combineItems();
		currentMap = map3;
		}

		else if (currentMap == map5)
		{
		cout<< map5<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map5;
		}

		else if (currentMap == map6)
		{
		cout<< map6<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map6;
		}

		else if (currentMap == map7)
		{
		cout << map6 <<endl<<endl;
		cout<<"\tIt's an empty grave..."<<endl;
		addItems("Magnet");
		currentMap = map6;
		}

		else if (currentMap == map8)
		{
		cout << map7 <<endl<<endl;
		cout << "Time to get back to the merchant" <<endl;
		currentMap = map7;
		}
	}

	else if (choice == 3)//east
	{
		if (currentMap == map1)
		{
		cout<<map2<<endl<<endl;
		cout<< "\tJust some crates..."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map2)
		{
		cout << map3 <<endl<<endl;
		cout<<"\tThere seems to be something down the well..."<<endl;
		//combineItems();
		currentMap = map3;
		}

		else if (currentMap == map3)
		{
		cout << map6 <<endl<<endl;
		cout<<"\tIt's an empty grave..."<<endl;
		addItems("Magnet");
		currentMap = map6;
		}

		else if (currentMap == map4)
		{
			if (itemInFile(item4))
			{
				cout << map7 <<endl<<endl;
				cout<< "\tYou can now open the door..." <<endl;
				currentMap = map7;
			}
			
			else
			{
				cout << map7 <<endl<<endl;
				cout<< "\tIt's a door but it's locked..." <<endl;
				currentMap = map7;
			}
		}

		else if (currentMap == map5)
		{
		cout << map6 <<endl<<endl;
		cout<<"\tIt's an empty grave..."<<endl;
		addItems("Magnet");
		currentMap = map6;
		}

		else if (currentMap == map6)
		{
		cout<< map6<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map6;
		}

		else if (currentMap == map7)
		{
		cout<< map7<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map7;
		}

		else if (currentMap == map8)
		{
		cout<< map8<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map8;
		}
	}

	else if (choice == 4)//west
	{
		if (currentMap == map1)
		{
		cout<< map1<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map1;
		}

		else if (currentMap == map2)
		{
		cout << map1 <<endl<<endl;
		cout<<"\tNothing here but the merchant..."<<endl;
		currentMap = map1;
		}

		else if (currentMap == map3)
		{
		cout << map2 <<endl<<endl;
		cout << "\tJust some crates..."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map4)
		{
		cout << map2 <<endl<<endl;
		cout << "\tJust some crates..."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map5)
		{
		cout << map2 <<endl<<endl;
		cout << "\tJust some crates..."<<endl;
		currentMap = map2;
		}

		else if (currentMap == map6)
		{
		cout << map3 <<endl<<endl;
		cout<<"\tThere seems to be something down the well..."<<endl;
		//combineItems();
		currentMap = map3;
		}

		else if (currentMap == map7)
		{
		cout << map3 <<endl<<endl;
		cout<<"\tThere seems to be something down the well..."<<endl;
		//combineItems();
		currentMap = map3;
		}

		else if (currentMap == map8)
		{
		cout<< map8<< endl;
		cout<<endl<<"\tThere's nothing there in that direction."<<endl;
		currentMap = map8;
		}
	}

}

string Player::getMap()
{
	return currentMap;
}

//to add items to inventory.txt
void Player::addItems(string item)
{
	Items myItem;

	string item1 = "Rope(short)";
	string item2 = "Rope(long)";
	string item3 = "Magnet";
	string item4 = "Key";
	string item5 = "Elegant Bangle";

	//if item is already in file
	if (itemInFile(item) == true)
	{
		cout << "You already took this item."<<endl;
	}

	else
	{
		cout<< "There's an item here..."<<endl;
		cout << "Take the "<< item<< "?" <<endl;
		string YorN;
		cout << "(Y)es or (N)o: ";
		cin >> YorN;

		if (YorN == "Y" || YorN == "y")
		{
			if (item == item1 || item == item2 || item == item3 || item == item4 || item == item5)
			{
				myItem.addItem(item);
				cout <<endl<< "\t+[Obtained " << item << "]+" << endl;
			}
		}
		else
		{
			cout << "You did not take the item..." << endl;
		}
	}
}

bool Player::itemInFile(const string& targetItem) {
	ifstream fin("inventory.txt");
	string line;

	while (getline(fin, line, '\n'))
	{
		if (line == targetItem)
		{
			fin.close();
			return true; //found the item in the file
		}
	}

	fin.close();
	return false; //item not found in the file
}

//if the items rope(long) and magnet are in the inventory and the current map is map3
void Player::combineItems()
{
	Inventory myInv;
	Items myItem;

	string item2 = "Rope(long)";
	string item3 = "Magnet";
	string item4 = "Key";
	string item5 = "Elegant Bangle";

	string map3 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|     +  +   |_*_|      |__=__|\n|_____|——|     @    _____     |\n         |         |___._|    |\n         |_.__________________|";

	if (!itemInFile(item4))
	{
		if (itemInFile(item2) && itemInFile(item3) && currentMap == map3)
		{
			cout << "Maybe you can combine some items in your inventory to get that key..." <<endl<<endl;
			myInv.outputInventory();

			cout<< endl<< "(please type the item name EXACTLY as you see in the list shown)"<<endl;
			cout << "Choose one item: ";
			string chosen1, chosen2;
			cin >> chosen1;
			cout << "Choose an item to combine with the first item you chose: ";
			cin >> chosen2;

			if (chosen1 == item2 && chosen2 == item3 || chosen1 == item3 && chosen2 == item2)
			{
				cout <<endl<< "\t[" << item2 << " and " << item3 << " combined]"<<endl;
				
				cout << "\tYou slowly lowered the magnet down the well\n\tYou hear something cling onto the magnet." <<endl<<endl;
				addItems("Key");
				myItem.useItem("Magnet");
				myItem.useItem("Rope(long)");
			}

			else
			{
				cout << "That doesn't seem right..." <<endl;
			}
		}
	}
	
	if (itemInFile(item4) || itemInFile(item5) && currentMap == map3)
	{
		cout<< endl<< "\tThe key you have might unlock something..."<<endl;
	}
}

//when the player obtains the elegant bangle and is at map1//put this on map1 in movePlayer?
void Player::win()
{
	Items myItem;

	string item5 = "Elegant Bangle";
	string map1 = "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|  @  +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|";

	if (itemInFile(item5) && currentMap == map1)
	{
		cout<<endl<<endl<<"Merchant: Got a request done and dusted eh?\nAh! I'll buy it at a high price!"<<endl<<endl;
		cout<<"You give the Elegant Bangle to the merchant..."<<endl<<endl;
		myItem.useItem(item5);
		cout<<"The merchant gave you 5,000 Pesetas!"<<endl<<endl;
		cout<<"\n\n\t\t\tYou have completed the game...\n\n\n";
		cout<< "You may now quit the game.";
	}
}