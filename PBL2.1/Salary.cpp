#include "Salary.h"

Salary::Salary() {
    this->salaryBase = 0;
    this->bonus = 0;
    this->timeslr;
}
Salary::~Salary() {}
void Salary::setBonus(int Bonus) {
    this->bonus = Bonus;
}
int Salary::getBonus() {
    return this->bonus;
}
void Salary::setTimeslr(Time Timeslr) {
    this->timeslr = Timeslr;
}
Time Salary::getTimeslr() {
    return this->timeslr;
}
void Salary::setSalaryBase(int salaryBase) {
    this->salaryBase = salaryBase;
}
int Salary::getSalaryBase() {
    return this->salaryBase;
}
void Salary::readFile(fstream& filein) {
    filein.ignore(20, 10);
    int salaryBase, bonus;
    Time timeslr;
    filein >> salaryBase;
    this->setSalaryBase(salaryBase);
    filein.ignore(1);
    filein >> bonus;
    this->setBonus(bonus);
    filein.ignore(1);
    this->timeslr.readfilet(filein);
}
void Salary::writeFile(fstream& fileout) {
    fileout << this->getSalaryBase() << ", ";
    fileout << this->getBonus() << ", ";
    this->timeslr.writefilet(fileout);
    fileout << "\n";
}
void Salary::write() {

}