#ifndef CINEMAROOM_H
#define CINEMAROOM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class CinemaRoom
{
public:
	string getId();
	int getChairs();
	string getStatus();
	void setId(const string&);
	void setChairs(int);
	void setStatus(const string&);
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	int chairs;
	string status;
};

#endif
