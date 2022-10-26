#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Director {
private:
	string ID;
	string Name;
	string Account;
	string Password;
public:
	// set function
	void setId(string);
	void setName(string);
	void setAccount(string);
	void setPassword(string);
	// get function
	string getId();
	string getName();
	string getAccount();
	string getPassword();

	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
};