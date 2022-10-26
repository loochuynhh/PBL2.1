#include "DirectorManager.h"

void DirectorManager::readFile(fstream& filein) {
	filein >> length;
	Director* drt = new Director[5];
	for (int i = 0; i < length; i++) {
		(drt + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = drt;
}
void DirectorManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void DirectorManager::write() {
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
	cout << "|" << left << setw(15) << "  Ma quan li" << "|" << left << setw(27) << "\tTen quan li" << "|" << left << setw(25) << "\t  Tai khoan" << "|" << left << setw(25) << "    Mat khau" << "|" << endl;
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeData();
	}
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
}