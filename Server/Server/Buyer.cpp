#include<iostream>
#include "Buyer.h"
#include"Ticket.h"
#include"user.h"
using namespace std;

Buyer::Buyer(char BID[], char Bpass[]):User(BID,Bpass)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
}

bool Buyer::carinfo(char cdate[], char start[], char end[],char** coachinfo[])
{
	//char ***coachinfo=new char **[10];

	return true;
}

int Buyer::allticketinfo(char cid[], char cdate[],char start[],char end[] )
{
	int num;
		
	return num;
}

void Buyer::chooseticket()
{
	ticket = t1;

}

bool Buyer::buyticket()
{
	bool b;
	b=ticket->buy;
	if (b==true)
		return true;
	else
		return false;
}

bool Buyer::inquireticket(char** info[])
{
	ticket->getinfo(info)
}

bool Buyer::changeticket(char cid[10], char cdate[4])
{
	bool c;
	c=ticket->change(cid, cdate);
		if(c==true)
			return true;
		else
			return false;

}
bool Buyer::refundticket()
{
	bool r;
	r = ticket->refund;
	if (r==true)
		return true;
	else
		return false;
}