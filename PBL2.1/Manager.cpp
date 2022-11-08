#include "Manager.h"

template <class type>
Manager<type>::Manager() {
	this->length = 0;
	this->typeList = nullptr;
}

template <class type>
Manager<type>::~Manager() {
	delete[] this->typeList;
}

template <class type>
void Manager<type>::add(const type& ty) {
	type* listtmp = new type[this->length + 1];
	for (int i = 0; i < this->length; i++) {
		*(listtmp + i) = *(this->typeList + i);
	}
	*(listtmp + length) = ty;
	delete[] this->typeList;
	this->typeList = listtmp;
	this->length++;
}

template <class type>
type* Manager<type>::findById(const string& id) {
	for (int i = 0; i < this->length; i++) {
		if (strcmp((this->typeList + i)->getId().c_str(), id.c_str()) == 0) {
			return (this->typeList + i);
		}
	}
	return nullptr;
}

template <class type>
void Manager<type>::del(const string& id) {
	type* listtmp = new type[this->length - 1];
	int count = 0;
	int counttmp = 0;
	while (counttmp < this->length - 1) {
		if (strcmp((this->typeList + count)->getId().c_str(), id.c_str()) != 0) {
			*(listtmp + counttmp) = *(this->typeList + count);
			counttmp++;
		}
		count++;
	}
	delete[] this->typeList;
	this->typeList = listtmp;
	this->length--;
}

template <class type>
int Manager<type>::getLength() {
	return this->length;
}

template <class type>
void Manager<type>::setLength(int length) {
	this->length = length;
}

template <class type>
type* Manager<type>::getTypeList() {
	return this->typeList;
}

int getInt() {
	while (true) {
		int x;
		cin >> x;
		if (!std::cin) {
			cin.clear(); 
			cin.ignore(100, 10);
			cout << "\t\t\t\t\t\t\tChi nhap so. Moi Nhap lai: ";
		}
		else {
			cin.ignore(100, 10);
			return x;
		}
	}
}

string getphone() {
	string x;
	getline(cin, x);
	if (x.length() > 11 || x.length() < 10) throw long(0);
	for (int i = 0; i < x.length(); i++) {
		if (x[i] > '9' || x[i] < '0') {
			throw int(0);
		}
	}
	return x;
}
int checktime(int date, int month, int year) {
	if (date > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) throw int();
	else if (date > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) throw int();
	else if (date > 29 && month == 2) throw int();
	else if (month > 12 || month < 1) throw long();
	else if (date < 1) throw unsigned int();
	else if (year > 9999 || year < 1000) throw string();
	return 0;
}
template class Manager<Ticket>;
template class Manager<Schedule>;
template class Manager<Film>;
template class Manager<CinemaRoom>;
template class Manager<Staff>;
template class Manager<Director>;
