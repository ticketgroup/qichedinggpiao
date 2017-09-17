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
	形参表：用户ID(char*)
	返回值：char**
	功能：查询用户信息
	**************************************************************/
    bool inquireNuser(char*,char**);
private:
	char *id;


};
#endif // !SELLER_H
