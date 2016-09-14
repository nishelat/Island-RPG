#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Creates a new account (put a 0 in the argument)
void create_account(int x)
{
	system("cls");
	if(x == 1)
	{
		cout << endl << "Sorry, that is an invalid account name. Either it already exists, or it contains one of the following characters: \\ / : * ? \" < > | " << endl;
	}
	// Ask for new name
	cout << endl << "What would you like your new character to be called?" << endl << endl;
	string player_name = string_prompt();
	// Check if account already exists
	string filename = player_name + "_savefile.txt";
	fstream test_stream;
	test_stream.open(filename.c_str());
	if(test_stream || player_name.find("\\") != string::npos || player_name.find("/") != string::npos || player_name.find(":") != string::npos || player_name.find("*") != string::npos || player_name.find("?") != string::npos || player_name.find("\"") != string::npos || player_name.find("<") != string::npos || player_name.find(">") != string::npos || player_name.find("|") != string::npos)
	{
		create_account(1);
		return;
	}
	test_stream.close();
	// Create a new file with the player name
	ofstream newfile;
	newfile.open(filename.c_str());
	newfile << time(0) << endl << "shore";
	newfile.close();
	
	// Display welcome message
	system("cls");
	cout << endl << "Welcome to the Island!" << endl;
	cout << endl << "You are the only survivor of a fatal shipwreck. After the ship went down, you blacked out, and have now awakened on the shore of a large and beautiful island." << endl;
	cout << endl << "It is now up to you to find food, fresh water, and shelter. Will you survive?" << endl << endl;
	cout << endl << "Your account has been created. Please select \"Load an existing game\" from the main menu to begin your adventure!" << endl;
	cout << endl << "1. Return to the main menu (press the number \"1\" on your keyboard)" << endl << endl;
	string answer = integer_prompt(1);
}

// Loads an existing account
void load_account(int x)
{
	system("cls");
	if(x == 1)
	{
		cout << endl << "Sorry, that account doesn't exist. Try again?" << endl;
	}
	cout << endl << "What is the name of your account?" << endl << endl;
	string player_name = string_prompt();
	string filename = player_name + "_savefile.txt";
	fstream stream;
	stream.open(filename.c_str());
	if(!stream)
	{
		load_account(1);
		return;
	}
	string hub_code;
	getline(stream, hub_code);
	getline(stream, hub_code);
	load_hub(hub_code, player_name);
}

// Main Menu
void main_menu()
{
	system("cls");
	cout << "V1.0";
	cout << endl << setw(27) << "THE ISLAND" << endl;
	cout << endl << setw(35) << "Developed by Nishir Shelat" << endl;
	cout << endl << "1. Create a new game" << endl;
	cout << "2. Load an existing game" << endl << endl;
	string answer = integer_prompt(2);
	if(answer == "1")
	{
		create_account(0);
		main_menu();
		return;
	}
	else if(answer == "2")
	{
		load_account(0);
	}
}