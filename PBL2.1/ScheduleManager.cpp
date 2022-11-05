#include "ScheduleManager.h"

ScheduleManager::ScheduleManager(FilmManager& filmManager, CinemaRoomManager& room) {
	this->filmManager = &filmManager;
	this->cinemaRoomManager = &room;
}

Schedule ScheduleManager::setScheduleInfor() {
	Schedule schedule;
	string id;
	string filmId;
	string cinemaRoomId;
	int show;
	int date;
	int month;
	int year;
	int check = 0;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		cin.ignore();
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
			cout << "\n\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		schedule.setId("null");
		return schedule;
	}
	check = 0;
	do {
		this->filmManager->write();
		cout << "\t\t\t\t\t\t\tNhap ma phim: ";
		getline(cin, filmId);
		if (this->filmManager->findById(filmId) == nullptr) {
			cout << "\t\t\t\t\t\t\t\tKhong tim thay phim!. Lua chon";
			cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
			cin.ignore();
		}
		else check = 3;
	} while (check == 1 || check == 0);	
	if (check == 2) {
		schedule.setId("null");
		return schedule;
	}
	check = 0;
	do {
		this->cinemaRoomManager->write();
		cout << "\t\t\t\t\t\t\tNhap ma phong chieu: "; 
		getline(cin, cinemaRoomId);
		if (this->cinemaRoomManager->findById(cinemaRoomId) == nullptr) {
			cout << "\t\t\t\t\t\t\t\tKhong tim thay phong chieu!. Lua chon";
			cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
			cin.ignore();
		}
		else if (this->cinemaRoomManager->findById(cinemaRoomId)->getStatus() == "bad") {
			cout << "\t\t\t\t\t\t\t\tPhong chieu dang co van de!. Lua chon";
			cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
			cin.ignore();
		}
		else check = 3;
	} while (check == 1 || check == 0);
	if (check == 2) {
		schedule.setId("null");
		return schedule;
	}
	getShow();
	cout << "\t\t\t\t\t\t\tNhap ca so: ";
	cin >> show;
	while (show < 1 || show > 5)
	{
		cout << "\t\t\t\t\t\t\tSo ca khong hop le!" << endl;
		getShow();
		cout << "\t\t\t\t\t\t\tNhap ca so: ";
		cin >> show;
	}	
	cout << "\t\t\t\t\t\t\tNhap ngay chieu: ";
	cin >> date;
	cout << "\t\t\t\t\t\t\tNhap thang chieu: ";
	cin >> month;
	cout << "\t\t\t\t\t\t\tNhap nam chieu: ";
	cin >> year;
	Time t(date, month, year);
	schedule.setId(id);
	schedule.setFilmId(filmId);
	schedule.setCinemaRoomId(cinemaRoomId);
	schedule.setShow(show);
	schedule.setTime(t);
	return schedule;
}

void ScheduleManager::update() {
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
		Schedule* schedule = findById(id);
		do {
			cout << "\t\t\t\t\t\t\t1. Sua ma phim" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua ma phong chieu" << endl;
			cout << "\t\t\t\t\t\t\t3. Sua ca chieu" << endl;
			cout << "\t\t\t\t\t\t\t4. Sua thoi gian" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t>> Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			cin.ignore();
			switch (opttmp) {
			case(1): {
				int check = 0;
				do {
					if(check == 1) {
						cout << "\t\t\t\t\t\t\tKhong tim thay phim!" << endl;
					}
					this->filmManager->write();
					cout << "\t\t\t\t\t\t\tNhap ma phim: ";
					getline(cin, up);
					if(this->filmManager->findById(up) == nullptr) {
						check = 1;
					}
					else {
						check = 0;
					}
				} while(check != 0);	
				schedule->setFilmId(up);
				break;
			}
			case(2): {
				int check = 0;
				do {
					if(check == 1) {
						cout << "\t\t\t\t\t\t\tKhong tim thay phong!" << endl;
					}
					else if(check == 2) {
						cout << "\t\t\t\t\t\t\tPhong chieu dang co van de, vui long chon phong khac!" << endl;
					}
					this->cinemaRoomManager->write();
					cout << "\t\t\t\t\t\t\tNhap ma phong: ";
					getline(cin, up);
					if(this->cinemaRoomManager->findById(up) == nullptr) {
						check = 1;
					}
					else if(this->cinemaRoomManager->findById(up)->getStatus() == "bad") {
						check = 2;
					}
					else  {
						check = 0;
					}
				} while(check != 0);
				schedule->setCinemaRoomId(up);
				this->cinemaRoomManager->write();
				break;
			}
			case(3): {
				cout << "\t\t\t\t\t\t\tNhap ca chieu: " << endl;
				getShow();
				cin >> upn;
				while (upn < 1 || upn > 5)
				{
					cout << "\t\t\t\t\t\t\tSo ca khong hop le!" << endl;
					getShow();
					cout << "\t\t\t\t\t\t\tNhap lai ca chieu: " << endl;
					cin >> upn;
				}	
				schedule->setShow(upn);
				break;
			}
			case(4): {
				int date;
				int month;
				int year;
				cout << "\t\t\t\t\t\t\tNhap ngay: ";
				cin >> date;
				cout << "\t\t\t\t\t\t\tNhap thang: ";
				cin >> month;
				cout << "\t\t\t\t\t\t\tNhap nam: ";
				cin >> year;
				Time t;
				t.setDate(date);
				t.setMonth(month);
				t.setYear(year);
				schedule->setTime(t);
				break;
			}
				cout << "\t\t\t\t\t\t\tLuc chon khong hop le.";
				break;
			}
		} while (opttmp != 0);
	}
}

void ScheduleManager::getShow() {
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 1: " << "7:00 - 9:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 2: " << "10:00 - 12:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 3: " << "13:00 - 16:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 4: " << "17:00 - 20:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 5: " << "21:00 - 0:00" << endl;
}

void ScheduleManager::readFile(fstream& filein) {
	filein >> length;
	Schedule* schedule = new Schedule[100];
	for (int i = 0; i < length; i++) {
		(schedule + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = schedule;
}
void ScheduleManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void ScheduleManager::write() {
	cout << "\t\t\t\t\t";
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
	cout << "\t\t\t\t\t";
	cout << "|  Ma lich chieu  |   Ma phim   |  Ma phong chieu  |  Ca  |     Ngay chieu     |" << endl;
	cout << "\t\t\t\t\t";
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t\t";
		(typeList + i)->writeData();
	}
	cout << "\t\t\t\t\t";
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
}