#include "Menu.h"
#include <Windows.h>

fstream fsst, fsdrt, fsfilm, fscr, fsscd, fstk, fsslr;
StaffManager stMng;
DirectorManager drtMng;
FilmManager filmMng;
CinemaRoomManager cnmMng;
ScheduleManager scdMng(filmMng, cnmMng);
TicketManager tkMng(scdMng, stMng);
HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu::logo() {
	SetConsoleTextAttribute(cl, 6);
	Sleep(30);
	cout << "\n\t                                                                                                      ..   .J#@@~@@J# ";
	Sleep(30);
	cout << "\n\t                                                                                                  .JB@@@&G!.  ~PP.@@@ ";
	Sleep(30);
	cout << "\n\t                                                                                          7G#&@&Y^  .7G@@@@@&Y^ .@@PJ ";
	Sleep(30);
	cout << "\n\t                                                                                 ~YB#&B?:  :Y#@@@@@B?.  ^5#BGJ!.^^^   ";
	Sleep(30);
	cout << "\n\t                                                                        ^7YG#G!. .~P&@@@@&P~. .!G&&#P?.               ";
	Sleep(30);
	cout << "\n\t                                                               .~7YG5^  .7#@@@@@#J:  .?B@@&#Y:                        ";
	Sleep(30);
	cout << "\n\t                                                      .:^!J?:  :Y&@@@@@B7.  ^5&@@@&P^                                 ";
	Sleep(30);
	cout << "\n\t                                              ..^7!.  :5&@@@@&P~  .!G&@@@@P^   ..                                     ";
	Sleep(30);
	cout << "\n\t                                             ^P&@@@@#J:  .?B@@@@@G^   ^^.                                             ";
	Sleep(30);
	cout << "\n\t                                             7.  ^Y&@@@@&P^  .~!^..                                                   ";
	Sleep(30);
	cout << "\n\t                                             #@&5:  .7J!^:.                                                           ";
	Sleep(30);
	cout << "\n\t                                             .Y7~..    .....    .....     ....     ....     .....    .....     ...... ";
	Sleep(30);
	cout << "\n\t                                             G@@G:  ?&@@@#~  ~&@@@&7  ^B@@@@Y  .P@@@@G.  J&@@@B^  !&@@@&!  ^B@@@&J    ";
	Sleep(30);
	cout << "\n\t                                             .  J@@@@#~  !&@@@&?  ^B@@@@5. .P@@@@G: .Y@@@@#~  7&@@@&?  ~#@@@@Y. :G@@J ";
	Sleep(30);
	cout << "\n\t                                               .^^:^:    ^^:::    ^^^:^    :^^:^.   .^^:^.   .^^:::    ^^^:^    :^^^. ";
	Sleep(30);
	cout << "\n\t                                             !YJ?????JJJJ?????JJJJ?????JJJJ??????JJJJ?????JJJJ?????JJJJ?????JJJJ????: ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@BJG@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.   :J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.      .~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.          .7G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.              :?#@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                  ~5&@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                    :@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                 ^5&@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.             :?B@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.         .!G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.     .~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@:  :J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@&B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@? ";
	Sleep(30);
	cout << "\n\t                                              .P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&J   ";
	Sleep(30);
	cout << "\n\t                                                 .::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.     ";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 8);
	for (int i = 0; i < 21; i++) {
		cout << i * 5 << "%  LOADING ...";
		cout.flush();
		Sleep(100);
		if (i == 0 || i == 1) cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		else if (i == 20) cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		else cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
}
void Menu::cinema() {
	cout << endl;
	cout << "\t\t\t\t\t\t\t ______    ________  ___   __    ______   ___ __ __   ________      " << endl;
	cout << "\t\t\t\t\t\t\t/_____/\\  /_______/\\/__/\\ /__/\\ /_____/\\ /__//_//_/\\ /_______/\\     " << endl;
	cout << "\t\t\t\t\t\t\t\\:::__\\/  \\__.::._\\/\\::\\_\\\\  \\ \\\\::::_\\/_\\::\\| \\| \\ \\\\::: _  \\ \\    " << endl;
	cout << "\t\t\t\t\t\t\t \\:\\ \\  __   \\::\\ \\  \\:. `-\\  \\ \\\\:\\/___/\\\\:.      \\ \\\\::(_)  \\ \\   " << endl;
	cout << "\t\t\t\t\t\t\t  \\:\\ \\/_/\\  _\\::\\ \\__\\:. _    \\ \\\\::___\\/_\\:.\\-/\\  \\ \\\\:: __  \\ \\  " << endl;
	cout << "\t\t\t\t\t\t\t   \\:\\_\\ \\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\\\:\\____/\\\\. \\  \\  \\ \\\\:.\\ \\  \\ \\ " << endl;
	cout << "\t\t\t\t\t\t\t    \\_____\\/\\________\\/ \\__\\/ \\__\\/ \\_____\\/ \\__\\/ \\__\\/ \\__\\/\\__\\/ " << endl << endl; 
}
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
	fsslr.open("Salary.txt", ios::in);
	stMng.readSalaryFile(fsslr);
	fsst.close();
	fsdrt.close();
	fsfilm.close();
	fscr.close();
	fsscd.close();
	fstk.close();
	fsslr.close();
	int cnt = 0;
	logo();
	system("cls");
	do {
		system("cls");
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 7);
		cout << endl;
		cout << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n" << left << setw(70) << " " << "|";
		cout << left << setw(12) << " " << "DANG NHAP";
		cout << setw(12) << " " << "|";
		cout << "\n" << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << endl;
		string account, password;
		char pas, pass; int c = 0;
		cout << "\n\t\t\t\t\t\t\t\t" << left << setw(16) << "TEN DANG NHAP" << ":   ";
		getline(cin, account);
		cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(16) << "MAT KHAU" << ":   ";
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
			cout << "\n\n\n\t\t\t\t\t\t\t\t\tTAI KHOAN KHONG HOP LE.";
			cout << "\n\n\t\t\t\t\t\t\t\t1. Dang Nhap Lai.";
			cout << "\t\t  2. Thoat";
			cout << "\n\t\t\t\t\t\t\t\t\t\t";
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
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 14);
		cout << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		Sleep(50);
		cout << "\n" << left << setw(70) << " " << "|";
		Sleep(50);
		cout << left << setw(14) << " " << "MENU";
		Sleep(50);
		cout << setw(15) << " " << "|";
		Sleep(50);
		cout << "\n" << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\n\t\t\t\t\t\t\t\t";
		Sleep(50);
		SetConsoleTextAttribute(cl, 7);
		for (int i = 0; i < 42; i++) cout << "-"; cout << "\n";
		cout << "\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 1. Quan li phim" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 2. Quan li phong chieu" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 3. Quan li lich chieu" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 4. Quan li hoa don" << "|"; 
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 0. Thoat" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		for (int i = 0; i < 42; i++) cout << "-";
		Sleep(50);
		cout << "\n\n\t\t\t\t\t\t\t\t\t**Nhap lua chon: ";
		cin >> opt;
		switch (opt) {
		case (1): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI PHIM";
				cout << setw(20) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim phim theo ten";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Tim phim theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Xoa phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Cap nhat phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM PHIM MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Film film = filmMng.setFilmInfor();
					if(film.getId() != "null") {
						filmMng.add(film);
						cout << "\t\t\t\t\t\t\t\t\tPhim da duoc them.\n"; system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH PHIM CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					filmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***TIM PHIM THEO TEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string name;
					cout << "\t\t\t\t\t\t\tNhap ten phim: ";
					cin.ignore();
					getline(cin, name);
					filmMng.findByName(name);
					system("pause");
				}
				else if (tmp == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***TIM PHIM THEO MA***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phim: ";
					cin.ignore();
					getline(cin, id);
					if (filmMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phim phu hop.\n";
					}
					else {
						cout << "\n\t\t\t\t\t\t\t\t\t<<PHIM CO MA TREN LA>>\n\n";
						cout << "\t";
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
						cout << "\t";
						cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
						cout << "\t";
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
						cout << "\t";
						filmMng.findById(id)->writeData();
						cout << "\t";
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA PHIM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phim can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (filmMng.findById(id) != nullptr) {
						SetConsoleTextAttribute(cl, 4);
						cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI CAC PHIM BI XOA CUNG SE DUOC XOA TRONG LICH CHIEU\n";
						SetConsoleTextAttribute(cl, 7);
						cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; cin >> idel;
						if (idel == 1) {
							filmMng.del(id);
							scdMng.deleteByFilm(id);
							cout << "\t\t\t\t\t\t\tPhim co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phim phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT PHIM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					filmMng.update();
				}
				else if (tmp == 7) {
					fsfilm.open("Film.txt", ios::out | ios::trunc);
					filmMng.writeFile(fsfilm);
					fsfilm.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					int test, iscd = 0;
					while (iscd < scdMng.getLength()) {
						test = 0;
						for (int ifilm = 0; ifilm < filmMng.getLength(); ifilm++) {
							if ((scdMng.getTypeList() + iscd)->getFilmId().compare((filmMng.getTypeList() + ifilm)->getId()) == 0) {
								test = 1;
						    }
						}
						if (test == 0) { 
							scdMng.del((scdMng.getTypeList() + iscd)->getId());
							iscd--;
						}
						iscd++;
					}
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLuu chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (2): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI PHONG CHIEU";
				cout << setw(13) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim phong chieu theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Cap nhat phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM PHONG CHIEU MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					CinemaRoom cM = cnmMng.setCinemaRoomInfor();
					if(cM.getId() != "null") {
						cnmMng.add(cM);
						cout << "\t\t\t\t\t\t\tPhong chieu da duoc them.\n"; system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH PHONG CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					cnmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***TIM PHONG CHIEU THEO MA***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phong chieu: ";
					cin.ignore();
					getline(cin, id);
					if (cnmMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phong chieu phu hop.\n";
					}
					else {
						cout << "\n\t\t\t\t\t\t\t\t\t<<PHONG CHIEU CO MA TREN LA>>\n\n";
						cout << "\t\t\t\t\t\t";
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
						cout << "\t\t\t\t\t\t";
						cout << "|" << left << setw(6) << " " << left << setw(20) << "Ma phong chieu" << "|" << left << setw(10) << "\tSo ghe" << "|" << left << setw(30) << "\t        Chat luong" << "|" << endl;
						cout << "\t\t\t\t\t\t";
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
						cout << "\t\t\t\t\t\t";
						cnmMng.findById(id)->writeData();
						cout << "\t\t\t\t\t\t";
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA PHONG CHIEU***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phong chieu can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (cnmMng.findById(id) != nullptr) {
						SetConsoleTextAttribute(cl, 4);
						cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI CAC PHONG CHIEU BI XOA CUNG SE DUOC XOA TRONG LICH CHIEU\n";
						SetConsoleTextAttribute(cl, 7);
						cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; cin >> idel;
						if(idel == 1){
							cnmMng.del(id);
							scdMng.deleteByRoom(id);
							cout << "\t\t\t\t\t\t\tPhong chieu co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phong chieu phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT PHONG CHIEU***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id = cnmMng.update();
					if(id != "" && cnmMng.findById(id)->getStatus() == "bad") {
						scdMng.deleteByRoom(id);
					}
				}
				else if (tmp == 6) {
					fscr.open("CinemaRoom.txt", ios::out | ios:: trunc);
					cnmMng.writeFile(fscr);
					fscr.close();
					cout << "\t\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					int test, iscd = 0;
					while (iscd < scdMng.getLength()) {
						test = 0;
						for (int icnm = 0; icnm < cnmMng.getLength(); icnm++) {
							if ((scdMng.getTypeList() + iscd)->getCinemaRoomId().compare((cnmMng.getTypeList() + icnm)->getId()) == 0) {
								test = 1;
							}
						}
						if (test == 0) { 
							scdMng.del((scdMng.getTypeList() + iscd)->getId()); 
							iscd--;
						}
						iscd++;
					}
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\n\t\t\t\t\t\t\tLua chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (3): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI LICH CHIEU";
				cout << setw(14) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim lich chieu theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Cap nhat lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				cout << "\n\n\t\t\t\t\t\t\t\t";
				Sleep(50);
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM LICH CHIEU MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Schedule tmp = scdMng.setScheduleInfor();
					if(tmp.getId() == "null") {}
					else { 
						scdMng.add(tmp); 
						cout << "\t\t\t\t\t\t\tLich chieu moi da duoc them.\n";
						system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH LICH CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					scdMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma lich chieu: ";
					cin.ignore();
					getline(cin, id);
					if (scdMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay lich chieu phu hop.\n";
					}
					else {
						cout << "\n\t\t\t\t\t\t\t\t\t<<LICH CHIEU CO MA TREN LA>>\n\n";
						cout << "\t\t\t\t\t";
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
						cout << "\t\t\t\t\t";
						cout << "|  Ma lich chieu  |   Ma phim   |  Ma phong chieu  |  Ca  |     Ngay chieu     |" << endl;
						cout << "\t\t\t\t\t";
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
						cout << "\t\t\t\t\t";
						scdMng.findById(id)->writeData();
						cout << "\t\t\t\t\t";
						for (int x = 0; x < 80; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma lich chieu can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (scdMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; cin >> idel;
						if (idel == 1) {
							scdMng.del(id);
							cout << "\t\t\t\t\t\t\tLich chieu co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else{}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay lich chieu phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT LICH CHIEU***\n\n";
					SetConsoleTextAttribute(cl, 7);
					scdMng.update();
				}
				else if (tmp == 6) {
					fsscd.open("Schedule.txt", ios::out | ios::trunc);
					scdMng.writeFile(fsscd);
					fsscd.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\n\t\t\t\t\t\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (4): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI HOA DON";
				cout << setw(17) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xuat hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Xuat doanh thu theo thoi gian";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xuat doanh thu theo nhan vien";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Xuat tong doanh thu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xoa hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Xuat doanh thu theo nam tung nhan vien";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t8. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay Lai menu";
				cout << "\n\n\t\t\t\t\t\t\t\t";
				Sleep(50);
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> tmp;
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM HOA DON MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Ticket tmp = tkMng.setTicketInfor();
					if (tmp.getId() == "null") {}
					else {
						tkMng.add(tmp);
						cout << "\t\t\t\t\t\t\tDa ban 1 hoa don moi.\n";
						system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH HOA DON DA BAN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					tkMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					int date;
					int month;
					int year;
					cout << "\t\t\t\t\t\t\tNhap ngay bat dau: ";
					cin >> date;
					cout << "\t\t\t\t\t\t\tNhap thang bat dau: ";
					cin >> month;
					cout << "\t\t\t\t\t\t\tNhap nam bat dau: ";
					cin >> year;
					Time t1(date, month, year);
					cout << "\t\t\t\t\t\t\tNhap ngay ket thuc: ";
					cin >> date;
					cout << "\t\t\t\t\t\t\tNhap thang ket thuc: ";
					cin >> month;
					cout << "\t\t\t\t\t\t\tNhap nam ket thuc: ";
					cin >> year;
					Time t2(date, month, year);
					cout << "\n\n\t\t\t\t\t\t\t>> DOANH THU TRONG THOI GIAN TREN LA: ";
					SetConsoleTextAttribute(cl, 10);
					cout << tkMng.getRevenue(t1, t2) << endl;
					SetConsoleTextAttribute(cl, 7);
					system("pause");
				}
				else if (tmp == 4) {
					int opt4 = 0;
					string id;
					do {
						cout << "\t\t\t\t\t\t\tNhap ma nhan vien: ";
						cin.ignore();
						getline(cin, id);
						if (stMng.findById(id) == nullptr) {
							cout << "\t\t\t\t\t\t\t\tKhong tim thay nhan vien phu hop!. Lua chon";
							cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
							cout << "\t\t\t2. Thoat";
							cout << "\n\t\t\t\t\t\t\t";
							cin >> opt4;
						}
						else opt4 = 3;
					} while (opt4 == 1 || opt4 == 0);
					if (opt4 != 3) {}
					else { 
						cout << "\n\n\t\t\t\t\t\t\t>> DOANH THU DO NHAN VIEN TREN TAO RA LA: ";
						SetConsoleTextAttribute(cl, 10);
						cout << tkMng.getRevenue(id) << endl;
						SetConsoleTextAttribute(cl, 7);
						system("pause");
					}
				}
				else if (tmp == 5) {
					cout << "\n\n\t\t\t\t\t\t\t>> TONG DOANH THU CUA RAP LA: ";
					SetConsoleTextAttribute(cl, 10);
					cout << tkMng.getRevenue() << endl;
					SetConsoleTextAttribute(cl, 7);
					system("pause");
				}
				else if (tmp == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***XOA HOA DON***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\n\t\t\t\t\t\t\tNhap ma hoa don can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (tkMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; cin >> idel;
						if (idel == 1) {
							tkMng.del(id);
							cout << "\t\t\t\t\t\t\tHoa don co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay hoa phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 7) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DOANH THU CHI TIET THEO NAM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					int year;
					cout << "\n\t\t\t\t\t\t\tNhap nam can thong ke doanh thu: ";
					cin >> year;
					SetConsoleTextAttribute(cl, 10);
					cout << "\n\n\t\t\t\t\t\t\t\t<<<DOANH THU CHI TIET NAM " << year << " LA>>>\n";
					SetConsoleTextAttribute(cl, 7);
					tkMng.getRevenueY(year);
					system("pause");
				}
				else if (tmp == 8) {
					fstk.open("Ticket.txt", ios::out | ios::trunc);
					tkMng.writeFile(fstk);
					fstk.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (0): {	break; }
		default: {
			cout << "\n\t\t\t\t\t\t\tLua chon khong hop le.\n";
			break;
		}
		}
	} while (opt != 0);
}

void Menu::drtMenu() {
	int opt = 0;
	do {
		system("cls");
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 14);
		cout << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		Sleep(50);
		cout << "\n" << left << setw(70) << " " << "|";
		Sleep(50);
		cout << left << setw(14) << " " << "MENU";
		Sleep(50);
		cout << setw(15) << " " << "|";
		Sleep(50);
		cout << "\n" << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\n\t\t\t\t\t\t\t\t";
		Sleep(50);
		SetConsoleTextAttribute(cl, 7);
		for (int i = 0; i < 42; i++) cout << "-"; cout << "\n";
		cout << "\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 1. Quan li nhan vien" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 2. Thong tin quan li" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 0. Thoat" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		for (int i = 0; i < 42; i++) cout << "-";
		Sleep(50);
		cout << "\n\n\t\t\t\t\t\t\t\t\t**Nhap lua chon: ";
		cin >> opt;
		switch (opt) {
		case (1): {
			int opt1 = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI NHAN VIEN";
				cout << setw(15) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xem thong tin nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem thong tin nhan than"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Them nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Cap nhat thong tin nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xem luong nhan vien theo nam"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Them (cap nhat) luong nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t8. Xac nhan thay doi"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Thoat"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> opt1;
				if (opt1 == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH NHAN VIEN LAM VIEC TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.write();
					system("pause");
				}
				else if (opt1 == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***THONG TIN NHAN THAN CUA NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.writerl();
					system("pause");
				}
				else if (opt1 == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM NHAN VIEN MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Staff staff = stMng.setStaff();
					if(staff.getId() != "null") {
						stMng.add(staff);
						cout << "\t\t\t\t\t\t\tNhan vien moi da duoc them.\n";
						system("pause");
					}
				}
				else if (opt1 == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma nhan vien can xoa: ";
					cin.ignore();
					getline(cin, id);
					if (stMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; cin >> idel;
						if (idel == 1) {
							stMng.del(id);
							cout << "\t\t\t\t\t\t\tNhan vien co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay nhan vien phu hop.\n";
						system("pause");
					}
				}
				else if (opt1 == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT THONG TIN NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.update();
				}
				else if (opt1 == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***LUONG NHAN VIEN CHI TIET THEO NAM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					int year;
					cout << "\t\t\t\t\t\t\tNhap nam muon xem luong: ";
					cin >> year;
					SetConsoleTextAttribute(cl, 10);
					cout << "\t\t\t\t\t\t\t\t\t<<<TIEN LUONG DA TRA TRONG NAM " << year << " LA>>> " << endl;
					SetConsoleTextAttribute(cl, 7);
					stMng.writeSalaryY(year);
					system("pause");
				}
				else if (opt1 == 7) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT LUONG NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.addSalary();
					system("pause");
				}
				else if (opt1 == 8) {
					fsst.open("Staff.txt", ios::out | ios::trunc);
					stMng.writeFile(fsst);
					fsst.close();
					fsslr.open("Salary.txt", ios::out | ios::trunc);
					stMng.writeSalaryFile(fsslr);
					fsslr.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt1 != 0) cout << "\n\t\t\t\t\t\t\tLua chon khong hop le. Moi nhap lai.\n";
			} while (opt1 != 0);
			break;
		}
		case (2): {
			int opt2;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|"; Sleep(50);
				cout << left << setw(14) << " " << "THONG TIN QUAN LI";
				cout << setw(15) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xem thong tin quan li"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Doi tai khoan"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Doi mat khau"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xac nhan thay doi"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Thoat"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				cin >> opt2;
				if (opt2 == 1) { 
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***THONG TIN QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.write(); 
					system("pause"); 
				}
				else if (opt2 == 2) { 
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***DOI TAI KHOAN QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.updateAc(); 
					system("pause"); 
				}
				else if (opt2 == 3) { 
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***DOI MAT KHAU QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.updatePq(); 
					system("pause"); 
				}
				else if (opt2 == 4) {
					fsdrt.open("Director.txt", ios::out | ios::trunc);
					drtMng.writeFile(fsdrt);
					fsdrt.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt != 0) cout << "\t\t\t\t\t\t\tLua chon khong hop le.\n";
			} while (opt2 != 0);
			break;
		}
		case (0): { break; }
		default: {
			cout << "\n\t\t\t\t\t\t\tLua chon khong hop le.\n";
			break; 
		}
		}
	} while (opt != 0);
}