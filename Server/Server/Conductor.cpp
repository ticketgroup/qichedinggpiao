#include "Conductor.h"
#include <iostream>
#include "Ticket.h"
#include <cstring>
using namespace std;

void timeAdd(char *time, char *addM, char *res)
{
	char temp[4][3] = { time[0],time[1],'\0',time[2],time[3],'\0',addM[0],addM[1],'\0',addM[2],addM[3],'\0' };
	int m = str2int(temp[1]) + str2int(temp[3]);
	int h = m / 60;
	m %= 60;
	h += str2int(temp[0]) + str2int(temp[2]);
	sprintf(res, "%02d:%02d", h, m);
}

Conducor::Conducor(char *i, char *p):User(i,p),innerPassword("12345"){}

bool Conducor::inquireSuser(char *p, char *i, char **out)
{
	if (this->check(p))
	{
		char a[56];
		sprintf(a, "SELECT password,name FROM suser where id='%s'", i);
		mysql_real_query(&con,a, 56);
		if (res = mysql_store_result(&con))
		{
			result = mysql_fetch_row(res);
			strcpy(out[0], i);
			strcpy(out[1], result[0]);
			strcpy(out[2], result[1]);
		}
		else
			return false;
	}
	else
		return false;
}

bool Conducor::check(char *p)
{
	if (!strcmp(this->innerPassword, p))
		return true;
	else
		return false;
}

bool Conducor::addSuser(char *p, char *i, char *pa,char* na)
{
	if (check(p))
	{
		char tem[100];
		sprintf(tem, "INSERT INTO suser(id,password,name) VALUES('%s','%s','%s')", i, pa,na);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Conducor::changeSuserInfo(char *p, char *mid, char *aid, char *pa)
{
	if (check(p))
	{
		char tem[200];
		sprintf(tem, "UPDATE suser set id='%s' ,password='%s' where id='%s'", aid, pa, mid);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Conducor::deleteUser(char *p, char *i)
{
	if (check(p))
	{
		char tem[200];
		sprintf(tem, "DELETE FROM suser where id='%s'", i);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Conducor::addCoach(char *p, char *i, char *st, char ***station, int s, char *seat)
{
	if (check(p))
	{
		char temp[100];
		sprint("select id from coach where id='%s'",i);
		mysql_real_query(&con,temp,40);
		if (mysql_store_result(&con))
			return false;
		else
		{
			sprintf(temp, "insert into coach(id,starttime,seatnum) values('%s','%s',%s)", i, st, seat);
			if (mysql_query(&con, temp))
			{
				sprintf(temp, "insert into ctos(id) values('%s')", i);
				if (mysql_query(&con, temp))
				{
					for (int a = 0; a < s; a++)
					{
						sprintf(temp, "select num from stov where station='%s'", station[a][0]);
						mysql_real_query(&con, temp, 100);
						if (res = mysql_store_result(&con))
						{
							result = mysql_fetch_row(res);
							sprintf(temp, "insert into ctov(num,id,station) values(%d,'%s','%s')", a, i, station[a][0]);
							if (mysql_query(&con, temp))
							{
								sprintf(temp, "update ctos set %s='%s,%s' where id='%s'", result[0], station[a][1], station[a][2], i);
								if (mysql_query(&con, temp))
								{
									continue;
								}
								else
								{
									while(!mysql_query(&con, strcat(strcat("delete from coach where id='", i),"'")));
									while(!mysql_query(&con, strcat(strcat("delete from ctov where id='", i),"'")));
									if(!a)
										while(!mysql_query(&con, strcat(strcat("delete from ctos where id='", i),"'")));
									return false;
								}
							}
							else
							{
								while(!mysql_query(&con, strcat(strcat("delete from coach where id='", i),"'")));
								if(!a)
									while(!mysql_query(&con, strcat(strcat("delete from ctov where id='", i),"'")));
								return false;
							}
						}
						else
						{
							int max = 0;
							mysql_real_query(&con,"select max(num) from stov",27);
							if (res = mysql_store_result(&con))
							{
								max = str2int(mysql_fetch_row(res)[0]);
							}
							++max;
							sprintf(temp,"alert table ctos add(%d varchar(9) default '-1' not null)",max);
							while (!mysql_query(&con, temp));
							sprintf(temp, "update ctos set %d='-1'", max);
							while (!mysql_query(&con, temp));
							sprintf(temp, "insert into ctov(num,id,station) values(%d,'%s','%s')", a, i, station[a][0]);
							if (mysql_query(&con, temp))
							{
								sprintf(temp, "update ctos set %d='%s,%s' where id='%s'", max, station[a][1], station[a][2], i);
								if (mysql_query(&con, temp))
								{
									continue;
								}
								else
								{
									while (!mysql_query(&con, strcat(strcat("delete from coach where id='", i),"'")));
									while (!mysql_query(&con, strcat("delete from ctov where id=", i)));
									if (!a)
										while (!mysql_query(&con, strcat(strcat("delete from ctos where id='", i),"'")));
									return false;
								}
							}
							else
							{
								while (!mysql_query(&con, strcat(strcat("delete from coach where id='", i),"'")));
								if (!a)
									while (!mysql_query(&con, strcat(strcat("delete from ctov where id=", i),"'")));
								return false;
							}
						}
					}
					return true;
				}
				else
				{
					while(!mysql_query(&con, strcat(strcat("delete from coach where id='", i),"'")));
					return false;
				}
			}
			else
				return false;
		}
	}
	else
		return false;
}

bool Conducor::deleteCoach(char *p, char *i)
{
	if (check(p))
	{
		while (!mysql_query(&con, strcat(strcat("delete from coach where id='", i), "'")));
		while (!mysql_query(&con, strcat(strcat("delete from ctov where id=", i), "'")));
		while (!mysql_query(&con, strcat(strcat("delete from ctos where id='", i), "'")));
		return true;
	}
	else
		return false;
}

char Conducor::verify(char *p)
{
	if (this->id == "12306" && p == "54321")
	{
		return 'Y';
	}
	else 
		return '0';
}
