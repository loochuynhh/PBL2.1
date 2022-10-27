#pragma once
#include "Manager.h"
#include "Staff.h"

class DirectorManager : public Manager<Director>
{
public:
	void updateAc();
	void updatePq();
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
protected:
};