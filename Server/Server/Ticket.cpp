#include "Ticket.h"
#include <cstring>
#include <iostream>
using namespace std;
/**********************************************
Ŀǰ�İ汾���ݿ����ȫ�����Ǵ����
**********************************************/

/**************************************************************
�������ƣ�str2int
�βα���������ɵ��ַ�(char*)
����ֵ��int
���ܣ����ַ��е���ת������(Ŀǰ�İ汾��Ϊ�򵥣����õ�ʱ����ȷ���ַ�����һ����)
**************************************************************/
int str2int(char*s)
{
	int a = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		a *= 10;
		a += s[i] - '0';
	}
	return a;
}

void Ticket::getse(char *st, char *en)
{
	int i = 0, s, e;
	for (; tNum[i] != '1'; i++);
	s = i;
	for (; tNum[i] != '0'; i++);
	e = i - 1;
	char tem[100];
	sprintf(tem, "SELECT station FROM ctov WHERE id='%s' and num in (%d,%d)",this->id,s, e);
	mysql_real_query(&con,tem,100);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	strcpy(st, row[0]);
	row = mysql_fetch_row(res);
	strcpy(en, row[0]);
}

/**************************************************************
�������ƣ�gettnum
�βα�����ID(char*)����ʼ��(char*)���յ�(char*)�����(char*)
����ֵ��bool(true���ɹ���false��ʧ��)
���ܣ�ͨ��ID����㣬�յ㣬���Ʊ�ı���
**************************************************************/
bool gettnum(char *id, char *st, char *en , char *source)
{
	MYSQL con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int s, e, station;
	char tem[200];
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	sprintf(tem, "select max(num) from ctov where id='%s'", id);
	mysql_real_query(&con, tem, 48);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	station = str2int(row[0]);
	for (int i = 0; i < station; source[i] = '0', i++);
	source[station] = '\0';
	sprintf(tem, "select num from ctov where id='%s' and station='%s' union select num from ctov where id='%s' and station='%s'", id, st, id,en);
	mysql_real_query(&con, tem, 200);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	s = str2int(row[0]);
	row = mysql_fetch_row(res);
	e = str2int(row[0]);
	if (s < e)
	{
		for (int i = s - 1; i < e; i++)
		{
			source[i] = '1';
		}
		return true;
	}
	else
		return false;
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
	sprintf(tem,"INSERT INTO ticket(id,ticketnum,date,passenger,buyer,seatid) VALUES('%s','%s','%s','%s','%s','%s')", this->id, this->tNum,this->date,this->passenger, this->buyer, this->seatnum);
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
	sprintf(tem, "UPDATE ticket set id='%s',date='%s',seatid='%s',ticketnum='%s' where id='%s' and ticketnum='%s' and date='%s' and seatid='%s'", i , da , se , tn , this->id , this->tNum , this->date , this->seatnum);
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
	this->getse(info[2],info[3]);
	strcpy(info[4], seatnum);
	strcpy(info[5], passenger);
	strcpy(info[0], buyer);
	return false;
}
