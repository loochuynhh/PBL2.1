#pragma once
#include "Manager.h"
#include "Staff.h"

class DirectorManager : public Manager<Director>
{
public:
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
protected:
};