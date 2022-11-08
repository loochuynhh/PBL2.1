#include "TicketManager.h"

TicketManager::TicketManager(ScheduleManager& scheduleList, StaffManager& staffManager) {
	this->scheduleList = &scheduleList;
	this->staffManager = &staffManager;
}

Ticket TicketManager::setTicketInfor() {
	Ticket ticket;
	string id;
	string scheduleId;
	string customerName = "";
	string customerPhone;
	string staffId;
	int cost;
	int amount;
	int soda_corn;
	int check = 0;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
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
		ticket.setId("null");
		return ticket;
	}
	check = 0;
	do {
		system("cls");
		cout << "\n";
		this->scheduleList->write();
		cout << "\n\t\t\t\t\t\t\tNhap ma lich chieu: ";
		getline(cin, scheduleId);
		if (this->scheduleList->findById(scheduleId) == nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tKhong tim thay lich chieu!. Lua chon";
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
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai khach hang: ";
			customerPhone = getphone();
			break;
		}
		catch (int) {
			cout << "\t\t\t\t\t\t\tSo dien thoai khong chua ki tu! Moi nhap lai.\n";
		}
		catch (long) {
			cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
		}
	} while (true);
	check = 0;
	for(int i = 0; i < this->length; i++) {
		if((this->typeList + i)->getCustomerPhone() == customerPhone) {
			customerName = (this->typeList + i)->getCustomerName();
			cout << "\t\t\t\t\t\t\tTen khach hang la: " << customerName << endl;
			system("pause");
			break;
		}
	}
	if(customerName == "") {
		cout << "\t\t\t\t\t\t\tNhap ten khach hang: ";
		getline(cin, customerName);
	}
	check = 0;
	do {
		system("cls");
		cout << "\n";
		this->staffManager->write();
		cout << "\n\t\t\t\t\t\t\tNhap ma nhan vien: ";
		getline(cin, staffId);
		if (this->staffManager->findById(staffId) == nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tKhong tim thay nhan vien!. Lua chon";
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
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "\t\t\t\t\t\t\tNhap gia ve: ";
	cost = getInt();
	cout << "\t\t\t\t\t\t\tNhap so ve: ";
	amount = getInt();
	cout << "\t\t\t\t\t\t\tNhap gia bap nuoc: ";
	soda_corn = getInt();
	ticket.setId(id);
	ticket.setScheduleId(scheduleId);
	ticket.setCustomerName(customerName);
	ticket.setCustomerPhone(customerPhone);
	ticket.setStaffId(staffId);
	ticket.setCost(cost);
	ticket.setAmount(amount);
	ticket.setSoda_Corn(soda_corn);
	return ticket;
}

int TicketManager::getRevenue() {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		revenue += (this->typeList + i)->getCost()*(this->typeList + i)->getAmount() + (this->typeList + i)->getSoda_Corn();
	}
	return revenue;
}

int TicketManager::getRevenue(Time& t1, Time& t2) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		Time t = (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getTime();
		if (t >= t1 && t <= t2 ) {
			revenue += (this->typeList + i)->getCost() * (this->typeList + i)->getAmount() + (this->typeList + i)->getSoda_Corn();
		}
	}
	return revenue;
}

int TicketManager::getRevenue(string staffId) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		if ((this->typeList + i)->getStaffId() == staffId) revenue += (this->typeList + i)->getCost() * (this->typeList + i)->getAmount() + (this->typeList + i)->getSoda_Corn();
	}
	return revenue;
}

void TicketManager::getRevenueY(int year) {
	int revenue[20][12];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) revenue[i][j] = 0;
	}
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		for (int j = 0; j < this->length; j++) {
			if (this->scheduleList->findById((this->typeList + j)->getScheduleId())->getTime().getYear() == year && ((this->staffManager->getTypeList() + i)->getId()).compare((this->typeList + j)->getStaffId()) == 0) {
				revenue[i][this->scheduleList->findById((this->typeList + j)->getScheduleId())->getTime().getMonth() - 1] += (this->typeList + i)->getCost() * (this->typeList + i)->getAmount() + (this->typeList + i)->getSoda_Corn();
			}
		}
	}
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	cout << "\t\t\t\t";
	cout << "|  MaNV/Thang  |  01  |  02  |  03  |  04  |  05  |  06  |  07  |  08  |  09  |  10  |  11  |  12  |\n";
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		cout << "\t\t\t\t";
		cout << "|    " << left << setw(10) << (this->staffManager->getTypeList() + i)->getId() << "|";
		for (int j = 0; j < 12; j++) {
			cout << " " << left << setw(5) << revenue[i][j] << "|";
		}
		cout << endl;
	}
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
}
void TicketManager::readFile(fstream& filein) {
	filein >> length;
	Ticket* ticket = new Ticket[200];
	for (int i = 0; i < length; i++) {
		(ticket + i)->readDataFile(filein);
	}
	delete[] typeList;
	typeList = ticket;
}
void TicketManager::writeFile(fstream& fileout) {
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeDataFile(fileout);
	}
}
void TicketManager::write() {
	cout << "\t\t\t";
	for (int x = 0; x < 131; x++) cout << "-"; cout << endl;
	cout << "\t\t\t";
	cout << "|  Ma hoa don  |  Ma lich chieu  | Ma nhan vien |  SDT khach hang  |          Ten khach hang          | Gia ve | So ve | Bap nuoc |" << endl;
	cout << "\t\t\t";
	for (int x = 0; x < 131; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t";
		(typeList + i)->writeData();
	}
	cout << "\t\t\t";
	for (int x = 0; x < 131; x++) cout << "-"; cout << endl;
}