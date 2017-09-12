#include<iostream>
#include <cstring>
#include"user.h"
#include "Ticket.h"
using namespace std;

bool cancel(User* a){ delete a; }

User::User(char ID[], int len)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
}

void User::carinfor() 
{
	coach->getinfo();
}

void User::allticketinfor()
{
	Ticket::search(id);
}



