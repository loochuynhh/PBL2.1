#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Film
{
public:
	string getId() const;
	string getName() const;
	string getDirector() const;
	string getCountry() const;
	string getType() const;
	string getActor() const;
	int getLength() const;
	void setName(const string&);
	void setId(const string&);
	void setDirector(const string&);
	void setActor(const string&);
	void setCountry(const string&);
	void setType(const string&);
	void setLength(int);
	Film();
	Film(string&, string&, string&, string&, string&, string&, int);
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	string name;
	string director;
	string actor;
	string country;
	string type;
	int length;
};

#endif
