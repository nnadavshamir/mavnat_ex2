#include <iostream>
#include <string>
#include "Manager.h"
#include <sstream>

using namespace std;

bool assertNotEmpty(Manager& manager) 
{
	if (manager.IsEmpty())
	{
		cout << "wrong input" << endl;
		return true;
	}

	return false;
}

int main()
{
	int numOfInstructions;
	Manager manager = Manager();
	cin >> numOfInstructions;

	if (numOfInstructions <= 0)
	{
		cout << "wrong input" << endl;
		return 0;
	}

	string command;
	char instructionType;
	for (int i = 0; i < numOfInstructions; i++)
	{
		getline(cin >> ws, command);
		instructionType = command[0];

		if (i == 0 && instructionType != 'e')
		{
			cout << "wrong input" << endl;
			return 0;
		}

		if (i != 0 && instructionType == 'e')
		{
			cout << "wrong input" << endl;
			return 0;
		}


		if (instructionType == 'a')
		{
			if(assertNotEmpty(manager))
				return 0;
			manager.Max();
		}
		else if (instructionType == 'b')
		{
			if (assertNotEmpty(manager))
				return 0;
			manager.DeleteMax();
		}
		else if (instructionType == 'c')
		{
			if (assertNotEmpty(manager))
				return 0;
			manager.Min();
		}
		else if (instructionType == 'd')
		{
			if (assertNotEmpty(manager))
				return 0;
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

			if (iss.fail())
			{
				cout << "wrong input" << endl;
				return 0;
			}
			manager.Insert(priority, data);
		}
		else if (instructionType == 'g')
		{
			assertNotEmpty(manager);
			manager.Median();
		}
		else {
			cout << "wrong input" << endl;
			return 0;
		}
	}


	getline(cin, command);
	if (command != "")
	{
		cout << "wrong input" << endl;
	}

	return 0;
}