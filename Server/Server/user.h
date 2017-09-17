#pragma once
#ifndef USER_H
#define USER_H

#include "mysql.h"
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	/**************************************************************
	函数名称：构造函数
	形参表：用户ID(char*)，密码(char*)
	**************************************************************/
	User(char[], char[]);
	/**************************************************************
	函数名称：verify                                               
	形参表：用户ID(char*)，密码(char*)                             
	返回值：char('Y'：登陆成功，'1'：用户名不存在，'2'：密码不正确)
	功能：用户登录                                                 
	**************************************************************/
	char virtual verify(char[]) = 0;
	/**************************************************************
	函数名称：cancel
	形参表：none
	返回值：bool(true：注销成功，false：注销失败)
	功能：用户注销
	**************************************************************/
	friend bool cancel(User*);
	
	//(char*) getpassword();
protected:
	char id[11];
	MYSQL con;
	MYSQL_RES res;
	MYSQL_ROW result;
};
#endif