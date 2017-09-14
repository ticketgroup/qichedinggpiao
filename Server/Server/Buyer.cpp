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

void Buyer::chooseticket(Ticket *t1)
{
	ticket = t1;

}

bool Buyer::buyticket()
{
	ticket->buy;
	if ()
		return true;
	else
		return false;
}

char***Buyer::inquireticket()
{
	return (char ***)();
}

bool Buyer::changeticket(char cid[10], char cdate[4])
{

	ticket->change(cid, cdate)
		if ()
			return true;
		else
			return false;

}
bool Buyer::refundticket()
{
	if ()
		return true;
	else
		return false;
}