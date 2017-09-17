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
	MYSQL b;
	mysql_init(&b);
	mysql_real_connect(&b, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char term[100];
	sprintf(term, "select num from ctov where station in ('%s','%s') order by num", start, end);
	mysql_real_query(&b, term, 100);
	res=mysql_store_result(&b);
	result = mysql_fetch_row(res);
	int st=str2int(result[0]);
	result = mysql_fetch_row(res);
	int en = str2int(result[0]);
	char *tem = new char[en - st + 2];
	tem[en - st + 1] = '\0';
	for (int i = en - st; i > -1; i--)
	{
		tem[i] = '0';
	}
	sprintf(term, "select count(distinct seatid) from ticket where substring(ticketnum,%d,%d)<>'%s'", st - 1, en - st + 1, tem);
	mysql_real_query(&b, term, 100);
	res = mysql_store_result(&b);
	result = mysql_fetch_row(res);
	int sitnum=str2int(result[0]);
	sprintf(tem, "select seatnum from coach where id='%s'", cid);
	mysql_real_query(&b,tem, 44);
	num = str2int(mysql_fetch_row(mysql_store_result(&b))[0])-sitnum;
	return num;
}

void Buyer::chooseticket(const char *car, const char *num, const char *da, const char *b, const char *p, const char *s)
{
	if (ticket)
		delete ticket;
	ticket = new Ticket(car, num, da, b, p, s);
}

bool Buyer::buyticket()
{
	return ticket->buy();
}

bool Buyer::inquireticket(char*** info)
{
	ticket->getinfo(info);
}

bool Buyer::changeticket(char cid[10], char cdate[4])
{
	return ticket->change(cid, cdate);

}
bool Buyer::refundticket()
{
	return ticket->refund();
}