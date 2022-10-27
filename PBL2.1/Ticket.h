#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Ticket
{
public:
	string getId() const;
	string getScheduleId() const;
	string getCustomerName() const;
	string getCustomerPhone() const;
	string getStaffId() const;
	int getCost() const;
	void setId(const string&);
	void setScheduleId(const string&);
	void setCustomerName(const string&);
	void setCustomerPhone(const string&);
	void setStaffId(const string&);
	void setCost(int);
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	string scheduleId;
	string customerName;
	string customerPhone;
	string staffId;
	int cost;
};

#endif
