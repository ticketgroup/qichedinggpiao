#include<iostream>
#include<cstring>
#include "Nuser.h"
#include "func.h"
using namespace std;

bool Nuser::inquireticket(char*** info)
{
	MYSQL coa;
	MYSQL_RES* cres;
	MYSQL_ROW row;
	mysql_init(&coa);
	mysql_real_connect(&coa, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	char temp[150];
	char st[5];
	char t[5];
	char n[58];
	sprintf(n, "SELECT id FROM nuser where phone='%s';", this->id);
	mysql_real_query(&con, n, 58);
	res = mysql_store_result(&con);
	result = mysql_fetch_row(res);
	sprintf(temp, "select id,ticketnum,date,passenger,seatid from ticket where buyer='%s';", result[0]);
	mysql_real_query(&coa, temp, 82);
	if (res = mysql_store_result(&coa))
	{
		int i = 0;
		for (; row = mysql_fetch_row(res); i++)
		{
			strcpy(info[i][0], row[0]);
			strcpy(info[i][1], row[4]);
			strcpy(info[i][7], row[2]);
			/*info[i][7][5] = '\0';
			info[i][7][4] = info[i][7][3];
			info[i][7][3] = info[i][7][2];
			info[i][7][2] = '/';*/


			mysql_query(&con, "SET NAMES 'gbk';");
			sprintf(temp, "select name,id from cinfo where id='%s';", row[3]);
			mysql_real_query(&con, temp, 50);
			cres = mysql_store_result(&con);
			result = mysql_fetch_row(cres);
			strcpy(info[i][6], result[0]);
			strcpy(info[i][8], result[1]);

			getse(row[0], row[1], info[i][2], info[i][4]);
			sprintf(temp, "select starttime from coach where id='%s';", info[i][0]);
			mysql_real_query(&coa, temp, 60);
			cres = mysql_store_result(&coa);
			strcpy(st, mysql_fetch_row(cres)[0]);
			 sprintf(temp, "select rownum from stov where station='%s' union select rownum from stov where station='%s';", info[i][4], info[i][2]);
			mysql_real_query(&coa, temp, 200);
			cres = mysql_store_result(&coa);
			char t[5];
			char b[6];
			sprintf(temp, "select a%s from ctos where id = '%s' union select a%s from ctos where id = '%s'; ", mysql_fetch_row(cres)[0], info[i][0], mysql_fetch_row(cres)[0], info[i][0]);
			mysql_real_query(&coa, temp, 200);
			cres = mysql_store_result(&coa);
			row = mysql_fetch_row(cres);

			sprintf(t, "%04s", strtok(row[0], ","));
			timeAdd(st, t, info[i][3]);


			row = mysql_fetch_row(cres);
			sprintf(t, "%04s", strtok(row[0], ","));
			timeAdd(st, t, info[i][5]);

		}
		if(i)
			strcat(info[i - 1][8], "$");
		else
		{
			info[0][0][0] = '$';
			info[0][0][1] = '\0';
		}
		return true;
	}
	else
		return false;	
}
bool ver(char *Id, char *num)
{
	MYSQL con;
	MYSQL_RES* res;
	MYSQL_ROW result;
	mysql_init(&con);
	mysql_real_connect(&con,"localhost","root","111111","user",3306,NULL,0);
	char v[47];
	sprintf(v, "SELECT number FROM cinfo where ID='%s';", Id);
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
	MYSQL con;
	MYSQL_RES* res;
	MYSQL_ROW result;
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
	char tem[150];
	sprintf(tem, "INSERT INTO nuser(id,phone,password) VALUES('%s','%s','%s');", idnum, ID, password);
	if (!mysql_query(&con, tem))
	{
		return true;
	}
	else
		return false;

}

bool findPassword(char *ID, char *newpass)
{
	MYSQL con;
	MYSQL_RES* res;
	MYSQL_ROW result;
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
	char tem[150];
	sprintf(tem, "UPDATE nuser set password='%s' where phone='%s';", newpass, ID);
	if (!mysql_query(&con, tem))
		return true;
	else
		return false;
	
}

Nuser::Nuser(char *NID, char *Npass):Buyer(NID,Npass)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
}

bool Nuser::del()
{
	char tem[45];
	sprintf(tem, "DELETE FROM nuser where phone='%s';", ID);
	if (!mysql_query(&con, tem))
		return true;
	else
		return false;
}

bool Nuser::changePassword(char *newpass)
{
	char tem[150];
	sprintf(tem, "UPDATE nuser set password='%s' where phone='%s';", newpass, ID);
	if (!mysql_query(&con, tem))
		return true;
	else
		return false;
}
bool Nuser::inquireInfo(char **out)
{
	char a[58];
	sprintf(a, "SELECT id FROM nuser where phone='%s';", id);
	mysql_real_query(&con, a, 58);
	res = mysql_store_result(&con);
	if (result = mysql_fetch_row(res))
	{
		strcpy(out[0], ID);
		strcpy(out[1], result[0]);
		//strcpy(out[2], result[1]);
		char b[72];
		mysql_query(&con, "SET NAMES 'GBK';");
		sprintf(b, "SELECT number,name FROM cinfo where id='%s';", result[0]);
		mysql_real_query(&con, b, 72);
		res = mysql_store_result(&con);
		result = mysql_fetch_row(res);
		strcpy(out[2], result[0]);
		strcpy(out[3], result[1]);
		return true;
	}
	else
		return false;

}
bool Nuser::changeinfo(char *newNID)
{
	char tem[65];
	sprintf(tem, "UPDATE nuser set phone='%s' where phone='%s';", newNID, id);
	if (!mysql_query(&con, tem))
	{
		return true;
		strcpy(ID, newNID);
	}
	else
		return false;
}
	
char Nuser::verify(char* password)
{
	char n[58];
	sprintf(n, "SELECT password,id FROM nuser where phone='%s';", this->id);
	mysql_real_query(&con, n, 58);
	res = mysql_store_result(&con);
	if (result = mysql_fetch_row(res))
	{
		if (!strcmp(result[0], password))
		{
			return 'Y';
		}
		else
			return '2';
	}
	else
		return '1';
}
