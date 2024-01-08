#include <iostream>
#include <fstream>
#include "Items.h"
#include "Inventory.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

int menu();

enum Choices{NORTH=1, SOUTH, EAST, WEST, QUIT};

int main()
{
	/* where's everyone going? bingo? */
	Player p;

	cout<<"Welcome to my game.\nHere is a key you may need for the map."<<endl;
	cout<<"\nKEY:\n'@' is you the player\n'*' means there is a special item\n'.' means there is an item\n'!!' is the merchant\n'=' means there is a locked door\n'+' means there is an open door\n'[-]' is the treasure chest\n\n\n";

	cout << "          ____________________\n _____   |  .           | [-] |\n|!!   |——|    ___       |     |\n|  @  +  +   |_*_|      |__=__|\n|_____|——|          _____     |\n         |         |___._|    |\n         |_.__________________|"<<endl;
	cout<< endl<< "Merchant: Hello stranger! I've gotta new request for ya.\nSomeone's lost their precious bangle and they're willing\nto pay a sizable price to get it back...\nI'll pay you double the price they're offering if you go\nget it now.\n\n\tObjective: Obtain Elegant Bangle and sell it to the Merchant."<<endl<<endl;

	int choice;
	do{
		choice = menu();
		switch(choice){
		case NORTH:
		p.movePlayer(NORTH);
		p.getMap();
		p.combineItems();
		p.win();
		break;

		case SOUTH:
		p.movePlayer(SOUTH);
		p.getMap();
		p.combineItems();
		p.win();
		break;

		case EAST:
		p.movePlayer(EAST);
		p.getMap();
		p.combineItems();
		p.win();
		break;

		case WEST:
		p.movePlayer(WEST);
		p.getMap();
		p.combineItems();
		p.win();
		break;
		}
	}while(choice != QUIT);

	cout<<endl<< "Goodbye...";

	return 0;
}

int menu(){
	int choice;
	cout << endl << "1. North"<< endl;
	cout << "2. South"<< endl;
	cout << "3. East"<< endl;
	cout << "4. West"<< endl;
	cout << "5. Quit"<< endl;
	cout << "Choose a number: ";
	cin >> choice;
	//cin.ignore();
	return choice;
}

