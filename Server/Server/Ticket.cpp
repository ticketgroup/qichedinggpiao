#include "Ticket.h"
#include <cstring>
#include <iostream>
using namespace std;
/**********************************************
目前的版本数据库调用全部都是错误的
**********************************************/

/**************************************************************
函数名称：str2int
形参表：由数字组成的字符(char*)
返回值：int
功能：将字符中的数转换成数(目前的版本较为简单，调用的时候请确保字符串是一个数)
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
	sprintf(tem, "SELECT name FROM *** WHERE id in (%d,%d)", s, e);
	mysql_real_query(&con,tem,100);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	strcpy(st, row[0]);
	row = mysql_fetch_row(res);
	strcpy(en, row[0]);
}

/**************************************************************
函数名称：gettnum
形参表：汽车ID(char*)，起始地(char*)，终点(char*)，输出(char*)
返回值：bool(true：成功，false：失败)
功能：通过ID，起点，终点，获得票的编码
**************************************************************/
bool gettnum(char *id, char *st, char *en , char *source)
{
	MYSQL con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int s, e, station;
	char tem[100];
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	mysql_real_query(&con, strcat("select seatnum from coach where id=", id), 42);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	station = str2int(row[0]);
	for (int i = 0; i < station; source[i] = '0', i++);
	source[station] = '\0';
	sprintf(tem, "select id from *** where id=%s and station in (%s,%s)", id, st, en);
	mysql_real_query(&con, tem, 100);
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
	char tem[150];
	sprintf(tem,"INSERT INTO tickets(id,placenum,buyer,passenger,seat) VALUES('%s','%s',%s,%s,'%s')", this->id, this->tNum, this->buyer, this->passenger, this->seatnum);
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
	char tem[200];
	sprintf(tem, "UPDATE TABLE tickets set id=%s ,date=%s,seat=%s,num=%s where id=%s and num=%s and date=%s and seat=%s", i , da , se , tn , this->id , this->tNum , this->date , this->seatnum);
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
	char tem[200];
	sprintf(tem, "DELETE FROM tickets where id=%s and num=%s and date=%s and seat=%s", this->id, this->tNum, this->date, this->seatnum);
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
