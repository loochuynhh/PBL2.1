#include "Type.h"

Type::Type() {
    this->type[0] = "Hanh dong";
	this->type[1] = "Tinh cam";
	this->type[2] = "Phieu Luu";
	this->type[3] = "Hoat hinh";
	this->type[4] = "Lang man";
	this->type[5] = "Phim 18+";
	this->type[6] = "Hai huoc";
	this->type[7] = "Co trang";
	this->type[8] = "Tam Ly";
	this->type[9] = "Anime";
	this->type[10] = "Chien tranh";
	this->type[11] = "The thao";
	this->type[12] = "Ky su";
	this->type[13] = "Chinh kich";
	this->type[14] = "Ma - Kinh di";
	this->type[15] = "Vo thuat";
	this->type[16] = "Vien Tuong";
	this->type[17] = "Khoa hoc";
	this->type[18] = "Than Loai";
	this->type[19] = "Am nhac";
}

string* Type::getType() {
    return this->type;
}

string Type::getType(int index) {
	return this->type[index];
}