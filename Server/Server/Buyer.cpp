#include <iostream>
#include "Buyer.h"
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

Buyer::Buyer(char BID[], char Bpass[]):User(BID,Bpass)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
}

bool Buyer::carinfo(char cdate[], char start[], char end[],char*** coachinfo)
{
	MYSQL coa;
	MYSQL_RES* cres;
	MYSQL_ROW row;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char tem[200];
	sprintf(tem, "select id from ctos where (select num from stov where station='%s')<>'-1 and (select num from stov where station='%s')<>'-1';", start, end);
	mysql_real_query(&con, tem, 200);
	res = mysql_store_result(&con);
	int num=allticketinfo(mysql_fetch_row(res)[0], cdate, start, end);
	char n[3];
	itoa(num, n, 10);
	for (int i = 0; result = mysql_fetch_row(res); i++)
	{
		//User::inquireCoach(result[0], coachinfo[i]);
		char temp[100];
		sprintf(temp, "select starttime from coach where id='%s';", result[0]);
		mysql_real_query(&coa, temp, 46);
		char st[5];
		cres = mysql_store_result(&coa);
		row = mysql_fetch_row(cres);
	
		strcpy(coachinfo[i][0],result[0]);
		strcpy(coachinfo[i][1], cdate);
		strcpy(coachinfo[i][2], start);
		strcpy(coachinfo[i][3], end);
		strcpy(coachinfo[i][4], n);
		//strcat(info[0], ";");

		strcpy(st, row[0]);
		sprintf(temp, "select ctov.station,stov.num from ctov,stov where id='%s' order by ctov.num;", result[0]);
		mysql_real_query(&con, temp, 100);
		res = mysql_store_result(&con);
	}
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

int Buyer::allticketinfo(char cid[], char cdate[],char start[],char end[] )
{
	int num;
	MYSQL b;
	mysql_init(&b);
	mysql_real_connect(&b, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char term[100];
	sprintf(term, "select num from ctov where station in ('%s','%s') order by num;", start, end);
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
	sprintf(term, "select count(distinct seatid) from ticket where substring(ticketnum,%d,%d)<>'%s';", st - 1, en - st + 1, tem);
	mysql_real_query(&b, term, 100);
	res = mysql_store_result(&b);
	result = mysql_fetch_row(res);
	int sitnum=str2int(result[0]);
	sprintf(tem, "select seatnum from coach where id='%s';", cid);
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
bool Buyer::changeticket(char *cid, char *cdate,char *seatnum)
{
	return ticket->change(cid, cdate,seatnum);

}
bool Buyer::refundticket()
{
	return ticket->refund();
}