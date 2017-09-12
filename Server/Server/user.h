#pragma once
#ifndef USER_H
#define USER_H

#include "mysql.h"
#include<iostream>
#include<string>
#include"Coach.h"
using namespace std;

class User
{
public:
	User(char[], int);
	bool virtual verify(char[]) = 0;
	friend bool cancel(User*);
	void carinfor();
	void allticketinfor();
	void virtual changeinfor() = 0;
	//(char*) getpassword();
private:
	char id[11];
	char name[10];
	Coach *coach;
	MYSQL con;
	MYSQL_RES res;
	MYSQL_ROW result;
};
#endif