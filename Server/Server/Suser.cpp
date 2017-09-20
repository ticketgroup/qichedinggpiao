#include "Suser.h"
#include "func.h"
#include <cstring>

Suser::Suser(char *i, char *p):Buyer(i , p) 
{
}
bool Suser::inquireticket(char*** info,char *nid)
{
	MYSQL coa;
	MYSQL_RES* cres;
	MYSQL_ROW row;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char temp[150];
	char st[5];
	char t[5];
	sprintf(temp, "select id,ticketnum,date,passenger,seatid from ticket where passenger='%s';", nid);
	mysql_real_query(&coa, temp, 80);
	if (cres = mysql_store_result(&coa))
	{
		int i = 0;
		for (; row = mysql_fetch_row(cres); i++)
		{
			strcpy(info[i][0], row[0]);
			strcpy(info[i][1], row[4]);
			strcpy(info[i][7], row[2]);

			sprintf(temp, "select name from cinfo where id='%s';", row[3]);
			mysql_real_query(&con, temp, 50);
			res = mysql_store_result(&con);
			strcpy(info[i][6], mysql_fetch_row(res)[0]);

			getse(row[0], row[1], info[i][2], info[i][4]);
			sprintf(temp, "select starttime from coach where id='%s';", info[i][0]);
			mysql_real_query(&coa, temp, 60);
			cres = mysql_store_result(&coa);
			strcpy(st, mysql_fetch_row(cres)[0]);
			sprintf(temp, "select (select num from stov where station=%s),(select num from stov where station=%s) from ctos where id='%s';", info[i][2], info[i][4], info[i][0]);
			mysql_real_query(&con, temp, 150);
			cres = mysql_store_result(&con);
			row = mysql_fetch_row(cres);

			sprintf(t, "%04s", strtok(row[0], ","));
			timeAdd(st, t, info[i][3]);
			sprintf(t, "%04s", strtok(row[1], ","));
			timeAdd(st, t, info[i][5]);

		}
		strcat(info[i - 1][7], "$");
	}
	else
		return true;
}
bool Suser::inquireNuser(char *i, char **info)
{
	char s[52];
	sprintf(s, "SELECT id FROM nuser where phone='%s';", i);
	mysql_real_query(&con, s, 52);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		strcpy(info[0], result[0]);
		strcpy(info[3], i);
		sprintf(s, "SELECT number,name FROM cinfo where id='%s';", result[0]);
		mysql_real_query(&con, s, 52);
		res = mysql_store_result(&con);
		result = mysql_fetch_row(res);
		strcpy(info[1], result[0]);
		strcpy(info[2], result[1]);
		return true;
	}
	else
		return false;
}

char Suser::verify(char *p)
{
	char v[54];
	sprintf(v, "SELECT password FROM nuser where phone='%s';", this->id);
	mysql_real_query(&con, v, 54);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		if (!strcmp(result[0], p))
			return 'Y';
		else
			return '2';
	}
	else
		return '1';
}
