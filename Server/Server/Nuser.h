#pragma once
#ifndef NUSER_H
#define NUSER_H

#include<iostream>
#include<string>
#include"Buyer.h"
using namespace std;


/**************************************************************
函数名称：ver
形参表：一卡通(char*)，学号(char*)
返回值：bool(true：成功，false：失败)
功能：注册前验证信息
**************************************************************/
bool ver(char*, char*);
/**************************************************************
函数名称：reg
形参表：一卡通(char*)，学号(char*)，手机号(char*)，密码(char*)
返回值：bool(true：成功，false：失败)
功能：注册普通用户
**************************************************************/
bool reg(char*, char*, char*, char*);
/**************************************************************
函数名称：findPassword
形参表：手机号(char*)，新密码(char*)
返回值：bool(true：成功，false：失败)
功能：找回密码
**************************************************************/
bool findPassword(char*, char*);

class Nuser :public Buyer
{
public:
	/**************************************************************
	函数名称：构造函数
	形参表：用户ID(char*)，密码(char*)
	**************************************************************/
	Nuser(char*, char*);
	/**************************************************************
	函数名称：del
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：删除用户
	**************************************************************/
	bool del();
	/**************************************************************
	函数名称：changePassword
	形参表：新密码(char*)
	返回值：bool(true：成功，false：失败)
	功能：修改密码
	**************************************************************/
	bool changePassword(char*);
	/**************************************************************
	函数名称：changeinfo
	形参表：手机号(char*)
	返回值：bool(true：修改成功，false：修改失败)
	功能：更改用户信息
	**************************************************************/
	bool changeinfo(char*);
	/************************************************************
	函数名称：verify
		形参表：用户ID(char*)，密码(char*)
		返回值：char('Y'：登陆成功，'1'：用户名不存在，'2'：密码不正确)
		功能：普通用户登录
	*************************************************************/
	char  verify(char*);

private:
	char *ID;
	char *password;
};

#endif // !NUSER_H
