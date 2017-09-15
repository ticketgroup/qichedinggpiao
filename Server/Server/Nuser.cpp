#include<iostream>
#include<cstring>
#include "Nuser.h"
using namespace std;

bool ver(char *Id, char *num)
{
	mysql_real_query(&con, strcat("SELECT password FROM nuser where phone=", Id), 40);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		if (!strcmp(result[0], num))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool reg(char *idnum, char *number, char *ID, char *password)
{
	
		char tem[100];
		sprintf(tem, "INSERT INTO suser(id,password) VALUES('%s','%s','%s','%s')", idnum, number, ID, password);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;

}

bool findPassword(char *ID, char *newpass)
{
	char tem[200];
	sprintf(tem, "UPDATE TABLE suser set password=%s where id=%s",newpass,ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
	
}

Nuser::Nuser(char *NID, char *Npass):Buyer(NID,Npass)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
	for (int i = 0; i < 11; i++)
		ID[i] = NID[i], password[i] = Npass[i];
}

bool Nuser::del()
{
	char tem[200];
	sprintf(tem, "DELETE FROM suser where id=%s", ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Nuser::changePassword(char *newpass)
{
	char tem[200];
	sprintf(tem, "UPDATE TABLE suser set password=%s where id=%s", newpass, ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Nuser::changeinfo(char *newNID)
{
	char tem[200];
	sprintf(tem, "UPDATE TABLE suser set password=%s where id=%s", newNID, ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}
	
char Nuser::verify()
{
	mysql_real_query(&con, strcat("SELECT password FROM nuser where phone=", this->ID), 40);
	if (res = mysql_store_result(&con))
	{
		result = mysql_fetch_row(res);
		if (!strcmp(result[0], password))
			return 'Y';
		else
			return '2';
	}
	else
		return '1';
}
