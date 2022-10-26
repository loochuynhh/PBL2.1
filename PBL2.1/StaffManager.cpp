#include "StaffManager.h"

void StaffManager::readFile(fstream& filein) {
	filein >> length;
	Staff* st = new Staff[20];
	for (int i = 0; i < length; i++) {
		(st + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = st;
}
void StaffManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void StaffManager::write() {
	for (int i = 0; i < 170; i++) cout << "-"; cout << endl;
	cout << "| Ma nhan vien |    " << left << setw(22) << " Ten nhan vien" << "| Tuoi |" << left << setw(15) << "   Cong viec " << "|" << left << setw(23) << "     Tai khoan" << "|" << left << setw(17) << "   Mat khau" << "| Ngay sinh  |" << left << setw(15) << " So dien thoai" << "|" << left << setw(32) << "        email" << "|" << endl;
	for (int i = 0; i < 170; i++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeData();
	}
	for (int i = 0; i < 170; i++) cout << "-"; cout << endl;
}