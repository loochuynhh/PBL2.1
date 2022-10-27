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
	cout << "Nhap id: ";
	cin.ignore();
	getline(cin, id);
	int check = 0;
	do {
		system("cls");
		this->filmManager->write();
		cout << "Nhap ma phim: ";
		getline(cin, filmId);
		if (this->filmManager->findById(filmId) == nullptr) {
			cout << "Khong tim thay phim!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
		}
		else check = 3;
		cin.ignore();
	} while (check == 1 || check == 0);	
	if (check == 2) {
		schedule.setId("null");
		return schedule;
	}
	check = 0;
	do {
		system("cls");
		this->cinemaRoomManager->write();
		cout << "Nhap ma phong chieu: ";
		getline(cin, cinemaRoomId);
		if (this->cinemaRoomManager->findById(cinemaRoomId) == nullptr) {
			cout << "Khong tim thay phong chieu!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
		}
		else if (this->cinemaRoomManager->findById(cinemaRoomId)->getStatus() == "bad") {
			cout << "Phong chieu dang co van de!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
		}
		else check = 3;
		cin.ignore();
	} while (check == 1 || check == 0);
	if (check == 2) {
		schedule.setId("null");
		return schedule;
	}
	getShow();
	cout << "Nhap ca so: " << endl;
	cin >> show;
	while (show < 1 || show > 5)
	{
		cout << "So ca khong hop le!" << endl;
		getShow();
		cout << "Nhap ca so: " << endl;
		cin >> show;
	}	
	cout << "Nhap ngay chieu: ";
	cin >> date;
	cout << "Nhap thang chieu: ";
	cin >> month;
	cout << "Nhap nam chieu: ";
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
	cout << "Nhap id: ";
	cin.ignore();
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "Khong tim thay!\n";
	}
	else {
		int opttmp = 0;
		Schedule* schedule = findById(id);
		do {
			cout << "\tCap nhap phim" << endl;
			cout << "1.Sua ma phim" << endl;
			cout << "2.Sua ma phong chieu" << endl;
			cout << "3.Sua ca chieu" << endl;
			cout << "4.Sua thoi gian" << endl;
			cout << "0.Xac nhan" << endl;
			cout << "Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			cin.ignore();
			switch (opttmp) {
			case(1): {
				int check = 0;
				do {
					if(check == 1) {
						cout << "Khong tim thay phim!" << endl;
					}
					cout << "Nhap ma phim: ";
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
						cout << "Khong tim thay phong!" << endl;
					}
					else if(check == 2) {
						cout << "Phong chieu dang co van de, vui long chon phong khac!" << endl;
					}
					cout << "Nhap ma phong: ";
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
				cout << "Nhap ca chieu: " << endl;
				getShow();
				cin >> upn;
				while (upn < 1 || upn > 5)
				{
					cout << "So ca khong hop le!" << endl;
					cout << "Nhap so ca: " << endl;
					getShow();
					cin >> upn;
				}	
				schedule->setShow(upn);
				break;
			}
			case(4): {
				int date;
				int month;
				int year;
				cout << "Nhap ngay: ";
				cin >> date;
				cout << "Nhap thang: ";
				cin >> month;
				cout << "Nhap nam: ";
				cin >> year;
				Time t;
				t.setDate(date);
				t.setMonth(month);
				t.setYear(year);
				schedule->setTime(t);
				break;
			}
				cout << "Luc chon khong hop le.";
				break;
			}
		} while (opttmp != 0);
	}
}

void ScheduleManager::getShow() {
	cout << "Ca 1: " << "7:00 - 9:00" << endl;
	cout << "Ca 2: " << "10:00 - 12:00" << endl;
	cout << "Ca 3: " << "13:00 - 16:00" << endl;
	cout << "Ca 4: " << "17:00 - 20:00" << endl;
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
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
	cout << "|  Ma lich chieu  |   Ma phim   |  Ma phong chieu  |  Ca  |     Ngay chieu     |" << endl;
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeData();
	}
	for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
}