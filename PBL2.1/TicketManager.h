#pragma once
#include "ScheduleManager.h"
#include "StaffManager.h"
#include "Ticket.h"
#include "Time.h"

class TicketManager : public Manager<Ticket>
{
public:
	void getRevenue();
	void getRevenue(string);
	void getRevenue(Time&, Time&);
	TicketManager(ScheduleManager&, StaffManager&);
	Ticket setTicketInfor();
private:
	ScheduleManager* scheduleList;
	StaffManager* staffManager;
};

