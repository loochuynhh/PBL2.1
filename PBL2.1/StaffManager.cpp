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
void StaffManager::writerl() {
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
	cout << "| Ma nhan vien |   " << left << setw(24) << "Ten nhan vien" << "|   " << left << setw(24) << "Ten nguoi than" << "| TuoiNT |" << left << setw(16) << " SDT nguoi than" << "|" << left << setw(32) << "       email nguoi than" << "|\n";
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDatarl();
	}
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
}
Staff StaffManager::setStaff() {
	cout << "\t\t**Nhap day du thong tin nhan vien**\n";
	Staff staff;
	string id, name, job, account, password, phone, mail, phonerl, mailrl, namerl;
	int age, agerl, date, month, year;
	Infor infor;
	Inforrl inforrl;
	int check = 0;
	do {
		cout << "Nhap ID nhan vien: ";fflush(stdin);
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "Ma bi trung!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
			cin.ignore();
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		staff.setId("null");
		return staff;
	}
	check = 0;
	cout << "Nhap ten nhan vien: ";
	getline(cin, name);
	cout << "Nhap cong viec: ";
	getline(cin, job);
	cout << "Nhap tai khoan nhan vien: ";
	getline(cin, account);
	cout << "Nhap mat khau nhan vien: ";
	getline(cin, password);
	cout << "Nhap so dien thoai nhan vien: ";
	getline(cin, phone);
	infor.setPhone(phone);
	cout << "Nhap mail nhan vien: ";
	getline(cin, mail);
	infor.setMail(mail);
	cout << "Nhap tuoi nhan vien: ";
	cin >> age;
	infor.setAge(age);
	staff.setInforSt(infor);
	cout << "Nhap ngay sinh nhan vien: ";
	cin >> date;
	cout << "Nhap thang sinh nhan vien: ";
	cin >> month;
	cout << "Nhap nam sinh nhan vien: ";
	cin >> year;
	Time t(date, month, year);
	staff.setTimeSt(t);
	cout << "Nhap ten nhan than: ";
	cin.ignore();
	getline(cin, namerl);
	inforrl.setNamerl(namerl);
	cout << "Nhap so dien thoai nhan than: ";
	getline(cin, phonerl);
	inforrl.setPhone(phonerl);
	cout << "Nhap mail nhan than: ";
	getline(cin, mailrl);
	inforrl.setMail(mailrl);
	cout << "Nhap tuoi nhan than: ";
	cin >> agerl; 
	inforrl.setAge(agerl);
	staff.setRelative(inforrl);
	staff.setId(id); staff.setName(name); staff.setAccount(account); staff.setJob(job); staff.setPassword(password);
	return staff;
}
void StaffManager::update(){
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
		Staff* staff = findById(id);
		do {
			cout << "\tCap nhap nhan vien" << endl;
			cout << "1.Sua ten nhan vien" << endl;
			cout << "2.Sua cong viec" << endl;
			cout << "3.Sua tai khoan" << endl;
			cout << "4.Sua mat khau" << endl;
			cout << "5.Sua ngay thang nam sinh" << endl;
			cout << "6.Sua tuoi nhan vien" << endl;
			cout << "7.Sua so dien thoai" << endl;
			cout << "8.Sua mail nhan vien" << endl;
			cout << "9.Sua ten nhan than" << endl;
			cout << "10.Sua tuoi nhan than" << endl;
			cout << "11.Sua so dien thoai nhan than" << endl;
			cout << "12.Sua mail nhan than" << endl;
			cout << "0.Xac nhan" << endl;
			cout << "Nhap lua chon: ";
			cin >> opttmp;
			string up;
			int upn;
			cin.ignore();
			switch (opttmp) {
			case(1): {
				cout << "Nhap ten nhan vien: ";
				getline(cin, up);
				staff->setName(up);
				break;
			}
			case(2): {
				cout << "Nhap cong viec: ";
				getline(cin, up);
				staff->setJob(up);
				break;
			}
			case(3): {
				cout << "Nhap tai khoan: ";
				getline(cin, up);
				staff->setAccount(up);
				break;
			}
			case(4): {
				cout << "Nhap mat khau: ";
				getline(cin, up);
				staff->setPassword(up);
				break;
			}
			case(5): {
				cout << "Nhap ngay thang nam sinh: ";
				int date, month, year;
				cin >> date >> month >> year;
				staff->getTimeSt().setDate(date);  staff->getTimeSt().setMonth(month); staff->getTimeSt().setYear(year);
				break;
			}
			case(6): {
				cout << "Nhap tuoi nhan vien: ";
				cin >> upn;
				staff->getInforSt().setAge(upn);
				break;
			}
			case(7): {
				cout << "Nhap so dien thoai nhan vien: ";
				getline(cin, up);
				staff->getInforSt().setPhone(up);
				break;
			}
			case(8): {
				cout << "Nhap mail nhan vien: ";
				getline(cin, up);
				staff->getInforSt().setMail(up);
				break;
			}
			case(9): {
				cout << "Nhap ten nhan than: ";
				getline(cin, up);
				staff->getRelative().setNamerl(up);
				break;
			}
			case(10): {
				cout << "Nhap tuoi nhan than: ";
				cin >> upn;
				staff->getRelative().setAge(upn);
				break;
			}
			case(11): {
				cout << "Nhap so dien thoai nhan than: ";
				getline(cin, up);
				staff->getRelative().setPhone(up);
				break;
			}
			case(12): {
				cout << "Nhap mail nhan than: ";
				getline(cin, up);
				staff->getRelative().setMail(up);
				break;
			}
			//cout << "Lua chon khong hop le.";
			break;
			}
		} while (opttmp != 0);
	}
}

void StaffManager::readSalaryFile(fstream& filein) {
	for (int i = 0; i < this->length; i++) {
		int slength;
		filein >> slength;
		(this->getTypeList() + i)->setSlength(slength);
		Salary* salary = new Salary[slength];
		for (int j = 0; j < slength; j++) {
			(salary + j)->readFile(filein);
		}
		delete[] (this->getTypeList() + i)->getStSalary();
		(this->getTypeList() + i)->setStSalary(salary);
	}
}

void StaffManager::writeSalaryFile(fstream& fileout) {
	for (int i = 0; i < this->length; i++) {
		fileout << (this->getTypeList() + i)->getSlength() << endl;
		for (int j = 0; j < (this->getTypeList() + i)->getSlength(); j++) {
			((this->getTypeList() + i)->getStSalary() + j)->writeFile(fileout);
		}
	}
}
void StaffManager::writeSalaryY(int year) {
	int salaryTable[20][12][2];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 2; k++) salaryTable[i][j][k] = 0;
		}
	}
	cout << "\t\t\t\t\t\t\t\tTIEN LUONG DA TRA TRONG NAM " << year << " LA: " << endl;
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->typeList->getSlength(); j++) {
			if (((this->getTypeList() + i)->getStSalary() + j)->getTimeslr().getYear() == year) {
				salaryTable[i][((this->getTypeList() + i)->getStSalary() + j)->getTimeslr().getMonth() - 1][0] = ((this->getTypeList() + i)->getStSalary() + j)->getSalaryBase();
				salaryTable[i][((this->getTypeList() + i)->getStSalary() + j)->getTimeslr().getMonth() - 1][1] = ((this->getTypeList() + i)->getStSalary() + j)->getBonus();
			}
		}
	}
	cout << "\t";
	for (int i = 0; i < 161; i++) cout << "-"; cout << endl;
	cout << "\t";
	cout << "| MaNV/Thang |  Loai Luong  |    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12    |\n";
	cout << "\t";
	for (int i = 0; i < 161; i++) cout << "-"; cout << endl; 
	for (int i = 0; i < length; i++) {
		for (int cnt = 0; cnt < 3; cnt++) {
			if (cnt == 1) {
				cout << "\t";
				cout << "|   " << left << setw(9) << (this->getTypeList() + i)->getId();
				cout << "|    Thuong    |";
				for (int j = 0; j < 12; j++) {
					cout << left << setw(10) << salaryTable[i][j][1] << "|";
				}
			}
			else if (cnt == 0) {
				cout << "\t";
				cout << "|            |    Co ban    |";
				for (int j = 0; j < 12; j++) {
					cout << left << setw(10) << salaryTable[i][j][0] << "|";
				}
			}
			else {
				cout << "\t";
				cout << "|            |  Tong cong   |";
				for (int j = 0; j < 12; j++) {
					cout << left << setw(10) << salaryTable[i][j][0] + salaryTable[i][j][1] << "|";
				}
			}
			cout << endl;
		}
		cout << "\t";
		for (int i = 0; i < 161; i++) cout << "-"; cout << endl;
	}
}
void StaffManager::addSalary() {
	string id;
	Salary tmp;
	int check = 1;
	do {
		cout << "\t\tNhap ma nhan vien muon them luong: ";
		cin.ignore();
		getline(cin, id);
		if (this->findById(id) != nullptr) {
			check = 2;
			int date, month, year, salarybase, bonus;
			cout << "\t\tNhap ngay tra luong: ";
			cin >> date;
			cout << "\t\tNhap thang tra luong: ";
			cin >> month;
			cout << "\t\tNhap nam tra luong: ";
			cin >> year;
			Time timeslr(date, month, year);
			tmp.setTimeslr(timeslr);
			cout << "\t\tNhap luong co ban: ";
			cin >> salarybase;
			tmp.setSalaryBase(salarybase);
			cout << "\t\tNhap luong thuong them: ";
			cin >> bonus;
			tmp.setBonus(bonus);
			this->typeList->addslr(tmp);
			cout << "\t\tLuong da duoc them.\n";
		}
		else {
			cout << "\t\t\tMa nhan vien khong hop le. Lua chon:";
			cout << "\n\t\t1. Nhap lai.";
			cout << "\n\t\t2. Thoat.\n";
			cin >> check;
		}
	} while (check == 1);
}