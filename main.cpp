#include <iostream>
#include <fstream>
#include "employee.h"
using namespace std;

int main()
{
	//Show user the menu options and get input
	cout << "This program has two options:" << endl;
	cout << "1 - Create a data file, or" << endl;
	cout << "2 - Read data from a file and print paychecks." << endl;
	cout << "Please enter (1) to create a file or (2) to print checks :" << endl;

	int option = -1;
	cin >> option;
	cin.clear();
	cin.ignore(1024, '\n');

	//Option 1: Write to a file
	if (option == 1)
	{
		//Prompt for a file name and create employees
		string fileName;
		cout << "Please enter a file name: " << endl;
		getline(cin, fileName);

		Employee joe(37, "Joe Brown", "123 Main St.", "123-6788", 10.00, 45.00);
		Employee sam(21, "Sam Jones", "45 East State", "661-9000", 12.00, 30.00);
		Employee mary(15, "Mary Smith", "12 High Street", "401-8900", 15.00, 40.00);

		//Write employees to a file
		try
		{
		
			ofstream file;
			file.open(fileName);
			joe.write(file);
			sam.write(file);
			mary.write(file);
			
			cout << "Data file created ... you can now run option 2." << endl << endl;
		}
		catch (runtime_error & e)
		{
			cout << e.what() << endl;
		}
	}
	//Option 2: Read from a file
	else if (option == 2)
	{
		//Prompt for a file name
		string fileName;
		cout << "Please enter a file name: " << endl;
		getline(cin, fileName);

		//Read employees from a file (assumes 3 employees)
		try
		{
			ifstream file;
			file.open(fileName);
			if (file.fail()) {
				cout << "Couldn't open file for input" << endl;
			}
			else {
				Employee temp(file);
				temp.printCheck();
				Employee temp2(file);
				temp2.printCheck();
				Employee temp3(file);
				temp3.printCheck();
			}
			
		}
		catch (runtime_error & e)
		{
			cout << e.what() << endl;
		}
	}
	//Invalid option
	else
	{
		cout << "Invalid menu input" << endl;
	}

	return 0;
}
