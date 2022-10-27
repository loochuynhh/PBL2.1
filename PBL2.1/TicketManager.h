#pragma once
#include "ScheduleManager.h"
#include "StaffManager.h"
#include "Ticket.h"
#include "Time.h"

class TicketManager : public Manager<Ticket>
{
public:
	int getRevenue();
	void getRevenue(string);
	int getRevenue(Time&, Time&, string);
	TicketManager(ScheduleManager&, StaffManager&);
	Ticket setTicketInfor();
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
private:
	ScheduleManager* scheduleList;
	StaffManager* staffManager;
};

