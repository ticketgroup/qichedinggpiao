#include<iostream>
#include <cstring>
#include"user.h"
#include "Ticket.h"
using namespace std;

bool cancel(User* a) { delete a; }

User::User(char *, char *)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
}


bool User::inquireCoach(char *p, char *i, char **info)
{
	if (check(p))
	{
		char temp[100];
		sprintf(temp, "select starttime from coach where id='%s'", i);
		mysql_real_query(&con, temp, 46);
		if (res = mysql_store_result(&con))
		{
			char st[5];
			result = mysql_fetch_row(res);

			strcpy(info[0], i);

			strcpy(st, result[2]);
			MYSQL_RES ctos;
			MYSQL_ROW row;
			sprintf(temp, "select ctov.station,stov.num from ctov,stov where id='%s' order by ctov.num", i);
			mysql_real_query(&con, temp, 100);
			res = mysql_store_result(&con);
			char t[5];
			char b[6];
			info[2][0] = '\0';
			for (int a = 0; result = mysql_fetch_row(res); a++)
			{
				strcat(info[2], result[0]);
				strcat(info[2], "/");
				sprintf(temp, "select '%s' from ctos where id='%s'", result[1], i);
				mysql_real_query(&con, temp, 100);
				sprintf(t, "%04s", strtok(result[0], ","));
				timeAdd(st, t, b);
				strcat(info[2], b);
				strcat(info[2], ";");
			}
		}
		else
			return false;
	}
	else
		return false;
}