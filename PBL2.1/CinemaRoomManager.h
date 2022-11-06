#pragma once
#include "Manager.h"
#include "CinemaRoom.h"
#include <string>

using namespace std;

class CinemaRoomManager : public Manager<CinemaRoom>
{
public:
	CinemaRoom setCinemaRoomInfor();
	string update();
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
protected:
};
