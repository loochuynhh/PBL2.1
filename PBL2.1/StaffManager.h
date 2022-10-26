#pragma once
#include "Manager.h"
#include "Staff.h"

class StaffManager : public Manager<Staff>
{
public:
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
protected:
};

