#include <iostream>
#include "func.h"
#include "mysql.h"

void getse(char*id, char*tNum, char *st, char*en)
{
	MYSQL con;
	MYSQL_RES* res;
	MYSQL_ROW row;
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	int i = 0, s, e;
	for (; tNum[i] != '1'; i++);
	s = i;
	for (; tNum[i] != '0'; i++);
	e = i - 1;
	char tem[100];
	sprintf(tem, "SELECT station FROM ctov WHERE id='%s' and num in (%d,%d);", id, s, e);
	mysql_real_query(&con, tem, 100);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	strcpy(st, row[0]);
	row = mysql_fetch_row(res);
	strcpy(en, row[0]);
	mysql_close(&con);
}


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

/**************************************************************
函数名称：gettnum
形参表：汽车ID(char*)，起始地(char*)，终点(char*)，输出(char*)
返回值：bool(true：成功，false：失败)
功能：通过ID，起点，终点，获得票的编码
**************************************************************/
bool gettnum(char *id, char *st, char *en, char *source)
{
	MYSQL con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int s, e, station;
	char tem[200];
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	sprintf(tem, "select max(num) from ctov where id='%s';", id);
	mysql_real_query(&con, tem, 48);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	station = str2int(row[0]);
	for (int i = 0; i < station; source[i] = '0', i++);
	source[station] = '\0';
	sprintf(tem, "select num from ctov where id='%s' and station='%s' union select num from ctov where id='%s' and station='%s';", id, st, id, en);
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
void timeAdd(char *time, char *addM, char *res)
{
	char temp[4][3] = { time[0],time[1],'\0',time[2],time[3],'\0',addM[0],addM[1],'\0',addM[2],addM[3],'\0' };
	int m = str2int(temp[1]) + str2int(temp[3]);
	int h = m / 60;
	m %= 60;
	h += str2int(temp[0]) + str2int(temp[2]);
	sprintf(res, "%02d:%02d", h, m);
}
void timeSub(char * time, char * subM, char * res)
{
	char temp[4][3] = { time[0],time[1],'\0',time[3],time[4],'\0',subM[0],subM[1],'\0',subM[3],subM[4],'\0' };
	int m = str2int(temp[1]) - str2int(temp[3]);
	int h = 0;
	if (m < 0)
	{
		m += 60;
		h--;
	}
	h += str2int(temp[0]) - str2int(temp[2]);
	sprintf(res, "%02d%02d", h, m);
}
int getSeatNum(char *id, char *st, char *en)
{
	MYSQL coa;
	MYSQL_RES* res;
	MYSQL_ROW result;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char tem[120];
	sprintf(tem, "select num from ctov where id='%s' and station in ('%s','%s') order by num;", id, st, en);
	mysql_real_query(&coa, tem, 120);
	if (res = mysql_store_result(&coa))
	{
		int a = str2int(mysql_fetch_row(res)[0]);
		int b = str2int(mysql_fetch_row(res)[0]) - a + 2;
		char * tn = new char[b];
		tn[b] = '\0';
		for (int i = b - 1; i > -1; i--)
		{
			tn[i] = '0';
		}
		sprintf(tem, "select seatid from ticket where id='%s' and substring(ticketnum,%d,%d)<>'%s' order by seatnum;", id, a, b, tn);
		mysql_real_query(&coa, tem, 120);
		if (res = mysql_store_result(&coa))
		{
			int pre = str2int(mysql_fetch_row(res)[0]);
			int next;
			while (result = mysql_fetch_row(res))
			{
				next = str2int(result[0]);
				if (next - pre > 1)
					return pre + 1;
				pre = next;
			}
			sprintf(tem, "select seatnum from coach where id='%s';", id);
			mysql_real_query(&coa, tem, 120);
			if (res = mysql_store_result(&coa))
			{
				int seat = str2int(mysql_fetch_row(res)[0]);
				if (next != seat)
					return seat;
				else
					return 0;
			}
		}
		else
			return 1;
	}
	else
		return 0;
}