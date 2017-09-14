#pragma once
#ifndef SELLER_H
#define SELLER_H

#include<iostream>
#include"Buyer.h"
using namespace std;

class Suser :public Buyer
{
public:
	/**************************************************************
	函数名称：构造函数
	形参表：用户ID(char*)，密码(char*)
	**************************************************************/
	Suser(char*, char*);
	/**************************************************************
	函数名称：inquireNuser
	形参表：用户ID(char*)，用户信息(输出)(char**)
	返回值：bool(true：查询到信息，false：未查询到信息)
	功能：查询用户信息
	**************************************************************/
	bool inquireNuser(char*,char**);
	/**************************************************************
	函数名称：verify
	形参表：用户ID(char*)，密码(char*)
	返回值：char('Y'：登陆成功，'1'：用户名不存在，'2'：密码不正确)
	功能：用户登录
	**************************************************************/
	virtual char verify(char*);

};
#endif // !SELLER_H
