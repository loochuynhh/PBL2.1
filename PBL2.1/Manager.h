#pragma once
#include <iostream>
#include <string.h>
#include "Schedule.h"
#include "Ticket.h"
#include "CinemaRoom.h"
#include "Film.h"
#include "Director.h"
#include "Staff.h"
#include <fstream>

using namespace std;

template <class type>

class Manager
{
public:
	void add(const type&);
	void del(const string&);
	type* findById(const string&);
	int getLength();
	void setLength(int);
	Manager();
	~Manager();
	type* getTypeList();
	virtual void readFile(fstream&);
	virtual void writeFile(fstream&);
	virtual void write();
protected:
	type* typeList;
	int length;
};

