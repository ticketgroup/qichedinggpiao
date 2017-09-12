#include<iostream>
#include <cstring>
#include"user.h"
using namespace std;

bool cancel(User* a)
{ delete a; }

User::User(char ID[], int len)
{
	mysql_init(&con);
}

void User::carinfor() 
{

}

void User::allticketinfor()
{

}



