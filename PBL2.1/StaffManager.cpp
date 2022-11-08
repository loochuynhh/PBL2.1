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
	cout << "\t\t\t";
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
	cout << "\t\t\t";
	cout << "| Ma nhan vien |   " << left << setw(24) << "Ten nhan vien" << "|   " << left << setw(24) << "Ten nguoi than" << "| TuoiNT |" << left << setw(16) << " SDT nguoi than" << "|" << left << setw(32) << "       email nguoi than" << "|\n";
	cout << "\t\t\t";
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t";
		(typeList + i)->writeDatarl();
	}
	cout << "\t\t\t";
	for (int i = 0; i < 131; i++) cout << "-"; cout << endl;
}
Staff StaffManager::setStaff() {
	cout << "\n\t\t\t\t\t\t\t**Nhap day du thong tin nhan vien**";
	Staff staff;
	string id, name, job, account, password, phone, mail, phonerl, mailrl, namerl;
	int age, agerl, date, month, year;
	Infor infor;
	Inforrl inforrl;
	int check = 0;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap ID nhan vien: ";
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
		staff.setId("null");
		return staff;
	}
	check = 0;
	cout << "\t\t\t\t\t\t\tNhap ten nhan vien: ";
	getline(cin, name);
	cout << "\t\t\t\t\t\t\tNhap cong viec: ";
	getline(cin, job);
	cout << "\t\t\t\t\t\t\tNhap tai khoan nhan vien: ";
	getline(cin, account);
	cout << "\t\t\t\t\t\t\tNhap mat khau nhan vien: ";
	getline(cin, password);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan vien: ";
			phone = getphone();
			break;
		}
		catch (int) {
			cout << "\t\t\t\t\t\t\tSo dien thoai khong chua ki tu! Moi nhap lai.\n";
		}
		catch (long) {
			cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
		}
	} while (true);
	infor.setPhone(phone);
	cout << "\t\t\t\t\t\t\tNhap mail nhan vien: ";
	getline(cin, mail);
	infor.setMail(mail);
	cout << "\t\t\t\t\t\t\tNhap tuoi nhan vien: ";
	age = getInt();
	infor.setAge(age);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap ngay sinh nhan vien: ";
			date = getInt();
			cout << "\t\t\t\t\t\t\tNhap thang sinh nhan vien: ";
			month = getInt();
			cout << "\t\t\t\t\t\t\tNhap nam sinh nhan vien: ";
			year = getInt();
			checktime(date, month, year);
			break;
		}
		catch (int) {
			cout << "\t\t\t\t\t\t\tNgay thang khong phu hop!. Moi nhap lai.\n";
		}
		catch (long) {
			cout << "\t\t\t\t\t\t\tThang khong hop le! Moi nhap lai.\n";
		}
		catch (unsigned int) {
			cout << "\t\t\t\t\t\t\tNgay khong duoc am! Moi nhap lai.\n";
		}
		catch (string) {
			cout << "\t\t\t\t\t\t\tNam khong hop le! Moi nhap lai.\n";
		}
	} while (true);
	Time t(date, month, year);
	staff.setTimeSt(t);
	cout << "\t\t\t\t\t\t\tNhap ten nhan than: ";
	getline(cin, namerl);
	inforrl.setNamerl(namerl);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan than: ";
			phonerl = getphone();
			break;
		}
		catch (int) {
			cout << "\t\t\t\t\t\t\tSo dien thoai khong chua ki tu! Moi nhap lai.\n";
		}
		catch (long) {
			cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
		}
	} while (true);
	inforrl.setPhone(phonerl);
	cout << "\t\t\t\t\t\t\tNhap mail nhan than: ";
	getline(cin, mailrl);
	inforrl.setMail(mailrl);
	cout << "\t\t\t\t\t\t\tNhap tuoi nhan than: ";
	agerl = getInt();
	inforrl.setAge(agerl);
	staff.setRelative(inforrl);
	staff.setId(id); staff.setName(name); staff.setAccount(account); staff.setJob(job); staff.setPassword(password);
	return staff;
}
void StaffManager::update(){
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		Staff* staff = findById(id);
		do {
			cout << "\t\t\t\t\t\t\t1. Sua ten nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua cong viec" << endl;
			cout << "\t\t\t\t\t\t\t3. Sua tai khoan" << endl;
			cout << "\t\t\t\t\t\t\t4. Sua mat khau" << endl;
			cout << "\t\t\t\t\t\t\t5. Sua ngay thang nam sinh" << endl;
			cout << "\t\t\t\t\t\t\t6. Sua tuoi nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t7. Sua so dien thoai" << endl;
			cout << "\t\t\t\t\t\t\t8. Sua mail nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t9. Sua ten nhan than" << endl;
			cout << "\t\t\t\t\t\t\t10. Sua tuoi nhan than" << endl;
			cout << "\t\t\t\t\t\t\t11. Sua so dien thoai nhan than" << endl;
			cout << "\t\t\t\t\t\t\t12. Sua mail nhan than" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t\t>> Nhap lua chon: ";
			opttmp = getInt();
			string up;
			int upn;
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap ten nhan vien: ";
				getline(cin, up);
				staff->setName(up);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap cong viec: ";
				getline(cin, up);
				staff->setJob(up);
				break;
			}
			case(3): {
				cout << "\t\t\t\t\t\t\tNhap tai khoan: ";
				getline(cin, up);
				staff->setAccount(up);
				break;
			}
			case(4): {
				cout << "\t\t\t\t\t\t\tNhap mat khau: ";
				getline(cin, up);
				staff->setPassword(up);
				break;
			}
			case(5): {
				int date, month, year;
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap ngay sinh: ";
						date = getInt();
						cout << "\t\t\t\t\t\t\tNhap thang sinh: ";
						month = getInt();
						cout << "\t\t\t\t\t\t\tNhap nam sinh: ";
						year = getInt();
						checktime(date, month, year);
						break;
					}
					catch (int) {
						cout << "\t\t\t\t\t\t\tNgay thang khong phu hop!. Moi nhap lai.\n";
					}
					catch (long) {
						cout << "\t\t\t\t\t\t\tThang khong hop le! Moi nhap lai.\n";
					}
					catch (unsigned int) {
						cout << "\t\t\t\t\t\t\tNgay khong duoc am! Moi nhap lai.\n";
					}
					catch (string) {
						cout << "\t\t\t\t\t\t\tNam khong hop le! Moi nhap lai.\n";
					}
				} while (true);
				staff->getTimeSt().setDate(date);  staff->getTimeSt().setMonth(month); staff->getTimeSt().setYear(year);
				break;
			}
			case(6): {
				cout << "\t\t\t\t\t\t\tNhap tuoi nhan vien: ";
				upn = getInt();
				staff->getInforSt().setAge(upn);
				break;
			}
			case(7): {
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan vien: ";
						up = getphone();
						break;
					}
					catch (int) {
						cout << "\t\t\t\t\t\t\tSo dien thoai khong chua ki tu! Moi nhap lai.\n";
					}
					catch (long) {
						cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
					}
				} while (true);
				staff->getInforSt().setPhone(up);
				break;
			}
			case(8): {
				cout << "\t\t\t\t\t\t\tNhap mail nhan vien: ";
				getline(cin, up);
				staff->getInforSt().setMail(up);
				break;
			}
			case(9): {
				cout << "\t\t\t\t\t\t\tNhap ten nhan than: ";
				getline(cin, up);
				staff->getRelative().setNamerl(up);
				break;
			}
			case(10): {
				cout << "\t\t\t\t\t\t\tNhap tuoi nhan than: ";
				upn = getInt();
				staff->getRelative().setAge(upn);
				break;
			}
			case(11): {
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan than: ";
						up = getphone();
						break;
					}
					catch (int) {
						cout << "\t\t\t\t\t\t\tSo dien thoai khong chua ki tu! Moi nhap lai.\n";
					}
					catch (long) {
						cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
					}
				} while (true);
				staff->getRelative().setPhone(up);
				break;
			}
			case(12): {
				cout << "\t\t\t\t\t\t\tNhap mail nhan than: ";
				getline(cin, up);
				staff->getRelative().setMail(up);
				break;
			}
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
					cout << " " << left << setw(9) << salaryTable[i][j][1] << "|";
				}
			}
			else if (cnt == 0) {
				cout << "\t";
				cout << "|            |    Co ban    |";
				for (int j = 0; j < 12; j++) {
					cout << " " << left << setw(9) << salaryTable[i][j][0] << "|";
				}
			}
			else {
				cout << "\t";
				cout << "|            |  Tong cong   |";
				for (int j = 0; j < 12; j++) {
					cout << " " << left << setw(9) << salaryTable[i][j][0] + salaryTable[i][j][1] << "|";
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
		cout << "\n\t\t\t\t\t\t\tNhap ma nhan vien muon them luong: ";
		getline(cin, id);
		if (this->findById(id) != nullptr) {
			check = 2;
			int date, month, year, salarybase, bonus;
			cout << "\t\t\t\t\t\t\tNhap ngay tra luong: ";
			date = getInt();
			cout << "\t\t\t\t\t\t\tNhap thang tra luong: ";
			month = getInt();
			cout << "\t\t\t\t\t\t\tNhap nam tra luong: ";
			year = getInt();
			Time timeslr(date, month, year);
			tmp.setTimeslr(timeslr);
			cout << "\t\t\t\t\t\t\tNhap luong co ban: ";
			salarybase = getInt();
			tmp.setSalaryBase(salarybase);
			cout << "\t\t\t\t\t\t\tNhap luong thuong them: ";
			bonus = getInt();
			tmp.setBonus(bonus);
			this->typeList->addslr(tmp);
			cout << "\t\t\t\t\t\t\tLuong da duoc them cho nhan vien!.\n";
		}
		else {
			do {
				cout << "\t\t\t\t\t\t\t\tMa nhan vien khong hop le!. Lua chon";
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
	} while (check == 1);
}