#include "TicketManager.h"

TicketManager::TicketManager(ScheduleManager& scheduleList, StaffManager& staffManager) {
	this->scheduleList = &scheduleList;
	this->staffManager = &staffManager;
}

Ticket TicketManager::setTicketInfor() {
	Ticket ticket;
	string id;
	string scheduleId;
	string customerName;
	string customerPhone;
	string staffId;
	int cost;
	cout << "Nhap id: ";
	cin.ignore();
	getline(cin, id);
	int check = 0;
	do {
		system("cls");
		this->scheduleList->write();
		cout << "Nhap ma lich chieu: ";fflush(stdin);
		//if (check != 0) cin.ignore();
		getline(cin, scheduleId);
		if (this->scheduleList->findById(scheduleId) == nullptr) {
			cout << "Khong tim thay lich chieu phu hop!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
			cin.ignore();
		}
		else check = 3;
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "Nhap ten khach hang: ";
	getline(cin, customerName);
	cout << "Nhap so dien thoai khach hang: ";
	getline(cin, customerPhone);
	check = 0;
	do {
		system("cls");
		this->staffManager->write();
		cout << "Nhap ma nhan vien: ";fflush(stdin);
		//if (check != 0) cin.ignore();
		getline(cin, staffId);
		if (this->staffManager->findById(staffId) == nullptr) {
			cout << "Khong tim thay nhan vien!. Lua chon" << endl;
			cout << "\n\t\t1. Nhap lai";
			cout << "\n\t\t2. Thoat\n";
			cin >> check;
			cin.ignore();
		}
		else check = 3;	
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "Nhap gia ve: ";
	cin >> cost;
	ticket.setId(id);
	ticket.setScheduleId(scheduleId);
	ticket.setCustomerName(customerName);
	ticket.setCustomerPhone(customerPhone);
	ticket.setStaffId(staffId);
	ticket.setCost(cost);
	return ticket;
}

int TicketManager::getRevenue() {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		revenue += (this->typeList + i)->getCost();
	}
	cout << "\t\t***Tong doanh thu la: " << revenue << endl;
	return revenue;
}

int TicketManager::getRevenue(Time& t1, Time& t2) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		Time t = (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getTime();
		if (t >= t1 && t <= t2 ) {
			revenue += (this->typeList + i)->getCost();
		}
	}
	cout << "Tong doanh thu trong thoi gian tren la: " << revenue << endl;
	return revenue;
}

void TicketManager::getRevenue(string staffId) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		if ((this->typeList + i)->getStaffId() == staffId) revenue += (this->typeList + i)->getCost();
	}
	cout << "Doanh thu do nhan vien tren ban duoc la: " << revenue << endl;
}

void TicketManager::getRevenueY(int year) {
	int revenue[20][12];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) revenue[i][j] = 0;
	}
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		for (int j = 0; j < this->length; j++) {
			if (this->scheduleList->findById((this->typeList + j)->getScheduleId())->getTime().getYear() == year && ((this->staffManager->getTypeList() + i)->getId()).compare((this->typeList + j)->getStaffId()) == 0) {
				revenue[i][this->scheduleList->findById((this->typeList + j)->getScheduleId())->getTime().getMonth() - 1] += (this->typeList + j)->getCost();
			}
		}
	}
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	cout << "|  MaNV/Thang  |  01  |  02  |  03  |  04  |  05  |  06  |  07  |  08  |  09  |  10  |  11  |  12  |\n";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		cout << "|    " << left << setw(10) << (this->staffManager->getTypeList() + i)->getId() << "|";
		for (int j = 0; j < 12; j++) {
			cout << " " << left << setw(5) << revenue[i][j] << "|";
		}
		cout << endl;
	}
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
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
	cout << "|   Ma ve   |  Ma lich chieu  | Ma nhan vien |  SDT khach hang  |          Ten khach hang          | Gia ve |" << endl;
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		(typeList + i)->writeData();
	}
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
}