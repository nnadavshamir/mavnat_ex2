#include <iostream>
#include <string>
#include "Manager.h"
#include <sstream>

using namespace std;

void assertNotEmpty(Manager manager) 
{
	if (manager.IsEmpty())
	{
		throw "Invalid! requested operation cannot be executed when empty";
	}
}

int main()
{
	int numOfInstructions;
	Manager manager = Manager();
	cin >> numOfInstructions;

	if (numOfInstructions <= 0)
	{
		throw  "First input must be a positive integer";
	}

	string command;
	char instructionType;
	for (int i = 0; i < numOfInstructions; i++)
	{
		getline(cin, command);
		instructionType = command[0];

		if (i == 0 && instructionType != 'e')
		{
			throw "e command must be executed before any other command";
		}

		if (i != 0 && instructionType == 'e')
		{
			throw "e command can be executed only once";
		}


		if (instructionType == 'a')
		{
			assertNotEmpty(manager);
			manager.Max();
		}
		else if (instructionType == 'b')
		{
			assertNotEmpty(manager);
			manager.DeleteMax();
		}
		else if (instructionType == 'c')
		{
			assertNotEmpty(manager);
			manager.Min();
		}
		else if (instructionType == 'd')
		{
			assertNotEmpty(manager);
			manager.DeleteMin();
		}
		else if (instructionType == 'e')
		{
			manager.MakeEmpty();
		}
		else if (instructionType == 'f')
		{
			istringstream iss(command);
			char type;
			int priority;
			string data;
			iss >> type >> priority;
			getline(iss >> ws, data);

			manager.Insert(priority, data);
		}
		else if (instructionType == 'g')
		{
			assertNotEmpty(manager);
			manager.Median();
		}
		else {
			throw "Invalid Command! make sure you start with one of [a-g] letters";
		}
	}

	return 0;
}