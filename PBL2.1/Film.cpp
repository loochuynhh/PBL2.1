#include "Film.h"

Film::Film() {
}

Film::Film(string& id, string& name, string& director, string& actor, string& country, string& type, int length) {
	this->id = id;
	this->name = name;
	this->director = director;
	this->actor = actor;
	this->country = country;
	this->type = type;
	this->length = length;
}
string Film::getId() const {
	return this->id;
}

string Film::getName() const {
	return this->name;
}

string Film::getDirector() const {
	return this->director;
}

string Film::getCountry() const {
	return this->country;
}

string Film::getType() const {
	return this->type;
}

string Film::getActor() const {
	return this->actor;
}

int Film::getLength() const {
	return this->length;
}

void Film::setId(const string& id) {
	this->id = id;
}

void Film::setName(const string& name) {
	this->name = name;
}

void Film::setDirector(const string& director) {
	this->director = director;
}

void Film::setActor(const string& actor) {
	this->actor = actor;
}

void Film::setCountry(const string& country) {
	this->country = country;
}

void Film::setType(const string& type) {
	this->type = type;
}

void Film::setLength(int length) {
	this->length = length;
}
void Film::readDataFile(fstream& filein) {
    filein.ignore(20, 10);
    string id, name, director, actor, country, type;
	getline(filein, id, ',');
	this->setId(id);
	filein.ignore(1);
	getline(filein, name, ',');
	this->setName(name);
	filein.ignore(1);
	getline(filein, director, ',');
	this->setDirector(director);
	filein.ignore(1);
	getline(filein, actor, ',');
	this->setActor(actor);
	filein.ignore(1);
	getline(filein, country, ',');
	this->setCountry(country);
	filein.ignore(1);
	getline(filein, type, ',');
	this->setType(type);
	int length;
	filein >> length;
	this->setLength(length);
}
void Film::writeDataFile(fstream& fileout) {
    fileout << this->getId() << ", ";
    fileout << this->getName() << ", ";
    fileout << this->getDirector() << ", ";
    fileout << this->getActor() << ", ";
    fileout << this->getCountry() << ", ";
	fileout << this->getType() << ", ";
	fileout << this->getLength() << ". ";
    fileout << "\n";
}
void Film::writeData() {
	cout << "|" << left << setw(4) << " ";
    cout << left << setw(9) << this->getId() << "|";
	cout << left << setw(4) << " ";
    cout << left << setw(27) << this->getName() << "|";
	cout << left << setw(3) << " ";
	cout << left << setw(17) << this->getDirector() << "|";
	cout << left << setw(4) << " ";
	cout << left << setw(19) << this->getActor() << "|";
	cout << left << setw(4) << " ";
	cout << left << setw(16) << this->getCountry() << "|";
	cout << left << setw(7) << " ";
	cout << left << setw(19) << this->getType() << "|";
	cout << left << setw(5) << " ";
	cout << left << setw(10) << this->getLength() << "|";
    cout << "\n";
}
