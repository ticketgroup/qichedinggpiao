#include "Suser.h"
#include <cstring>

Suser::Suser(char *i, char *p):Buyer(i , p) 
{
}

bool Suser::inquireNuser(char *i, char **info)
{
	mysql_real_query(&con, strcat("SELECT * FROM nuser where phone=", i), 40);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		/*
		strcpy(info[0], i);
		*/
		mysql_real_query(&con, strcat("SELECT * FROM cinfo where uid=", result[? ]), 40);
		res = mysql_store_result(&con);
		result = mysql_fetch_row(res);
		strcpy(info[/*?*/], result[1]);
		strcpy(info[/*?*/], result[2]);
		return true;
	}
	else
		return false;
}

char Suser::verify(char *p)
{
	mysql_real_query(&con, strcat("SELECT password FROM nuser where phone=", this->id), 40);
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
