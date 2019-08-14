#include "employee.h"
#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;


// declare define the contructor
Employee::Employee(int EmployeeNumber, string Name, string Addr, string Phone, double HourlyWage, double HoursWorked)
{
	// this refer to the calling oabject
	this->EmployeeNumber = EmployeeNumber;
	this->Name = Name;
	this->Addr = Addr;
	this->Phone = Phone;
	this->HourlyWage = HourlyWage;
	this->HoursWorked = HoursWorked;


}
Employee::Employee(ifstream& in) {
   string temp;
	getline(in,temp);
	try {
	EmployeeNumber =stoi(temp);
	}
	catch(invalid_argument & e) {
	 throw runtime_error("Bad employee number");
	}
	
	getline(in, temp);
	Name = temp;
	if (!in) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Bad name");
	}
	getline(in, temp);
	Addr = temp;
	if (!in) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Bad address");
	}
	getline(in, temp);
	Phone = temp;
	if (!in) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Bad phone number");
	}
	getline(in, temp);
	try {
	HourlyWage =stod(temp);
	}
	catch(invalid_argument & e) {
	 throw runtime_error("Bad hourly wage");
	}
	
	getline(in, temp);
	try {
	HoursWorked =stod(temp);
	}
	catch(invalid_argument & e) {
	 throw runtime_error("Bad hours worked");
	}

}
// pulling variables from the .h class Employee to the .cpp file 

void Employee::write(ofstream& out) {
	out << EmployeeNumber << endl;
	out << Name << endl;
	out << Addr << endl;
	out << Phone << endl;
	out << HourlyWage << endl;
	out << HoursWorked << endl;
}
int Employee::getEmployeeNumber()const {
	return EmployeeNumber;
}
const string& Employee::getName() const {
	return Name;
}
const string& Employee::getAddr() const {
	return Addr;
}
const string& Employee::getPhone() const {
	return Phone;
}
double Employee::getHourlyWage() const {
	return HourlyWage;
}
double Employee::getHoursWorked() const {
	return HoursWorked;
}
void Employee::setName(const string& name) {
	Name = name;
}
void Employee::setAddr(const string& address) {
	Addr = address;
}
void Employee::setPhone(const string& phone) {
	Phone = phone;
}
void Employee::setHourlyWage(double wage) {
	HourlyWage = wage;
}
void Employee::setHoursWorked(double hours) {
	HoursWorked = hours;
}
// defining calcPay that was declared in the .h file
double Employee::calcPay()const {
	double grosPay;
	double netPay;
	double hrs_Worked = getHoursWorked();
	double hrly_wage = getHourlyWage();


	if (hrs_Worked > 40) {
		grosPay = hrly_wage * (40 + 1.5 * (hrs_Worked - 40));
		netPay = 0.725 * grosPay;
	}
	else if (hrs_Worked <= 40) {
		grosPay = hrly_wage * hrs_Worked;
		netPay = 0.725 * grosPay;

	}
	return netPay;
}
void Employee::printCheck() const {
	cout << "....................UVU Computer Science Dept................................." << endl << endl;
	cout << fixed;
	cout << "Pay to the order of " << getName() << "....................................$" << setprecision(2) << calcPay() << endl << endl;
	cout << "United Community Credit Union" << endl << endl;
	cout << ".............................................................................." << endl << endl << endl;
	cout << "Hourly wage: " << getHourlyWage() << endl;
	cout << "Hours worked: " << getHoursWorked() << endl;
}
