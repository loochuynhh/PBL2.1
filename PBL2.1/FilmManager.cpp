#include "FilmManager.h"

char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

void FilmManager::findByName(string& name) {
	transform(name.begin(), name.end(), name.begin(), asciitolower);
	int check = 0;
	int i = 0;
	while(i < this->length) {
		string nametmp = (this->typeList + i)->getName();
		transform(nametmp.begin(), nametmp.end(), nametmp.begin(), asciitolower);
		size_t found = nametmp.find(name);
		if (found != string::npos && check == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t<<PHIM CHUA TEN TREN LA>>\n\n";
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			(this->typeList + i)->writeData();
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			check = 1;
		}
		else if (found != string::npos) {
			cout << "\t";
			(this->typeList + i)->writeData();
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
		}
		i++;
	}
	if(check == 0) {
		cout << "\n\t\t\t\t\t\t\tKhong tim thay phim!" << endl;
		return;
	}
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
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		cin.ignore();
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "\t\t\t\t\t\t\tMa bi trung!. Lua chon" << endl;
			cout << "\n\t\t\t\t\t1. Nhap lai";
			cout << "\n\t\t\t2. Thoat\n";
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
	cout << "\t\t\t\t\t\t\tNhap ten phim: ";
	getline(cin, name);
	cout << "\t\t\t\t\t\t\tNhap dao dien: ";
	getline(cin, director);
	cout << "\t\t\t\t\t\t\tNhap dien vien chinh: ";
	getline(cin, actor);
	cout << "\t\t\t\t\t\t\tNhap noi san xuat: ";
	getline(cin, country);
	cout << "\t\t\t\t\t\t\t\t\t\tCac the loai bao gom:";
	int cnt = 0;
	while (cnt < 20) {
		cout << "\n\t\t\t\t\t\t\t" << left << setw(30) << *(this->getTypeList()->getTypeof() + cnt) << "|";
		cout << "\t\t\t\t" << *(this->getTypeList()->getTypeof() + cnt + 1);
		cnt += 2;
	}
	cout << "\n";
	do {
		cout << "\t\t\t\t\t\t\tNhap the loai: ";
		getline(cin, type);
		for (int i = 0; i < 20; i++) {
			if (type.compare(*(filmtmp.getTypeof() + i)) == 0) {
				checkf = 1;
			}
		}
		if (checkf == 0) {
			cout << "\t\t\t\t\t\t\t\tThe loai khong hop le moi nhap lai.\n";
			system("pause");
		}
	} while (checkf == 0);
	cout << "\t\t\t\t\t\t\tNhap do dai phim: ";
	cin >> length;
	Film film(id, name, director, actor, country, type, length);
	return film;
}

void FilmManager::update() {
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	cin.ignore();
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\n\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		Film* film = findById(id);
		do {
			cout << "\t\t\t\t\t\t\t1. Sua ten phim" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua dao dien" << endl;
			cout << "\t\t\t\t\t\t\t3. Sua dien vien" << endl;
			cout << "\t\t\t\t\t\t\t4. Sua noi san xuat" << endl;
			cout << "\t\t\t\t\t\t\t5. Sua the loai" << endl;
			cout << "\t\t\t\t\t\t\t6. Sua do dai phim" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t\t>> Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			cin.ignore();
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap ten phim: ";
				getline(cin, up);
				film->setName(up);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap dao dien: ";
				getline(cin, up);
				film->setDirector(up);
				break;
			}
			case(3): {
				cout << "\t\t\t\t\t\t\tNhap dien vien: ";
				getline(cin, up);
				film->setActor(up);
				break;
			}
			case(4): {
				cout << "\t\t\t\t\t\t\tNhap noi san xuat: ";
				getline(cin, up);
				film->setCountry(up);
				break;
			}
			case(5): {
				cout << "\t\t\t\t\t\t\tNhap the loai: ";
				getline(cin, up);
				film->setType(up);
				break;
			}
			case(6): {
				cout << "\t\t\t\t\t\t\tNhap thoi gian: ";
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
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	cout << "\t";
	cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t";
		(typeList + i)->writeData();
	}
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
}