#include <iostream>
#include "Buyer.h"
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

Buyer::Buyer(char BID[], char Bpass[]):User(BID,Bpass)
{
}

bool Buyer::carinfo(char cdate[], char start[], char end[],char*** coachinfo)
{
	MYSQL coa;
	MYSQL_RES* cres;
	MYSQL_ROW row;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char tem[200];
	sprintf(tem, "select rownum from stov where station='%s' union select rownum from stov where station='%s';", end, start);
	mysql_real_query(&coa, tem, 200);
	cres = mysql_store_result(&coa);
	sprintf(tem, "select id from ctos where a%s<>'-1' and a%s<>'-1';", mysql_fetch_row(cres)[0], mysql_fetch_row(cres)[0]);
	mysql_real_query(&coa, tem, 200);
	if(res = mysql_store_result(&coa))
	{
		int i = 0;
		for (; result = mysql_fetch_row(res); i++)
		{
			int num = allticketinfo(result[0], cdate, start, end);
			char n[3];
			itoa(num, n, 10);
			strcpy(coachinfo[i][5], n);
			inquireCoach(result[0], coachinfo[i], start, end);
		}
		strcat(coachinfo[i - 1][6], "$");
		return true;
	}
	else
		return false;
}

int Buyer::allticketinfo(char cid[], char cdate[],char start[],char end[] )
{
	int num;
	MYSQL b;
	MYSQL_RES* r;
	MYSQL_ROW o;
	mysql_init(&b);
	mysql_real_connect(&b, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char term[150] = "";
	sprintf(term, "select num from ctov where station in ('%s','%s') order by num;", start, end);
	mysql_real_query(&b, term, 100);
	r=mysql_store_result(&b);
	o = mysql_fetch_row(r);
	int st=str2int(o[0]);
	o = mysql_fetch_row(r);
	int en = str2int(o[0]);
	char *tem = new char[en - st + 2];
	tem[en - st + 1] = '\0';
	for (int i = en - st; i > -1; i--)
	{
		tem[i] = '0';
	}
	sprintf(term, "select count(distinct seatid) from ticket where date='%s' and id='%s' and substring(ticketnum,%d,%d)<>'%s';", cdate, cid, st - 1, en - st + 1, tem);
	mysql_real_query(&b, term, 150);
	r = mysql_store_result(&b);
	o = mysql_fetch_row(r);
	int sitnum=str2int(o[0]);
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

bool Buyer::inquireCoach(char *i, char **info, char *sta, char *en)
{
	MYSQL coa;
	MYSQL_RES* cres;
	MYSQL_ROW row;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char temp[200] = "";
	sprintf(temp, "select starttime from coach where id='%s';", i);
	mysql_real_query(&coa, temp, 46);
	if (cres = mysql_store_result(&coa))
	{
		char st[5];
		row = mysql_fetch_row(cres);

		strcpy(info[0], i);
		strcpy(info[1], sta);
		strcpy(info[3], en);

		strcpy(st, row[0]);
		sprintf(temp, "select rownum from stov where station='%s' union select rownum from stov where station='%s';", en, sta);
		
		mysql_real_query(&coa, temp, 200);
		cres = mysql_store_result(&coa);
		char t[5];
		char b[6];
		sprintf(temp, "select a%s from ctos where id = '%s' union select a%s from ctos where id = '%s'; ", mysql_fetch_row(cres)[0], i, mysql_fetch_row(cres)[0], i);
		mysql_real_query(&coa, temp, 200);
		cres = mysql_store_result(&coa);
		row = mysql_fetch_row(cres);
		sprintf(t, "%04s", strtok(row[0], ","));
		timeAdd(st, t, b);
		strcpy(info[2], b);
		int te = str2int(strtok(NULL, ","));
		row = mysql_fetch_row(cres);
		sprintf(t, "%04s", strtok(row[0], ","));
		timeAdd(st, t, b);
		strcpy(info[4], b);
		te = str2int(strtok(NULL, ",")) - te;
		sprintf(info[6], "%d", te);
	}
	else
		return false;
}