#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Type.h"

using namespace std;

class Film
{
public:
	string* getAllType();
	string getId() const;
	string getName() const;
	string getDirector() const;
	string getCountry() const;
	int getType() const;
	string getActor() const;
	int getLength() const;
	void setName(const string&);
	void setId(const string&);
	void setDirector(const string&);
	void setActor(const string&);
	void setCountry(const string&);
	void setType(int);
	void setLength(int);
	Film();
	Film(string&, string&, string&, string&, string&, int, int);
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	string name;
	string director;
	string actor;
	string country;
	int type;
	int length;
	Type allType;
};

#endif
