#include "FilmManager.h"

void FilmManager::findByName(string& name) {
	if(checkName(name) == false) {
		cout << "Khong tim thay phim!" << endl;
		return;
	}
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	for (int i = 0; i < this->length; i++) {
		string namecmp = (this->typeList + i)->getName();
		if (name.compare(namecmp) == 0) (this->typeList + i)->writeData();
	}
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
}

bool FilmManager::checkName(string& name) {
	for (int i = 0; i < this->length; i++) {
		string namecmp = (this->typeList + i)->getName();
		if (name.compare(namecmp) == 0) return true;
	}
	return false;
}


Film FilmManager::setFilmInfor() {
	string id;
	string name;
	string director;
	string actor;
	string country;
	string type;
	int length;
	int check = 0, checkf = 0;
	Film filmtmp;
	do {
		cout << "Nhap id: ";
		cin.ignore();
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "Ma bi trung!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		Film film;
		film.setId("null");
		return film;
	}
	check = 0;
	cout << "Nhap ten phim: ";
	getline(cin, name);
	cout << "Nhap dao dien: ";
	getline(cin, director);
	cout << "Nhap dien vien chinh: ";
	getline(cin, actor);
	cout << "Nhap noi san xuat: ";
	getline(cin, country);
	do {
		cout << "Nhap the loai: ";
		getline(cin, type);
		for (int i = 0; i < 20; i++) {
			if (type.compare(*(filmtmp.getTypeof() + i)) == 0) {
				checkf = 1;
			}
		}
		if (checkf == 0) {
			cout << "The loai khong hop le moi nhap lai.";
			system("pause");
		}
	} while (checkf == 0);
	cout << "Nhap do dai phim: ";
	cin >> length;
	Film film(id, name, director, actor, country, type, length);
	return film;
}

void FilmManager::update() {
	string id;
	cout << "Nhap id: ";
	cin.ignore();
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "Khong tim thay!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		Film* film = findById(id);
		do {
			cout << "\t\tCap nhap phim" << endl;
			cout << "1.Sua ten phim" << endl;
			cout << "2.Sua dao dien" << endl;
			cout << "3.Sua dien vien" << endl;
			cout << "4.Sua noi san xuat" << endl;
			cout << "5.Sua the loai" << endl;
			cout << "6.Sua do dai phim" << endl;
			cout << "0.Xac nhan" << endl;
			cout << "Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			cin.ignore();
			switch (opttmp) {
			case(1): {
				cout << "Nhap ten phim: ";
				getline(cin, up);
				film->setName(up);
				break;
			}
			case(2): {
				cout << "Nhap dao dien: ";
				getline(cin, up);
				film->setDirector(up);
				break;
			}
			case(3): {
				cout << "Nhap dien vien: ";
				getline(cin, up);
				film->setActor(up);
				break;
			}
			case(4): {
				cout << "Nhap noi san xuat: ";
				getline(cin, up);
				film->setCountry(up);
				break;
			}
			case(5): {
				cout << "Nhap the loai: ";
				getline(cin, up);
				film->setType(up);
				break;
			}
			case(6): {
				cout << "Nhap thoi gian: ";
				cin >> upn;
				film->setLength(upn);
				break;
			}
			}
		} while (opttmp != 0);
	}
}
void FilmManager::readFile(fstream& filein) {
	filein >> length;
	Film* film = new Film[50];
	for (int i = 0; i < length; i++) {
		(film + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = film;
}
void FilmManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void FilmManager::write() {
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeData();
	}
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
}