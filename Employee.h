#pragma once
#include<string>
#include<fstream>
#include<stdexcept>
#include <limits>
using namespace std;
class Employee {
private:
	int EmployeeNumber;
	string Name;
	string Addr;
	string Phone;
	double HourlyWage;
	double HoursWorked;
public:
	Employee(int EmployeeNumber, string Name, string Addr, string Phone, double HourlyWage, double HoursWorked);

	Employee(ifstream& in);

	void write(ofstream& out);

	int getEmployeeNumber() const;
	const string& getName() const;
	const string& getAddr() const;
	const string& getPhone() const;
	double getHourlyWage() const;
	double getHoursWorked() const;

	void setName(const string& name);
	void setAddr(const string& address);
	void setPhone(const string& phone);
	void setHourlyWage(double wage);
	void setHoursWorked(double hours);

	double calcPay() const;

	void printCheck()const;

};

