#include "CinemaRoomManager.h"

CinemaRoom CinemaRoomManager::setCinemaRoomInfor() {
	CinemaRoom cinemaRoom;
	string id;
	int check = 0;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		cin.ignore(); 
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
			cout << "\n\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat\n";
			cin >> check;
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
	cin >> chairs;
	string status;
	cout << "\t\t\t\t\t\t\tNhap tinh trang phong chieu: ";
	cin.ignore();
	getline(cin, status);
	cinemaRoom.setId(id);
	cinemaRoom.setChairs(chairs);
	cinemaRoom.setStatus(status);
	return cinemaRoom;
}

void CinemaRoomManager::update() {
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	cin.ignore();
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		CinemaRoom* room = findById(id);
		do {
			cout << "\t\t\t\t\t\t\t1. Sua so ghe" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua tinh trang" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t>> Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap so ghe: ";
				cin >> upn;
				room->setChairs(upn);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap tinh trang: ";
				cin.ignore();
				getline(cin, up);
				room->setStatus(up);
				break;
			}
			}
		} while (opttmp != 0);
	}
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