#include "Conductor.h"
#include <cstring>

Conducor::Conducor(char *i, char *p):User(i,p),innerPassword("?????????"){}

bool Conducor::inquireSuser(char *p, char *i, char **out)
{
	if (this->check(p))
	{
		mysql_real_query(&con, strcat("SELECT * FROM suser where id=", i), 36);
		if (res = mysql_store_result(&con))
		{
			result = mysql_fetch_row(res);
			strcpy(out[? ], i);
			strcpy(out[? ], result[0]);
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

bool Conducor::addSuser(char *p, char *i, char *pa)
{
	if (check(p))
	{
		char tem[100];
		sprintf(tem, "INSERT INTO suser(id,password) VALUES('%s','%s')", i, pa);
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
		sprintf(tem, "UPDATE TABLE suser set id=%s ,password=%s where id=%s", aid, pa, mid);
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
		sprintf(tem, "DELETE FROM suser where id=%s", i);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Conducor::inquireCoach(char *p, char *, char ***)
{
	return false;
}

bool Conducor::addCoach(char *p, char *, char *, char *, char *)
{
	return false;
}

bool Conducor::deleteCoach(char *p, char *)
{
	return false;
}

char Conducor::verify(char *p)
{
	if (this->id == "???" && p == "???")
	{
		return 'Y';
	}
	else 
		return '0';
}
