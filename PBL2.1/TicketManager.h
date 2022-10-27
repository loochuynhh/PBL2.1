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
private:
	ScheduleManager* scheduleList;
	StaffManager* staffManager;
};

