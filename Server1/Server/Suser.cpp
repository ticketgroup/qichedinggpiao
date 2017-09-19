#include "Suser.h"
#include <cstring>

Suser::Suser(char *i, char *p):Buyer(i , p) 
{
}

bool Suser::inquireNuser(char *i, char **info)
{
	char s[52];
	sprintf(s, "SELECT id FROM nuser where phone='%s'",i);
	mysql_real_query(&con, s, 52);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		strcpy(info[0], result[0]);
		strcpy(info[3], i);
		sprintf(s, "SELECT number,name FROM cinfo where id='%s'", result[0]);
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
	sprintf(v, "SELECT password FROM nuser where phone='%s'",this->id);
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
