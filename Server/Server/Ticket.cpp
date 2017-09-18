#include "Ticket.h"
#include <cstring>
#include <iostream>
using namespace std;

void Ticket::getse(char *st, char *en)
{
	int i = 0, s, e;
	for (; tNum[i] != '1'; i++);
	s = i;
	for (; tNum[i] != '0'; i++);
	e = i - 1;
	char tem[100];
	sprintf(tem, "SELECT station FROM ctov WHERE id='%s' and num in (%d,%d)", this->id, s, e);
	mysql_real_query(&con, tem, 100);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	strcpy(st, row[0]);
	row = mysql_fetch_row(res);
	strcpy(en, row[0]);
}


Ticket::Ticket(const char *car, const char *num, const char *da, const char *b, const char *p, const char *s)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	strcpy(this->id, car);
	strcpy(this->tNum, num);
	strcpy(this->date, da);
	strcpy(this->buyer, b);
	strcpy(this->passenger, p);
	strcpy(this->seatnum, s);
}

bool Ticket::buy()
{
	char tem[200];
	sprintf(tem, "INSERT INTO ticket(id,ticketnum,date,passenger,buyer,seatid) VALUES('%s','%s','%s','%s','%s','%s')", this->id, this->tNum, this->date, this->passenger, this->buyer, this->seatnum);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Ticket::change(char *i, char *da, char *se)
{
	char tn[21];
	char st[9], en[9];
	this->getse(st, en);
	gettnum(this->id, st, en, tn);
	char tem[250];
	sprintf(tem, "UPDATE ticket set id='%s',date='%s',seatid='%s',ticketnum='%s' where id='%s' and ticketnum='%s' and date='%s' and seatid='%s'", i, da, se, tn, this->id, this->tNum, this->date, this->seatnum);
	if (mysql_query(&con, tem))
	{
		strcpy(this->id, i);
		strcpy(this->date, da);
		strcpy(this->seatnum, se);
		strcpy(this->tNum, tn);
		return true;
	}
	else
		return false;
}

bool Ticket::refund()
{
	char tem[150];
	sprintf(tem, "DELETE FROM ticket where id='%s' and ticketnum='%s' and date='%s' and seatid='%s'", this->id, this->tNum, this->date, this->seatnum);
	if (mysql_query(&con, tem))
	{
		return true;
	}
	else
		return false;
}

bool Ticket::getinfo(char **info)
{
	strcpy(info[0], id);
	strcpy(info[1], date);
	this->getse(info[2], info[3]);
	strcpy(info[4], seatnum);
	strcpy(info[5], passenger);
	strcpy(info[0], buyer);
	return false;
}
