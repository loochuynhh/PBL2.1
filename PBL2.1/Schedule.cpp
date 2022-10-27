#include "Schedule.h"

string Schedule::getId() const {
	return this->id;
}

string Schedule::getFilmId() const {
	return this->filmId;
}

string Schedule::getCinemaRoomId() const {
	return this->cinemaRoomId;
}

int Schedule::getShow() const {
	return this->show;
}

Time Schedule::getTime() const {
	return this->time;
}

void Schedule::setId(const string& id) {
	this->id = id;
}

void Schedule::setFilmId(const string& filmId) {
	this->filmId = filmId;
}

void Schedule::setShow(const int& period) {
	this->show = period;
}

void Schedule::setCinemaRoomId(const string& id) {
	this->cinemaRoomId = id;
}

void Schedule::setTime(const Time& Day) {
	this->time = Day;
}

void Schedule::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, filmid, cnmrid;
	int show;
	Time time;
	getline(filein, id, ',');
	this->setId(id);
	filein.ignore(1);
	getline(filein, filmid, ',');
	this->setFilmId(filmid);
	filein.ignore(1);
	getline(filein, cnmrid, ',');
	this->setCinemaRoomId(cnmrid);
	filein.ignore(1);
	filein >> show;
	this->setShow(show);
	filein.ignore(1);
	this->time.readfilet(filein);
}
void Schedule::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getFilmId() << ", ";
	fileout << this->getCinemaRoomId() << ", ";
	fileout << this->getShow() << ", ";
	this->time.writefilet(fileout);
	fileout << "\n";
}
void Schedule::writeData() {
	cout << "|";
	cout << "   " << left << setw(14) << this->getId() << "|";
	cout << "   " << left << setw(10) << this->getFilmId() << "|";
	cout << "    " << left << setw(14) << this->getCinemaRoomId() << "|";
	cout << "  " << left << setw(4) << this->getShow() << "|";
	cout << "     ";
	this->getTime().writet();
	cout << "     |\n";
}