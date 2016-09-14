// RPG

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#include "basic.h"
#include "combat.h"
#include "hub.h"
#include "menu.h"

using namespace std;

int main()
{
	system("color 0B");
	main_menu();
	
	srand(time(0));
	system("PAUSE");
	return 0;
}