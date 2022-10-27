#include "Menu.h"

fstream fsst, fsdrt, fsfilm, fscr;
StaffManager stMng;
DirectorManager drtMng;
FilmManager filmMng;
CinemaRoomManager cnmMng;
ScheduleManager scdMng(filmMng, cnmMng);
TicketManager tkMng(scdMng);

void Menu::login() {
	fsst.open("Staff.txt", ios::in);
	stMng.readFile(fsst);
	fsdrt.open("Director.txt", ios::in);
	drtMng.readFile(fsdrt);
	fsfilm.open("Film.txt", ios::in);
	filmMng.readFile(fsfilm);
	fscr.open("CinemaRoom.txt", ios::in);
	cnmMng.readFile(fscr);
	fsst.close();
	fsdrt.close();
	fsfilm.close();
	fscr.close();
	int cnt = 0;
	do {
		system("cls"); fflush(stdin);
		cout << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n" << left << setw(70) << " " << "|";
		cout << left << setw(12) << " " << "DANG NHAP";
		cout << setw(12) << " " << "|";
		cout << "\n" << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		string account, password;
		char pas, pass; int c = 0;
		cout << "\n\t\t\t\t" << left << setw(16) << "TEN DANG NHAP" << ":   ";
		getline(cin, account);
		cout << "\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t" << left << setw(16) << "MAT KHAU" << ":   ";
		while (true) {
			pas = _getch();
			if (pas == 13) break;
			if (pas == 8 && c > 0) {
				cout << "\b \b";
				password.resize(password.size() - 1);
				c--;
			}
			else if (pas == 8 && c == 0) {}
			else {
				c++;
				pass = pas;
				password.push_back(pass);
				cout << "*";
			}
		}
		for (int i = 0; i < stMng.getLength(); i++) {
			if (account.compare((stMng.getTypeList() + i)->getAccount()) == 0 && password.compare((stMng.getTypeList() + i)->getPassword()) == 0) {
				cnt = 1;
			}
		}
		if (cnt != 1) {
			for (int i = 0; i < drtMng.getLength(); i++) {
				if (account.compare((drtMng.getTypeList() + i)->getAccount()) == 0 && password.compare((drtMng.getTypeList() + i)->getPassword()) == 0) {
					cnt = 2;
				}
			}
		}
		if (cnt == 0) {
			cout << "\n\n\n\t\t\t\tTai Khoan Khong Hop Le.";
			cout << "\n\t\t\t\t1. Dang Nhap Lai.";
			cout << "\n\t\t\t\t2. Thoat";
			cout << "\n\t\t\t\t";
			int x; cin >> x;
			if (x == 2) break;
			cin.ignore();
		}
	} while (cnt == 0);
	if (cnt == 1) {
		stMenu();
	}
	else if (cnt == 2) {
		drtMenu();
	}
}
void Menu::stMenu() {
	int opt = 0;
	do {
		system("cls");
		cout << endl;
		cout << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n" << left << setw(70) << " " << "|";
		cout << left << setw(14) << " " << "MENU";
		cout << setw(15) << " " << "|";
		cout << "\n" << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\t\t\t\t1.Quan li phim";
		cout << "\n\t\t\t\t2.Quan li phong chieu";
		cout << "\n\t\t\t\t3.Quan li lich chieu";
		cout << "\n\t\t\t\t4.Quan li hoa don";
		cout << "\n\t\t\t\t0.Thoat";
		cout << "\n\t\t\t\tNhap lua chon: ";;
		cin >> opt;
		switch (opt) {
		case (1): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQuan li phim";
				cout << "\n\t1.Them phim";
				cout << "\n\t2.Xem danh sach phim";
				cout << "\n\t3.Tim phim theo ten";
				cout << "\n\t4.Tim phim theo ma";
				cout << "\n\t5.Xoa phim";
				cout << "\n\t6.Cap nhap phim";
				cout << "\n\t7.Xac nhan cac thay doi";
				cout << "\n\t0.Quay lai mainmenu";
				cout << "\nNhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					filmMng.add(filmMng.setFilmInfor());
				}
				else if (tmp == 2) {
					filmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string name;
					cout << "Nhap ten phim: ";
					cin.ignore();
					getline(cin, name);
					filmMng.findByName(name);
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "Nhap ma phim: ";
					cin.ignore();
					getline(cin, id);
					for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
					for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					if (filmMng.findById(id) != nullptr) filmMng.findById(id)->writeData();
					for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					system("pause");
				}
				else if (tmp == 5) {
					string id;
					cout << "Nhap ma phim can xoa: ";
					cin.ignore();
					getline(cin, id);
					int tmp5 = filmMng.getLength();
					filmMng.del(id);
					if (tmp5 == filmMng.getLength()) cout << "\n Khong tim thay phim phu hop.";
					else cout << " Phim co ma " << id << " da duoc xoa.";
					system("pause");
				}
				else if (tmp == 6) {
					filmMng.update();
				}
				else if (tmp == 7) {
					fsfilm.open("Film.txt", ios::out | ios::trunc);
					filmMng.writeFile(fsfilm);
					fsfilm.close();
					cout << "Thay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << " Luu chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (2): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQuan li phong chieu";
				cout << "\n\t1.Them phong chieu";
				cout << "\n\t2.Xem danh sach phong chieu";
				cout << "\n\t3.Tim phong chieu theo ma";
				cout << "\n\t4.Xoa phong chieu";
				cout << "\n\t5.Cap nhap phong chieu";
				cout << "\n\t5.Xac nhan cac thay doi";
				cout << "\n\t0.Quay lai mainmenu";
				cout << "\nNhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					cnmMng.add(cnmMng.setCinemaRoomInfor());
				}
				else if (tmp == 2) {
					cnmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string id;
					cout << "Nhap ma phong chieu: ";
					cin.ignore();
					getline(cin, id);
					for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					cout << "|" << left << setw(6) << " " << left << setw(20) << "Ma phong chieu" << "|" << left << setw(10) << "\tSo ghe" << "|" << left << setw(30) << "\t        Chat luong" << "|" << endl;
					for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					if(cnmMng.findById(id) != nullptr) cnmMng.findById(id)->writeData();
					for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "Nhap ma phong chieu can xoa: ";
					cin.ignore();
					getline(cin, id);
					int tmp4 = cnmMng.getLength();
					cnmMng.del(id);
					if (tmp4 == cnmMng.getLength()) cout << "\n Khong tim thay phong chieu phu hop.";
					else cout << " Phong chieu co ma " << id << " da duoc xoa.";
					system("pause");
				}
				else if (tmp == 5) {
					cnmMng.update();
				}
				else if (tmp == 6) {
					fscr.open("CinemaRoom.txt", ios::out | ios:: trunc);
					cnmMng.writeFile(fscr);
					fscr.close();
					cout << "Thay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\nLua chon khong hop le. Moi chon lai.";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (3): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQuan li lich chieu";
				cout << "\n\t1.Them lich chieu";
				cout << "\n\t2.Xem danh sach lich chieu";
				cout << "\n\t3.Tim lich chieu theo ma";
				cout << "\n\t4.Xoa lich chieu";
				cout << "\n\t5.Cap nhap lich chieu";
				cout << "\n\t0.Quay lai mainmenu";
				cout << "\nNhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					scdMng.add(scdMng.setScheduleInfor());
				}
				else if (tmp == 2) {
					scdMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string id;
					cout << "Nhap ma lich chieu: ";
					getline(cin, id);
					cout << scdMng.findById(id)->getId() << endl;
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "Nhap ma lich chieu: ";
					getline(cin, id);
					scdMng.del(id);
				}
				else if (tmp == 5) {
					scdMng.update();
				}
			} while (tmp != 0);
			break;
		}
		case (4): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQuan li ve";
				cout << "\n\t1.Xuat ve";
				cout << "\n\t2.Xem danh sach ve";
				cout << "\n\t3.Xuat doanh thu theo ngay";
				cout << "\n\t4.Xuat doanh thu theo nhan vien";
				cout << "\n\t5.Xuat tong doanh thu";
				cout << "\n\t6.Xoa ve";
				cout << "\n\t0.Quay lai mainmenu";
				cout << "\nNhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					tkMng.add(tkMng.setTicketInfor());
				}
				else if (tmp == 2) {
					tkMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					int date;
					int month;
					int year;
					cout << "Nhap ngay bat dau: ";
					cin >> date;
					cout << "Nhap thang bat dau: ";
					cin >> month;
					cout << "Nhap nam bat dau: ";
					cin >> year;
					Time t1(date, month, year);
					cout << "Nhap ngay ket thuc: ";
					cin >> date;
					cout << "Nhap thang ket thuc: ";
					cin >> month;
					cout << "Nhap nam ket thuc: ";
					cin >> year;
					Time t2(date, month, year);
					tkMng.getRevenue(t1, t2);
				}
				else if (tmp == 4) {
					string id;
					cout << "Nhap ma nhan vien: ";
					getline(cin, id);
					tkMng.getRevenue(id);
				}
				else if (tmp == 5) {
					tkMng.getRevenue();
				}
				else if (tmp == 6) {
					string id;
					cout << "Nhap ma ve: ";
					getline(cin, id);
					tkMng.del(id);
				}
			} while (tmp != 0);
			break;
		}
		}
	} while (opt != 0);
}

void Menu::drtMenu() {
	int opt = 0;
	do {
		system("cls");
		cout << endl;
		cout << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n" << left << setw(70) << " " << "|";
		cout << left << setw(14) << " " << "MENU";
		cout << setw(15) << " " << "|";
		cout << "\n" << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\t\t\t\t1.Quan li nhan vien";
		cout << "\n\t\t\t\t2.Thong tin quan li";
		cout << "\n\t\t\t\t0.Thoat";
		cout << "\n\t\t\t\tNhap lua chon: ";
		cin >> opt;
		switch (opt) {
		case (1): {
			int opt1 = 0;
			do {
				cout << "\n\t\t\t\t1.Xem thong tin nhan vien";
				cout << "\n\t\t\t\t2.Xem thong tin nhan than";
				cout << "\n\t\t\t\t3.Them nhan vien";
				cout << "\n\t\t\t\t4.Xoa nhan vien";
				cout << "\n\t\t\t\t5.Cap nhat thong tin nhan vien";
				//cout << "\n\t\t\t6.Xem luong nhan vien";
				//cout << "\n\t\t\t7.Cap nhat luong nhan vien";
				cout << "\n\t\t\t\t0.Thoat";
				cout << "\n\t\t\t\tNhap lua chon: ";
				cin >> opt1;
				if (opt1 == 1) {
					system("cls");
					stMng.write();
					system("pause");
				}
				else if (opt1 == 2) {
					system("cls");
					stMng.writerl();
					system("pause");
				}
				else if (opt1 == 3) {
					stMng.add(stMng.setStaff());
				}
				else if (opt1 == 4) {
					string id;
					cout << "Nhap ma nhan vien can xoa: ";
					cin.ignore();
					getline(cin, id);
					int tmp4 = stMng.getLength();
					stMng.del(id);
					if (tmp4 == stMng.getLength()) cout << "\nKhong tim thay nhan vien phu hop.";
					else cout << "Nhan vien co ma " << id << " da duoc xoa.";
					system("pause");
				}
				else if (opt1 == 5) {
					stMng.update();
				}
				else if (opt1 != 0) cout << "Lua chon khong hop le. Moi nhap lai.";
			} while (opt1 != 0);
			break;
		}
		case (2): {
			int opt2;
			do {
				cout << "\n\t\t\t\t1.Xem thong tin quan li";
				cout << "\n\t\t\t\t2.Doi mat khau";
				cout << "\n\t\t\t\t0.Thoat";
				cout << "\n\t\t\t\tNhap lua chon: ";
				cin >> opt2;
				if (opt2 == 1) { drtMng.write(); system("pause"); }
				
			} while (opt2 != 0);
			break;
		}
		}
	} while (opt != 0);
}