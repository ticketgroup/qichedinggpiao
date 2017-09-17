#include<iostream>
#include<cstring>
#include "Nuser.h"
using namespace std;

bool ver(char *Id, char *num)
{
	char v[47];
	sprintf(v, "SELECT number FROM cinfo where ID='%s'", Id);
	mysql_real_query(&con, v, 47);
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

bool reg(char *idnum, char *ID, char *password)
{
	
		char tem[150];
		sprintf(tem, "INSERT INTO nuser(id,,phone,password) VALUES('%s','%s','%s')", idnum, ID, password);
		if (mysql_query(&con, tem))
			return true;
		else
			return false;

}

bool findPassword(char *ID, char *newpass)
{
	char tem[150];
	sprintf(tem, "UPDATE nuser set password='%s' where phone='%s'",newpass,ID);
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
		ID[i] = NID[i];
}

bool Nuser::del()
{
	char tem[45];
	sprintf(tem, "DELETE FROM nuser where phone='%s'", ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Nuser::changePassword(char *newpass)
{
	char tem[150];
	sprintf(tem, "UPDATE nuser set password='%s' where phone='%s'", newpass, ID);
	if (mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Nuser::changeinfo(char *newNID)
{
	char tem[65];
	sprintf(tem, "UPDATE nuser set phone='%s' where phone='%s'", newNID, ID);
	if (mysql_query(&con, tem))
	{
		return true;
		strcpy(ID, newNID);
	}
	else
		return false;
}
	
char Nuser::verify(char* password)
{
	char n[54];
	sprintf(n, "SELECT password FROM nuser where phone='%s'",this->ID);
	mysql_real_query(&con, n, 54);
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
