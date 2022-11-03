#include "Film.h"

Film::Film() {
	this->typeof[0] = "Hanh dong";
	this->typeof[1] = "Tinh cam";
	this->typeof[2] = "Phieu Luu";
	this->typeof[3] = "Hoat hinh";
	this->typeof[4] = "Lang man";
	this->typeof[5] = "Phim 18+";
	this->typeof[6] = "Hai huoc";
	this->typeof[7] = "Co trang";
	this->typeof[8] = "Tam Ly";
	this->typeof[9] = "Anime";
	this->typeof[10] = "Chien tranh";
	this->typeof[11] = "The thao";
	this->typeof[12] = "Ky su";
	this->typeof[13] = "Chinh kich";
	this->typeof[14] = "Ma - Kinh di";
	this->typeof[15] = "Vo thuat";
	this->typeof[16] = "Vien Tuong";
	this->typeof[17] = "Khoa hoc";
	this->typeof[18] = "Than Loai";
	this->typeof[19] = "Am nhac";
}

Film::Film(string& id, string& name, string& director, string& actor, string& country, string& type, int length) {
	this->id = id;
	this->name = name;
	this->director = director;
	this->actor = actor;
	this->country = country;
	this->type = type;
	this->length = length;
	this->typeof[0] = "Hanh dong";
	this->typeof[1] = "Tinh cam";
	this->typeof[2] = "Phieu Luu";
	this->typeof[3] = "Hoat hinh";
	this->typeof[4] = "Lang man";
	this->typeof[5] = "Phim 18+";
	this->typeof[6] = "Hai huoc";
	this->typeof[7] = "Co trang";
	this->typeof[8] = "Tam Ly";
	this->typeof[9] = "Anime";
	this->typeof[10] = "Chien tranh";
	this->typeof[11] = "The thao";
	this->typeof[12] = "Ky su";
	this->typeof[13] = "Chinh kich";
	this->typeof[14] = "Ma - Kinh di";
	this->typeof[15] = "Vo thuat";
	this->typeof[16] = "Vien Tuong";
	this->typeof[17] = "Khoa hoc";
	this->typeof[18] = "Than Loai";
	this->typeof[19] = "Am nhac";
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

string* Film::getTypeof() {
	return this->typeof;
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
