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
		if(check == 1) {
			cout << "Khong tim thay nhan vien" << endl;
		}
		cout << "Nhap ma nhan vien: ";
		getline(cin, staffId);
		if(this->staffManager->findById(scheduleId) == nullptr) check = 1;
	} while (this->staffManager->findById(scheduleId) == nullptr);
	ticket.setId(id);
	ticket.setScheduleId(scheduleId);
	ticket.setCustomerName(customerName);
	ticket.setCustomerPhone(customerPhone);
	ticket.setStaffId(staffId);
	return ticket;
}

void TicketManager::getRevenue() {
	/*int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		int tmp = (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getCost();
		revenue += tmp;
	}
	cout << "All: " << revenue << endl;*/
}

void TicketManager::getRevenue(Time& t1, Time& t2) {
	/*int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		Time t = (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getTime();
		if (t >= t1 && t <= t2) {
			revenue += (this->scheduleList)->findById((this->typeList + i)->getScheduleId())->getCost();
		}
	}
	cout << "All in time: " << revenue << endl;*/
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
