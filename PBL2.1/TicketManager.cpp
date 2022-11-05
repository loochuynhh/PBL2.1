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
	int check = 0;
	do {
		cin.ignore();
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		cin.ignore();
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
			cout << "\n\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	check = 0;
	do {
		this->scheduleList->write();
		cout << "\t\t\t\t\t\t\tNhap ma lich chieu: ";
		getline(cin, scheduleId);
		if (this->scheduleList->findById(scheduleId) == nullptr) {
			cout << "\t\t\t\t\t\t\t\tKhong tim thay lich chieu phu hop!. Lua chon";
			cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
			cin.ignore();
		}
		else check = 3;
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "\t\t\t\t\t\t\tNhap ten khach hang: ";
	getline(cin, customerName);
	cout << "\t\t\t\t\t\t\tNhap so dien thoai khach hang: ";
	getline(cin, customerPhone);
	check = 0;
	do {
		this->staffManager->write();
		cout << "\t\t\t\t\t\t\tNhap ma nhan vien: ";
		getline(cin, staffId);
		if (this->staffManager->findById(staffId) == nullptr) {
			cout << "\t\t\t\t\t\t\t\tKhong tim thay nhan vien!. Lua chon";
			cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
			cout << "\t\t\t2. Thoat";
			cout << "\n\t\t\t\t\t\t\t";
			cin >> check;
			cin.ignore();
		}
		else check = 3;	
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "\t\t\t\t\t\t\tNhap gia ve: ";
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
	return revenue;
}

int TicketManager::getRevenue(string staffId) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		if ((this->typeList + i)->getStaffId() == staffId) revenue += (this->typeList + i)->getCost();
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
				revenue[i][this->scheduleList->findById((this->typeList + j)->getScheduleId())->getTime().getMonth() - 1] += (this->typeList + j)->getCost();
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
	cout << "\t\t\t\t";
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
	cout << "\t\t\t\t";
	cout << "|   Ma ve   |  Ma lich chieu  | Ma nhan vien |  SDT khach hang  |          Ten khach hang          | Gia ve |" << endl;
	cout << "\t\t\t\t";
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t";
		(typeList + i)->writeData();
	}
	cout << "\t\t\t\t";
	for (int x = 0; x < 109; x++) cout << "-"; cout << endl;
}