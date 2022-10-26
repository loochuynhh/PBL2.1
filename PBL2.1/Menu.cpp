#include "Menu.h"

fstream fsst, fsdrt, fsfilm, fscr;
StaffManager stMng;
DirectorManager drtMng;
FilmManager filmMng;
CinemaRoomManager cnmMng;
ScheduleManager scdMng(filmMng, cnmMng);
TicketManager tkMng(scdMng);

void Menu::login() {
	fsst.open("Staff.txt", ios::in | ios::out);
	stMng.readFile(fsst);
	fsdrt.open("Director.txt", ios::in | ios::out);
	drtMng.readFile(fsdrt);
	fsfilm.open("Film.txt", ios::in | ios::out);
	filmMng.readFile(fsfilm);
	fscr.open("CinemaRoom.txt", ios::in | ios::out);
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
		char pas;
		cout << "\n\t\t\t\t" << left << setw(16) << "TEN DANG NHAP" << ":   ";
		getline(cin, account);
		cout << "\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t" << left << setw(16) << "MAT KHAU" << ":   ";
		while (true) {
			pas = _getch();
			if (pas == 13) break;
			if (pas == 8) cout << "\b \b" ; 
			else {
				password.push_back(pas);
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
					if (filmMng.findById(id) != nullptr) filmMng.findById(id)->writeData();
					for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					system("pause");
				}
				else if (tmp == 5) {
					string id;
					cout << "Nhap ma phim: ";
					getline(cin, id);
					filmMng.del(id);
				}
				else if (tmp == 6) {
					filmMng.update();
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
					getline(cin, id);
					cout << cnmMng.findById(id)->getId() << endl;
				}
				else if (tmp == 4) {
					string id;
					cout << "Nhap ma phong chieu: ";
					getline(cin, id);
					cnmMng.del(id);
				}
				else if (tmp == 5) {
					cnmMng.update();
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
			cout << "\n\t\t\t1.Xem thong tin nhan vien";
			cout << "\n\t\t\t2.Xem thong tin nhan than";
			cout << "\n\t\t\t3.Them nhan vien";
			cout << "\n\t\t\t4.Xoa nhan vien";
			cout << "\n\t\t\t5.Cap nhat thong tin nhan vien";
			cout << "\n\t\t\t6.Xem luong nhan vien";
			cout << "\n\t\t\t7.Cap nhat luong nhan vien";
			cout << "\n\t\t\t0.Thoat";
			cout << "\n\t\t\t\tNhap lua chon: ";
			int opt1; cin >> opt1;
			if (opt1 == 1) stMng.write();
			system("pause");
			break;
		}
		case (2): {
			cout << "\n\t\t\t\t1.Xem thong tin quan li";
			cout << "\n\t\t\t\t2.Doi mat khau";
			cout << "\n\t\t\t\t0.Thoat";
			cout << "\n\t\t\t\tNhap lua chon: ";
			int opt2; cin >> opt2;
			if (opt2 == 1) drtMng.write();
			system("pause");
			break;
		}
		}
	} while (opt != 0);
}