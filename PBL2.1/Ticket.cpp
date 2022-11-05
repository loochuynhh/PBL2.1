#include "Ticket.h"

string Ticket::getId() const {
	return this->id;
}

string Ticket::getScheduleId() const {
	return this->scheduleId;
}

string Ticket::getCustomerName() const {
	return this->customerName;
}

string Ticket::getCustomerPhone() const {
	return this->customerPhone;
}

string Ticket::getStaffId() const {
	return this->staffId;
}

int Ticket::getCost() const {
	return this->cost;
}

int Ticket::getAmount() {
	return this->amount;
}

int Ticket::getSoda_Corn() {
	return this->soda_corn;
}

void Ticket::setId(const string& id) {
	this->id = id;
}

void Ticket::setScheduleId(const string& id) {
	this->scheduleId = id;
}

void Ticket::setCustomerName(const string& name) {
	this->customerName = name;
}

void Ticket::setCustomerPhone(const string& phone) {
	this->customerPhone = phone;
}

void Ticket::setStaffId(const string& id) {
	this->staffId = id;
}

void Ticket::setCost(int cost) {
	this->cost = cost;
}

void Ticket::setAmount(int amount) {
	this->amount = amount;
}

void Ticket::setSoda_Corn(int soda_corn) {
	this->soda_corn = soda_corn;
}

void Ticket::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, scheduleid, customername, customerphone, staffid;
	int cost, amount, soda_corn;
	getline(filein, id, ',');
	this->setId(id);
	filein.ignore(1);
	getline(filein, scheduleid, ',');
	this->setScheduleId(scheduleid);
	filein.ignore(1);
	getline(filein, customername, ',');
	this->setCustomerName(customername);
	filein.ignore(1);
	getline(filein, customerphone, ',');
	this->setCustomerPhone(customerphone);
	filein.ignore(1);
	getline(filein, staffid, ',');
	this->setStaffId(staffid);
	filein.ignore(1);
	filein >> cost;
	this->setCost(cost);
	filein.ignore(1);
	filein >> amount;
	this->setAmount(amount);
	filein.ignore(1);
	filein >> soda_corn;
	this->setSoda_Corn(soda_corn);
}
void Ticket::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getScheduleId() << ", ";
	fileout << this->getCustomerName() << ", ";
	fileout << this->getCustomerPhone() << ", ";
	fileout << this->getStaffId() << ", ";
	fileout << this->getCost() << ", ";
	fileout << this->getAmount() << ", ";
	fileout << this->getSoda_Corn() << ".";
	fileout << "\n";
}
void Ticket::writeData() {
	cout << "|";
	cout << "    " << left << setw(10) << this->getId() << "|";
	cout << "    " << left << setw(13) << this->getScheduleId() << "|";
	cout << "    " << left << setw(10) << this->getStaffId() << "|";
	cout << "   " << left << setw(15) << this->getCustomerPhone() << "|";
	cout << "   " << left << setw(31) << this->getCustomerName() << "|";
	cout << "  " << left << setw(6) << this->getCost() << "|";
	cout << "   " << left << setw(4) << this->getAmount() << "|";
	cout << "    " << left << setw(6) << this->getSoda_Corn() << "|\n";
}