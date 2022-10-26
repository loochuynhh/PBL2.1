#include "Staff.h"
#include <string>

void Staff::setId(string ID) {
    this->id = ID;
}
string Staff::getId() {
    return this->id;
}
void Staff::setName(string Name) {
    this->name = Name;
}
string Staff::getName() {
    return this->name;
}
void Staff::setJob(string Job) {
    this->job = Job;
}
string Staff::getJob() {
    return this->job;
}
void Staff::setAccount(string Account) {
    this->account = Account;
}
string Staff::getAccount() {
    return this->account;
}
void Staff::setPassword(string Password) {
    this->password = Password;
}
string Staff::getPassword() {
    return this->password;
}
void Staff::setTimeSt(Time Timest) {
    this->timest = Timest;
}
Time Staff::getTimeSt() {
    return this->timest;
}
void Staff::setStSalary(Salary* Stsalary) {
    this->stsalary = Stsalary;
}
Salary Staff::getStSalary() {
    return *this->stsalary;
}
void Staff::setInforSt(Infor Inforst) {
    this->inforst = Inforst;
}
Infor Staff::getInforSt() {
    return this->inforst;
}
void Staff::setRelative(Inforrl Relative) {
    this->relative = Relative;
}
Inforrl Staff::getRelative() {
    return this->relative;
}

void Staff::readDataFile(fstream& filein) {
    filein.ignore(20, 10);
    string ID, Name, Job, Account, Password;
    getline(filein, ID, ',');
    this->setId(ID);
    filein.ignore(1);
    getline(filein, Name, ',');
    this->setName(Name);
    filein.ignore(1);
    getline(filein, Job, ',');
    this->setJob(Job);
    filein.ignore(1);
    getline(filein, Account, ',');
    this->setAccount(Account);
    filein.ignore(1);
    getline(filein, Password, ',');
    this->setPassword(Password);
    this->timest.readfilet(filein);
    this->inforst.readFileIf(filein);
    this->relative.readFileIf(filein);
}
void Staff::writeDataFile(fstream& fileout) {
    fileout << this->getId() << ", ";
    fileout << this->getName() << ", ";
    fileout << this->getJob() << ", ";
    fileout << this->getAccount() << ", ";
    fileout << this->getPassword() << ", ";
    this->timest.writefilet(fileout);
    this->inforst.writeFileIf(fileout);
    this->relative.writeFileIf(fileout);
    fileout << "\n";
}
void Staff::writeData() {
    cout << "|" << left << setw(4) << " ";
    cout << left << setw(10) << this->getId() << "|";
    cout << left << setw(3) << " ";
    cout << left << setw(23) << this->getName() << "|";
    cout << "  " << this->getInforSt().getAge() << "  " << "|";
    cout << left << setw(3) << " ";
    cout << left << setw(12) <<this->getJob() << "|";
    cout << left << setw(3) << " ";
    cout << left << setw(20) << this->getAccount() << "|";
    cout << left << setw(2) << " ";
    cout << left << setw(15) << this->getPassword() << "|";
    cout << " ";
    this->timest.writet();
    cout << " " << "|";
    cout << "  " << left << setw(13) << this->getInforSt().getPhone() << "|";
    cout << "  ";
    cout << left << setw(30) << this->getInforSt().getMail() << "|";
    cout << "\n";
}
