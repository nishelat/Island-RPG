#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Master hub function
void load_hub(string hub_code, string player_name)
{
	bool quit = false;
	while(!quit)
	{
		system("cls");
		string filename = hub_code + "_hub";
		cout << endl << file_reader(filename) << endl;
		
		int seconds = elapsed_time(player_name);
		int minutes = seconds / 60;
		int hours = minutes / 60;
		minutes = minutes - (hours * 60);
		cout << endl << "It has been " << hours;
		if(hours == 1)
		{
			cout << " hour and ";
		}
		else
		{
			cout << " hours and ";
		}
		cout << minutes;
		if(minutes == 1)
		{
			cout << " minute since you last logged in." << endl;
		}
		else
		{
			cout << " minutes since you last logged in." << endl;
		}
	
		cout << endl << "What do you want to do?" << endl << "1. Go fight a zombie" << endl << "2. Save and quit" << endl << endl;
		string answer = integer_prompt(2);
		if(answer == "1")
		{
			combat("zombie", 50, 5, 5);
		}
		if(answer == "2")
		{
			system("cls");
			exit(1);
			return;
		}
	}
}