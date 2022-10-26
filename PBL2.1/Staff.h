#pragma once
#ifndef STAFF_H
#define STAFF_H
#include "Inforrl.h"
#include "Salary.h"
#include "Time.h"
#include <iomanip>

using namespace std;

class Staff
{
private:
	string id;
	string name;
	string job;
	string account;
	string password;
	Time timest;
	Infor inforst;
	Inforrl relative;
	Salary* stsalary;
public:
	void setId(string);
	string getId();
	void setName(string);
	string getName();
	void setJob(string);
	string getJob();
	void setAccount(string);
	string getAccount();
	void setPassword(string);
	string getPassword();
	void setTimeSt(Time);
	Time getTimeSt();
	void setInforSt(Infor);
	Infor getInforSt();
	void setRelative(Inforrl);
	Inforrl getRelative();
	void setStSalary(Salary*);
	Salary getStSalary();
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
};

#endif
