#include "Menu.h"

fstream fsst, fsdrt, fsfilm, fscr, fsscd, fstk;
StaffManager stMng;
DirectorManager drtMng;
FilmManager filmMng;
CinemaRoomManager cnmMng;
ScheduleManager scdMng(filmMng, cnmMng);
TicketManager tkMng(scdMng, stMng);

void Menu::login() {
	fsst.open("Staff.txt", ios::in);
	stMng.readFile(fsst);
	fsdrt.open("Director.txt", ios::in);
	drtMng.readFile(fsdrt);
	fsfilm.open("Film.txt", ios::in);
	filmMng.readFile(fsfilm);
	fscr.open("CinemaRoom.txt", ios::in);
	cnmMng.readFile(fscr);
	fsscd.open("Schedule.txt", ios::in);
	scdMng.readFile(fsscd);
	fstk.open("Ticket.txt", ios::in);
	tkMng.readFile(fstk);
	fsst.close();
	fsdrt.close();
	fsfilm.close();
	fscr.close();
	fsscd.close();
	fstk.close();
	int cnt = 0;
	do {
		system("cls"); 
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
			cout << "\n\n\n\t\t\t\tTAI KHOAN KHONG HOP LE.";
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
		cout << "\n\t\t\t\t4.Quan li ve";
		cout << "\n\t\t\t\t0.Thoat";
		cout << "\n\t\t\t\t**Nhap lua chon: ";;
		cin >> opt;
		switch (opt) {
		case (1): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQUAN LI PHIM";
				cout << "\n\t\t1.Them phim";
				cout << "\n\t\t2.Xem danh sach phim";
				cout << "\n\t\t3.Tim phim theo ten";
				cout << "\n\t\t4.Tim phim theo ma";
				cout << "\n\t\t5.Xoa phim";
				cout << "\n\t\t6.Cap nhap phim";
				cout << "\n\t\t7.Xac nhan cac thay doi";
				cout << "\n\t\t0.Quay lai mainmenu";
				cout << "\n\t\t**Nhap lua chon: ";
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
					cout << "\t\tNhap ten phim: ";
					cin.ignore();
					getline(cin, name);
					filmMng.findByName(name);
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "\t\tNhap ma phim: ";
					cin.ignore();
					getline(cin, id);
					if (filmMng.findById(id) == nullptr) {
						cout << "\n\t\tKhong tim thay phim phu hop.\n";
					}
					else {
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
						cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
						filmMng.findById(id)->writeData();
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 5) {
					string id;
					cout << "\t\tNhap ma phim can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (filmMng.findById(id) != nullptr) {
						cout << "\t\tPhim co ma " << id << " da duoc xoa.\n";
					}
					else cout << "\n\t\tKhong tim thay phim phu hop.\n";
					system("pause");
				}
				else if (tmp == 6) {
					filmMng.update();
				}
				else if (tmp == 7) {
					fsfilm.open("Film.txt", ios::out | ios::trunc);
					filmMng.writeFile(fsfilm);
					fsfilm.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\tLuu chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (2): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQUAN LI PHONG CHIEU";
				cout << "\n\t\t1.Them phong chieu";
				cout << "\n\t\t2.Xem danh sach phong chieu";
				cout << "\n\t\t3.Tim phong chieu theo ma";
				cout << "\n\t\t4.Xoa phong chieu";
				cout << "\n\t\t5.Cap nhap phong chieu";
				cout << "\n\t\t6.Xac nhan cac thay doi";
				cout << "\n\t\t0.Quay lai mainmenu";
				cout << "\n\t\t**Nhap lua chon: ";
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
					cout << "\t\tNhap ma phong chieu: ";
					cin.ignore();
					getline(cin, id);
					if (cnmMng.findById(id) == nullptr) {
						cnmMng.del(id);
						cout << "\n\t\tKhong tim thay phong chieu phu hop.\n";
					}
					else {
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
						cout << "|" << left << setw(6) << " " << left << setw(20) << "Ma phong chieu" << "|" << left << setw(10) << "\tSo ghe" << "|" << left << setw(30) << "\t        Chat luong" << "|" << endl;
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
						cnmMng.findById(id)->writeData();
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "\t\tNhap ma phong chieu can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (cnmMng.findById(id) != nullptr) {
						cnmMng.del(id);
						cout << "\t\tPhong chieu co ma " << id << " da duoc xoa.\n";
					}
					else cout << "\n\t\tKhong tim thay phong chieu phu hop.\n";
					system("pause");
				}
				else if (tmp == 5) {
					cnmMng.update();
				}
				else if (tmp == 6) {
					fscr.open("CinemaRoom.txt", ios::out | ios:: trunc);
					cnmMng.writeFile(fscr);
					fscr.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\n\t\tLua chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (3): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQUAN LI LICH CHIEU";
				cout << "\n\t\t1.Them lich chieu";
				cout << "\n\t\t2.Xem danh sach lich chieu";
				cout << "\n\t\t3.Tim lich chieu theo ma";
				cout << "\n\t\t4.Xoa lich chieu";
				cout << "\n\t\t5.Cap nhap lich chieu";
				cout << "\n\t\t6.Xac nhan cac thay doi";
				cout << "\n\t\t0.Quay lai mainmenu";
				cout << "\n\t\t**Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					Schedule tmp = scdMng.setScheduleInfor();
					if(tmp.getId() == "null") {}
					else { 
						scdMng.add(tmp); 
						cout << "\t\tLich chieu moi da duoc them.\n";
						system("pause");
					}
				}
				else if (tmp == 2) {
					scdMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string id;
					cout << "\t\tNhap ma lich chieu: ";
					cin.ignore();
					getline(cin, id);
					if (scdMng.findById(id) == nullptr) {
						cout << "\n\t\tKhong tim thay lich chieu phu hop.\n";
					}
					else {
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
						cout << "|  Ma lich chieu  |   Ma phim   |  Ma phong chieu  |  Ca  |     Ngay chieu     |" << endl;
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
						scdMng.findById(id)->writeData();
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "\t\tNhap ma lich chieu can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (scdMng.findById(id) != nullptr) {
						scdMng.del(id);
						cout << "\t\tLich chieu co ma " << id << " da duoc xoa.\n";
					}
					else cout << "\n\t\tKhong tim thay lich chieu phu hop.\n";
					system("pause");
				}
				else if (tmp == 5) {
					scdMng.update();
				}
				else if (tmp == 6) {
					fsscd.open("Schedule.txt", ios::out | ios::trunc);
					scdMng.writeFile(fsscd);
					fsscd.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (4): {
			int tmp = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\t\tQUAN LI VE";
				cout << "\n\t\t1.Xuat ve";
				cout << "\n\t\t2.Xem danh sach ve";
				cout << "\n\t\t3.Xuat doanh thu theo thoi gian";
				cout << "\n\t\t4.Xuat doanh thu theo nhan vien";
				cout << "\n\t\t5.Xuat tong doanh thu";
				cout << "\n\t\t6.Xoa ve";
				cout << "\n\t\t7.Xac nhan cac thay doi";
				cout << "\n\t\t0.Quay lai mainmenu";
				cout << "\n\t\t**Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					Ticket tmp = tkMng.setTicketInfor();
					if (tmp.getId() == "null") {}
					else {
						tkMng.add(tmp);
						cout << "\t\tDa ban 1 ve moi.\n";
						system("pause");
					}
				}
				else if (tmp == 2) {
					tkMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					int date;
					int month;
					int year;
					cout << "\tNhap ngay bat dau: ";
					cin >> date;
					cout << "\tNhap thang bat dau: ";
					cin >> month;
					cout << "\tNhap nam bat dau: ";
					cin >> year;
					Time t1(date, month, year);
					cout << "\tNhap ngay ket thuc: ";
					cin >> date;
					cout << "\tNhap thang ket thuc: ";
					cin >> month;
					cout << "\tNhap nam ket thuc: ";
					cin >> year;
					Time t2(date, month, year);
					tkMng.getRevenue(t1, t2);
					system("pause");
				}
				else if (tmp == 4) {
					int opt4 = 0;
					string id;
					do {
						cout << "\t\tNhap ma nhan vien: ";fflush(stdin);
						getline(cin, id);
						if (stMng.findById(id) == nullptr) {
							cout << "\t\tMa nhan vien khong hop le. Moi nhap lai.\n";
							opt4 = 1;
						} else {
							opt4 = 0;
						}
					} while (opt4 == 1);
					tkMng.getRevenue(id);
					system("pause");
				}
				else if (tmp == 5) {
					tkMng.getRevenue();
					system("pause");
				}
				else if (tmp == 6) {
					string id;
					cout << "\t\tNhap ma ve can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (tkMng.findById(id) != nullptr) {
						tkMng.del(id);
						cout << "\t\tVe co ma " << id << " da duoc xoa.\n";
					}
					else cout << "\n\t\tKhong tim thay ve phu hop.\n";
					system("pause");
				}
				else if (tmp == 7) {
					fstk.open("Ticket.txt", ios::out | ios::trunc);
					tkMng.writeFile(fstk);
					fstk.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (0): {	break; }
		default: {
			cout << "\t\tLua chon khong hop le.\n";
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
		cout << "\n\t\t\t\t**Nhap lua chon: ";
		cin >> opt;
		switch (opt) {
		case (1): {
			int opt1 = 0;
			do {
				system("cls");
				cout << "\t\t\t\t\tQUAN LI NHAN VIEN";
				cout << "\n\t\t1.Xem thong tin nhan vien";
				cout << "\n\t\t2.Xem thong tin nhan than";
				cout << "\n\t\t3.Them nhan vien";
				cout << "\n\t\t4.Xoa nhan vien";
				cout << "\n\t\t5.Cap nhat thong tin nhan vien";
				//cout << "\n\t\t6.Xem luong nhan vien";
				//cout << "\n\t\t7.Cap nhat luong nhan vien";
				cout << "\n\t\t6.Xac nhan thay doi";
				cout << "\n\t\t0.Thoat";
				cout << "\n\t\t**Nhap lua chon: ";
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
					cout << "\t\tNhap ma nhan vien can xoa: ";
					cin.ignore();
					getline(cin, id);
					int tmp4 = stMng.getLength();
					stMng.del(id);
					if (tmp4 == stMng.getLength()) cout << "\t\tKhong tim thay nhan vien phu hop.\n";
					else cout << "\t\tNhan vien co ma " << id << " da duoc xoa.\n";
					system("pause");
				}
				else if (opt1 == 5) {
					stMng.update();
				}
				else if (opt1 == 6) {
					fsst.open("Staff.txt", ios::out | ios::trunc);
					stMng.writeFile(fsst);
					fsst.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt1 != 0) cout << "\t\tLua chon khong hop le. Moi nhap lai.\n";
			} while (opt1 != 0);
			break;
		}
		case (2): {
			int opt2;
			do {
				system("cls");
				cout << "\t\t\t\t\tTHONG TIN QUAN LI";
				cout << "\n\t\t1.Xem thong tin quan li";
				cout << "\n\t\t2.Doi tai khoan";
				cout << "\n\t\t3.Doi mat khau";
				cout << "\n\t\t4.Xac nhan thay doi";
				cout << "\n\t\t0.Thoat";
				cout << "\n\t\t**Nhap lua chon: ";
				cin >> opt2;
				if (opt2 == 1) { drtMng.write(); system("pause"); }
				else if (opt2 == 2) { drtMng.updateAc(); system("pause"); }
				else if (opt2 == 3) { drtMng.updatePq(); system("pause"); }
				else if (opt2 == 4) {
					fsdrt.open("Director.txt", ios::out | ios::trunc);
					drtMng.writeFile(fsdrt);
					fsdrt.close();
					cout << "\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt != 0) cout << "\t\tLua chon khong hop le.\n";
			} while (opt2 != 0);
			break;
		}
		case (0): { break; }
		default: {
			cout << "\t\tLua chon khong hop le.\n";
			break; 
		}
		}
	} while (opt != 0);
}