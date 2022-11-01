#pragma once
#include "Manager.h"
#include "Staff.h"

class StaffManager : public Manager<Staff>
{
public:
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
	void writerl();
	void update();
	Staff setStaff();
	void readSalaryFile(fstream&);
	void writeSalaryFile(fstream&);
	void writeSalaryY(int);
	void addSalary();
protected:
};

