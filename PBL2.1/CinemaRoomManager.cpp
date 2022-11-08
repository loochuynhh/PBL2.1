#include "CinemaRoomManager.h"
#include <Windows.h>

CinemaRoom CinemaRoomManager::setCinemaRoomInfor() {
	CinemaRoom cinemaRoom;
	string id;
	int check = 0;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
				cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
				cout << "\t\t\t2. Thoat";
				cout << "\n\t\t\t\t\t\t\t";
				check = getInt();
				if (check != 1 && check != 2) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
					system("pause");
				}
			} while (check != 1 && check != 2);
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		cinemaRoom.setId("null");
		return cinemaRoom;
	}
	check = 0;
	int chairs;
	cout << "\t\t\t\t\t\t\tNhap so ghe: ";
	chairs = getInt();
	string status;
	cout << "\t\t\t\t\t\t\tNhap tinh trang phong chieu: ";
	getline(cin, status);
	cinemaRoom.setId(id);
	cinemaRoom.setChairs(chairs);
	cinemaRoom.setStatus(status);
	return cinemaRoom;
}

string CinemaRoomManager::update() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
		return "";
	}
	else {
		int opttmp = 0;
		CinemaRoom* room = findById(id);
		do {
			system("cls");
			cout << "\n\t\t\t\t\t\t";
			for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
			cout << "\t\t\t\t\t\t";
			cout << "|" << left << setw(6) << " " << left << setw(20) << "Ma phong chieu" << "|" << left << setw(10) << "\tSo ghe" << "|" << left << setw(30) << "\t        Chat luong" << "|" << endl;
			cout << "\t\t\t\t\t\t";
			for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
			cout << "\t\t\t\t\t\t";
			room->writeData();
			cout << "\t\t\t\t\t\t";
			for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
			cout << "\n\t\t\t\t\t\t\t1. Sua so ghe" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua tinh trang" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t>> Nhap lua chon: ";
			opttmp = getInt();
			string up;
			int upn;
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap so ghe: ";
				upn = getInt();
				room->setChairs(upn);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap tinh trang: ";
				getline(cin, up);
				if(up == "bad") {
					SetConsoleTextAttribute(cl, 4);
					cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI PHONG CHIEU CAP NHAT TINH TRANG KHONG TOT SE DUOC XOA TRONG LICH CHIEU\n";
					SetConsoleTextAttribute(cl, 7);
					cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon cap nhat.";
					cout << "\n\t\t\t\t\t\t\t1. Cap nhat.";
					cout << "\t\t\t0. Thoat.";
					cout << "\n\t\t\t\t\t\t\t";
					int idel; idel = getInt();
					if(idel == 1){
						room->setStatus(up);
					}
					else if (idel == 0) {}
					else {
						cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
						system("pause");
					}
				}	
				else room->setStatus(up);			
				break;
			}
			}
		} while (opttmp != 0);
	}
	return id;
}
void CinemaRoomManager::readFile(fstream& filein) {
	filein >> length;
	CinemaRoom* cnmr = new CinemaRoom[10];
	for (int i = 0; i < length; i++) {
		(cnmr + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = cnmr;
}
void CinemaRoomManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void CinemaRoomManager::write() {
	cout << "\t\t\t\t\t\t";
	for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
	cout << "\t\t\t\t\t\t";
	cout << "|" << left << setw(6) << " " << left << setw(20) << "Ma phong chieu" << "|" << left << setw(10) << "\tSo ghe" << "|" << left << setw(30) << "\t        Chat luong" << "|" << endl;
	cout << "\t\t\t\t\t\t";
	for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t\t\t";
		(typeList + i)->writeData();
	}
	cout << "\t\t\t\t\t\t";
	for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
}