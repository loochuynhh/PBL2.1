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
	cout << "\t\t\t\t";
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
	cout << "\t\t\t\t";
	cout << "|" << left << setw(15) << "  Ma quan li" << "|" << left << setw(27) << "\tTen quan li" << "|" << left << setw(25) << "\t  Tai khoan" << "|" << left << setw(25) << "    Mat khau" << "|" << endl;
	cout << "\t\t\t\t";
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t";
		(typeList + i)->writeData();
	}
	cout << "\t\t\t\t";
	for (int x = 0; x < 107; x++) cout << "-"; cout << endl;
}
void DirectorManager::updateAc() {
	string id;
	cout << "\n\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
	}
	else {
		Director* director = findById(id);
		string account;
		cout << "\t\t\t\t\t\t\tNhap tai khoan moi: ";
		getline(cin, account);
		director->setAccount(account);
		cout << "\t\t\t\t\t\t\tTai khoan da duoc cap nhat.\n";
	}
}
void DirectorManager::updatePq() {
	string id;
	cout << "\n\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay!\n";
	}
	else {
		Director* director = findById(id);
		string password;
		cout << "\t\t\t\t\t\t\tNhap mat khau moi: ";
		getline(cin, password);
		director->setPassword(password);
		cout << "\t\t\t\t\t\t\tMat khau da duoc cap nhat.\n";
	}
}