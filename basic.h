#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Int to String
string int_to_string (int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}
// String to Int
int string_to_int(string s)
{
   istringstream strm;
   strm.str(s);
   int n=0;
   strm >> n;
   return n;
}
// String Prompt
string string_prompt()
{
	// It will return a string, including spaces, 
	// punctuation, numbers, and letters.
	cout << ">> ";
	string answer;
	getline(cin, answer);
	return answer;
}
// Integer Prompt (1-3 choices)
string integer_prompt(int number_of_choices)
{
	// Enter the number of choices, and it will return the user_inputted 
	// answer after checking if it is a valid choice
	cout << ">> ";
	string answer;
	getline(cin, answer);
	if(number_of_choices == 1)
	{
		while(answer != "1")
		{
			cout << "Please enter a valid response." << endl;
			cout << ">> ";
			getline(cin, answer);
		}
		return answer;
	}
	if(number_of_choices == 2)
	{
		while(answer != "1" && answer != "2")
		{
			cout << "Please enter a valid response." << endl;
			cout << ">> ";
			getline(cin, answer);
		}
		return answer;
	}
	if(number_of_choices == 3)
	{
		while(answer != "1" && answer != "2" && answer != "3")
		{
			cout << "Please enter a valid response." << endl;
			cout << ">> ";
			getline(cin, answer);
		}
		return answer;
	}
}
// Basic File Reader
string file_reader(string filename)
{
	// Enter the name or location of the file and
	// it will save the contents into a string.
	string name = filename + ".txt";
	string contents;
	fstream file;
	file.open(name.c_str());
	getline(file, contents);
	file.close();
	return contents;
}
// Returns the time elapsed since last login
int elapsed_time(string player_name)
{
	fstream time_stream;
	string filename = player_name + "_savefile.txt";
	time_stream.open(filename.c_str());
	int old_time;
	if(time_stream >> old_time); // Read from the file
	time_stream.clear();
	time_stream.seekg(0, ios::beg);
	int new_time = time(0);
	time_stream << new_time << endl; // Write to the file
	int elapsed_time = new_time - old_time;
	return elapsed_time;
}