#include<iostream>
#include <cstring>
#include"user.h"
using namespace std;

User::User(char ID[], int len)
{
	mysql_init(&con);
	if (mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0))
	{
		mysql_real_query(&con, strcat("select UID from cinfo where UID = ",ID), len);
		if (res = mysql_store_result(&con))
		{
			for (int i = 0; i < len; i++)
				id[i] = ID[i];
		}
	}
}

bool  User::verify(char ID[11], string password)
{
    
}

void User::cancel() 
{

}

void User::carinfor() 
{

}

void User::allticketinfor()
{

}
void User::changeinfor()
{

}




