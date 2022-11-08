#include "CinemaRoom.h"

string CinemaRoom::getId() {
	return this->id;
}

int CinemaRoom::getChairs() {
	return this->chairs;
}

string CinemaRoom::getStatus() {
	return this->status;
}

void CinemaRoom::setId(const string& id) {
	this->id = id;
}

void CinemaRoom::setChairs(int chairs) {
	this->chairs = chairs;
}

void CinemaRoom::setStatus(const string& status) {
	this->status = status;
}

void CinemaRoom::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, status;
	int chairs;
	getline(filein, id, ',');
	this->setId(id);
	filein >> chairs;
	this->setChairs(chairs);
	filein.ignore(20, 32);
	getline(filein, status, '.');
	this->setStatus(status);
}
void CinemaRoom::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getChairs() << ", ";
	fileout << this->getStatus() << ". ";
	fileout << "\n";
}
void CinemaRoom::writeData() {
	cout << "|";
	cout << left << setw(10) << " " << left << setw(8) << this->getId() << left << setw(8) << " " << "|";
	cout << left << setw(5) << " " << left << setw(8) << this->chairs << "|";
	cout << left << setw(15) << " " << left << setw(20) << this->getStatus() << "|";
	cout << "\n";
}