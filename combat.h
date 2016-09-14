#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Analyzes Opponent Stats
void opponent_analyzer(string opponent_name, int &opponent_health, int &opponent_chance, int &opponent_min_damage, int &opponent_max_damage, string &description, string &good, string &okay, string &bad, string&death)
{
	string placeholder;
	string name = opponent_name + "_opponent" + ".txt";
	fstream file;
	file.open(name.c_str());
	getline(file, placeholder);
	opponent_health = string_to_int(placeholder);
	getline(file, placeholder);
	opponent_chance = string_to_int(placeholder);
	getline(file, placeholder);
	opponent_min_damage = string_to_int(placeholder);
	getline(file, placeholder);
	opponent_max_damage = string_to_int(placeholder);
	getline(file, description);
	getline(file, good);
	getline(file, bad);
	getline(file, okay);
	getline(file, death);
	file.close();
}

// Offensive Simulator
void offensive_simulator(int &opponent_health, int your_chance, int player_min_damage, int player_max_damage, string good, string okay, string bad, string death)
{
	int hit_or_miss = rand() % 101;
	if(hit_or_miss <= your_chance)
	{
		int damage_done = rand() % (player_max_damage - player_min_damage + 1) + player_min_damage;
		cout << endl << "You do " << damage_done << " damage!" << endl;
		opponent_health -= damage_done;
		if(opponent_health <= 0)
		{
			cout << death << endl;
			
		}
		else
		{
			if(damage_done >= 0 && damage_done < 10)
			{
				cout << good << endl;
			}
			else if(damage_done >= 10 && damage_done < 20)
			{
				cout << okay << endl;
			}
			else if(damage_done >= 20 && damage_done <= 25)
			{
				cout << bad << endl;
			}
		}
	}
	else
	{
		cout << endl << "MISS!" << endl;
		cout << good << endl;
	}
}

// Defensive Simulator
void defensive_simulator(string opponent_name, int &player_health, int their_chance, int opponent_min_damage, int opponent_max_damage)
{
	int hit_or_miss = rand() % 101;
	if(hit_or_miss <= their_chance)
	{
		int damage_done = rand() % (opponent_max_damage - opponent_min_damage + 1) + opponent_min_damage;
		cout << "The " << opponent_name << " does " << damage_done << " damage!" << endl;
		player_health -= damage_done;
		if(player_health <= 0)
		{
			player_health = 0;
		}
	}
	else
	{
		cout << "The " << opponent_name << " attacks and misses!" << endl;
	}
}

// Executes a Round
bool execute_round(string opponent_name, int &player_health, int player_strength, int player_agility, int &opponent_health, int opponent_chance, int opponent_min_damage, int opponent_max_damage, string description, string good, string okay, string bad, string death, int player_max_health)
{
	int your_chance = 80 + player_agility;
	int their_chance = opponent_chance - player_agility;
	int player_min_damage = 1;
	int player_max_damage = 5 + player_strength;
	cout << endl << setw(27) << "Your health: " << player_health << setw(27) << "Enemy health: " << opponent_health << endl << endl;
	cout << "What do you do?" << endl;
	cout << "1. Attack (Chance of hitting is " << your_chance << "%)" << endl << "2. Recover your health" << endl << "3. Try to run away" << endl;
	string response = integer_prompt(3);
	system("cls");
	if(response == "1")
	{
		offensive_simulator(opponent_health, your_chance, player_min_damage, player_max_damage, good, okay, bad, death);
		if(opponent_health > 0)
		{
			defensive_simulator(opponent_name, player_health, their_chance, opponent_min_damage, opponent_max_damage);
		}
	}
	else if(response == "2")
	{
		if(player_health > player_max_health - 5)
		{
			cout << endl << "Your health is too full to recover!" << endl;
			execute_round(opponent_name, player_health, player_strength, player_agility, opponent_health, opponent_chance, opponent_min_damage, opponent_max_damage, description, good, okay, bad, death, player_max_health);
			return false;
		}
		cout << endl << "You sacrifice your turn to attack and recover 5 health!" << endl;
		player_health += 5;
		defensive_simulator(opponent_name, player_health, their_chance, opponent_min_damage, opponent_max_damage);
	}
	else if(response == "3")
	{
		int flee = rand() % 101;
		if(flee < 10)
		{
			opponent_health = 0;
			return true;
		}
		else
		{
			cout << endl << "You fail to escape your enemy!" << endl;
			defensive_simulator(opponent_name, player_health, their_chance, opponent_min_damage, opponent_max_damage);
		}
	}
}
// Master combat function
void combat(string opponent_name, int player_health, int player_strength, int player_agility)
{
	system("color 0c");
	system("cls");
	bool flee = false;
	int opponent_health, opponent_chance, opponent_min_damage, opponent_max_damage, player_max_health;
	string description, good, okay, bad, death;
	opponent_analyzer(opponent_name, opponent_health, opponent_chance, opponent_min_damage, opponent_max_damage, description, good, okay, bad, death);
	player_max_health = player_health;
	cout << endl << description << endl;
	while(player_health > 0 && opponent_health > 0)
	{
		flee = execute_round(opponent_name, player_health, player_strength, player_agility, opponent_health, opponent_chance, opponent_min_damage, opponent_max_damage, description, good, okay, bad, death, player_max_health);
	}
	// ADD A MONEY SYSTEM
	if(player_health <= 0)
	{
		cout << endl << "You lost! Utterly defeated, you black out..." << endl << "Upon waking, you notice you have lost xxx gold." << endl;
	}
	else if(flee)
	{
		cout << endl << "You successfully escape your enemy!" << endl;
	}
	else if(opponent_health <= 0)
	{
		cout << endl << "You won! You find xxx gold." << endl;
	}
	cout << "Your health has been restored to full." << endl;
	cout << "Press any key to continue!" << endl << endl;
	system("color 0B");
	getch();
}
