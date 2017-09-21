#include "Conductor.h"
#include"user.h"
#include "func.h"
#include <iostream>
#include "Ticket.h"
#include <cstring>
using namespace std;


Conductor::Conductor(char *i, char *p) : User(i, p), innerPassword("12345") { strcpy(this->id, i); }

bool Conductor::inquireSuser(char *p, char ***out)
{
	if (this->check(p))
	{
		mysql_real_query(&con, "SELECT id,password,name FROM suser;", 36);
		if (res = mysql_store_result(&con))
		{
			for (int i = 0; result = mysql_fetch_row(res); i++)
			{
				strcpy(out[i][0], result[0]);
				strcpy(out[i][1], result[1]);
				strcpy(out[i][2], result[2]);
			}
		}
		else
			return true;
	}
	else
		return false;
}

bool Conductor::check(char *p)
{
	if (!strcmp(this->innerPassword, p))
		return true;
	else
		return false;
}

int Conductor::carnum()
{
	mysql_real_query(&con, "select count(id) from coach;", 29);
	if (res = mysql_store_result(&con))
		return str2int(mysql_fetch_row(res)[0]);
	else
		return -1;
}

bool Conductor::carinfo(char ***info)
{
	mysql_real_query(&con, "select id from coach;", 23);
	if (res = mysql_store_result(&con))
	{
		int i = 0;
		for (; result = mysql_fetch_row(res); i++)
		{
			inquireCoach(result[0], info[i]);
		}
		strcat(info[i - 1][2], "$");
		return true;
	}
	else
		return false;
}

bool Conductor::addSuser(char *p, char *i, char *pa)
{
	if (check(p))
	{
		char tem[100];
		sprintf(tem, "INSERT INTO suser(id,password) VALUES('%s','%s');", i, pa);
		if (!mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Conductor::changeSuserInfo(char *p, char *mid, char *aid, char *pa)
{
	if (check(p))
	{
		char tem[200];
		sprintf(tem, "UPDATE suser set id='%s' ,password='%s' where id='%s';", aid, pa, mid);
		if (!mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Conductor::deleteUser(char *p, char *i)
{
	if (check(p))
	{
		char tem[200];
		sprintf(tem, "DELETE FROM suser where id='%s';", i);
		if (!mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Conductor::addCoach(char *p, char *i, char *st, char ***station, int s, char *seat)
{
	if (check(p))
	{
		MYSQL coa;
		mysql_init(&coa);
		mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
		char temp[100];
		sprintf(temp, "select id from coach where id='%s';", i);
		mysql_real_query(&coa, temp, 42);
		if (mysql_fetch_row(mysql_store_result(&coa)))
		{
			cout << "车次信息已存在！" << endl;
			return false;
		}
		else
		{
			sprintf(temp, "INSERT INTO coach(id,starttime,seatnum) VALUES('%s','%s','%s');", i, st, seat);
			if (!mysql_query(&coa, temp))
			{
				sprintf(temp, "insert into ctos(id) values('%s');", i);
				if (!mysql_query(&coa, temp))
				{
					for (int a = 0; a < s; a++)
					{
						sprintf(temp, "select rownum from stov where station='%s';", station[a][0]);
						mysql_real_query(&coa, temp, 100);
						res = mysql_store_result(&coa);
						if (result = mysql_fetch_row(res))
						{
							sprintf(temp, "insert into ctov(num,id,station) values(%d,'%s','%s');", a, i, station[a][0]);
							if (!mysql_query(&coa, temp))
							{
								sprintf(temp, "update ctos set a%s='%s,%s' where id='%s';", result[0], station[a][1], station[a][2], i);
								if (!mysql_query(&coa, temp))
								{
									continue;
								}
								else
								{
									while (mysql_query(&coa, strcat(strcat("delete from ctov where id='", i), "';")));
									if (!a)
										while (mysql_query(&coa, strcat(strcat("delete from ctos where id='", i), "';")));
									while (mysql_query(&coa, strcat(strcat("delete from coach where id='", i), "';")));
									return false;
								}
							}
							else
							{
								if (!a)
									while (mysql_query(&coa, strcat(strcat("delete from ctov where id='", i), "';")));
								while (mysql_query(&coa, strcat(strcat("delete from coach where id='", i), "';")));

								return false;
							}
						}
						else
						{
							int max = 0;
							mysql_real_query(&coa, "select rownum from stov;", 30);
							res = mysql_store_result(&coa);
							if (mysql_fetch_row(res))
							{
								mysql_real_query(&coa, "select max(rownum) from stov;", 30);
								max = str2int(mysql_fetch_row(mysql_store_result(&coa))[0]);
							}
							++max;

							sprintf(temp, "insert into stov(rownum,station) values(%d,'%s');", max, station[a][0]);
							if (!mysql_query(&coa, temp))
							{
								sprintf(temp, "alter table ctos add(a%d varchar(9) default '-1' not null);", max);
								while (mysql_query(&coa, temp));
								sprintf(temp, "update ctos set a%d='-1';", max);
								while (mysql_query(&coa, temp));
								sprintf(temp, "update ctos set a%d='%s,%s' where id='%s';", max, station[a][1], station[a][2], i);
								if (!mysql_query(&coa, temp))
								{
									sprintf(temp, "insert into ctov(num,id,station) values(%d,'%s','%s');", a, i, station[a][0]);
									if (!mysql_query(&coa, temp))
									{
										continue;
									}
									else
									{
										while (mysql_query(&coa, strcat(strcat("delete from coach where id='", i), "';")));
										while (mysql_query(&coa, strcat(strcat("delete from ctov where id='", i), "';")));
										if (!a)
											while (mysql_query(&coa, strcat(strcat("delete from ctos where id='", i), "';")));
										return false;
									}
								}
								else
								{
									if (!a)
										while (mysql_query(&coa, strcat(strcat("delete from ctov where id=", i), "';")));
									while (mysql_query(&coa, strcat(strcat("delete from coach where id='", i), "';")));
									return false;
								}
							}
						}
					}
					return true;
				}
				else
				{
					while (mysql_query(&con, strcat(strcat("delete from coach where id='", i), "';")));
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		cout << "密码错误！"<<endl;
		return false;
	}
}

bool Conductor::deleteCoach(char *p, char *i)
{
	if (check(p))
	{
		while (mysql_query(&con, strcat(strcat("delete from coach where id='", i), "';")));
		while (mysql_query(&con, strcat(strcat("delete from ctov where id=", i), "';")));
		while (mysql_query(&con, strcat(strcat("delete from ctos where id='", i), "';")));
		return true;
	}
	else
		return false;
}

char Conductor::verify(char *p)
{
	if (strcmp(this->id , "12306") == 0 && strcmp(p, "54321") == 0 )
	{
		return 'Y';
	}
	else
		return '0';
}

bool Conductor::inquireCoach(char *i, char **info)
{
	char temp[100];
	sprintf(temp, "select starttime from coach where id='%s';", i);
	mysql_real_query(&con, temp, 46);
	if (res = mysql_store_result(&con))
	{
		char st[5];
		result = mysql_fetch_row(res);

		strcpy(info[0], i);
		//strcat(info[0], ";");

		strcpy(st, result[2]);
		sprintf(temp, "select ctov.station,stov.num from ctov,stov where id='%s' order by ctov.num;", i);
		mysql_real_query(&con, temp, 100);
		res = mysql_store_result(&con);
		char t[5];
		char b[6];
		info[2][0] = '\0';
		for (int a = 0; result = mysql_fetch_row(res); a++)
		{
			strcat(info[2], result[0]);
			strcat(info[2], "/");
			sprintf(temp, "select '%s' from ctos where id='%s';", result[1], i);
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
