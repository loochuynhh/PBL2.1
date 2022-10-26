#include "Director.h"

void Director::setId(string ID) {
	this->ID = ID;
}
void Director::setName(string Name) {
	this->Name = Name;
}
void Director::setAccount(string Account) {
	this->Account = Account;
}
void Director::setPassword(string Password) {
	this->Password = Password;
}

string Director::getId() {
	return this->ID;
}
string Director::getName() {
	return this->Name;
}
string Director::getAccount() {
	return this->Account;
}
string Director::getPassword() {
	return this->Password;
}
void Director::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string ID, Name, Account, Password;
	getline(filein, ID, ',');
	this->setId(ID);
	filein.ignore(1);
	getline(filein, Name, ',');
	this->setName(Name);
	filein.ignore(1);
	getline(filein, Account, ',');
	this->setAccount(Account);
	filein.ignore(1);
	getline(filein, Password, '.');
	this->setPassword(Password);
}
void Director::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getName() << ", ";
	fileout << this->getAccount() << ", ";
	fileout << this->getPassword() << ". ";
	fileout << "\n";
}
void Director::writeData() {
	cout << "|" << left << setw(3) << " ";
	cout << left << setw(12) << this->getId() << "|";
	cout << left << setw(7) << " ";
	cout << left << setw(26) << this->getName() << "|";
	cout << left << setw(4) << " ";
	cout << left << setw(25) << this->getAccount() << "|";
	cout << left << setw(4) << " ";
	cout << left << setw(21) << this->getPassword() << "|";
	cout << "\n";
}