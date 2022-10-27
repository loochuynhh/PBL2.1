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
	cout << "Nhap id: ";
	cin.ignore();
	getline(cin, id);
	int check = 0;
	do {
		this->scheduleList->write();
		if(check == 1) {
			cout << "Khong tim thay lich chieu" << endl;
		}
		cout << "Nhap ma lich chieu: ";
		getline(cin, scheduleId);
		if(this->scheduleList->findById(scheduleId) == nullptr) check = 1;
	} while (this->scheduleList->findById(scheduleId) == nullptr);
	cout << "Nhap ten khach hang: ";
	getline(cin, customerName);
	cout << "Nhap so dien thoai khach hang: ";
	getline(cin, customerPhone);
	check = 0;
	do {
		this->staffManager->write();
		if(check == 1) {
			cout << "Khong tim thay nhan vien" << endl;
		}
		cout << "Nhap ma nhan vien: ";
		getline(cin, staffId);
		if(this->staffManager->findById(staffId) == nullptr) check = 1;
	} while (this->staffManager->findById(staffId) == nullptr);
	ticket.setId(id);
	ticket.setScheduleId(scheduleId);
	ticket.setCustomerName(customerName);
	ticket.setCustomerPhone(customerPhone);
	ticket.setStaffId(staffId);
	return ticket;
}

int TicketManager::getRevenue() {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		revenue += (this->typeList + i)->getCost();
	}
	cout << "All: " << revenue << endl;
	return revenue;
}

int TicketManager::getRevenue(Time& t1, Time& t2, string staffId) {
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		Time t = (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getTime();
		if (t >= t1 && t <= t2 && (this->typeList + i)->getStaffId() == staffId) {
			revenue += (this->typeList + i)->getCost();
		}
	}
	cout << "All in time: " << revenue << endl;
	return revenue;
}

void TicketManager::getRevenue(string staffId) {
	/*int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		if ((this->typeList + i)->getStaffId() == staffId) {
			revenue += (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getCost();
		}
	}
	cout << "All in staff: " << revenue << endl;*/
}

void TicketManager::readFile(fstream& filein) {
	filein >> length;
	Ticket* ticket = new Ticket[100];
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