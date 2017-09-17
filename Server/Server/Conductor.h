#pragma once
#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include<iostream>
#include"user.h"
#include"Suser.h"
using namespace std;

class Conducor :public User
{
public:
	/**************************************************************
	函数名称：构造函数
	形参表：用户ID(char*)，密码(char*)
	**************************************************************/
	Conducor(char*, char*);
	/**************************************************************
	函数名称：inquireSuser
	形参表：用户ID(char*)
	返回值：详细信息(char**)
	功能：查询售票员信息
	**************************************************************/
	bool inquireSuser(char*,char*,char**);
	/**************************************************************
	函数名称：check
	形参表：内部密码(char*)
	返回值：bool(true：正确，false：错误)
	功能：内部验证
	**************************************************************/
	bool check(char*);
	/**************************************************************
	函数名称：addSuser
	形参表：用户ID(char*)，密码(char*)
	返回值：bool(true：成功，false：失败)
	功能：增加售票员
	**************************************************************/
	bool addSuser(char*, char*,char*,char*);
	/**************************************************************
	函数名称：changeSuserinfo
	形参表：内部验证密码（char*），旧用户ID(char*)，新用户ID(char*)，密码(char*)
	返回值：bool(true：成功，false：失败)
	功能：更改售票员信息
	**************************************************************/
	bool changeSuserInfo(char*, char*, char*,char*);
	/**************************************************************
	函数名称：deleteUser
	形参表：内部验证密码（char*），用户ID(char*)
	返回值：bool(true：成功，false：失败)
	功能：删除售票员
	**************************************************************/
	bool deleteUser(char*,char*);
	/**************************************************************
	函数名称：addCoach
	形参表：内部验证密码（char*),汽车ID(char*)，发车时间(char*(HHMM))，站点信息(char***)，座位数(char*)
	返回值：bool(true：成功，false：失败)
	功能：增加车辆信息
	**************************************************************/
	bool addCoach(char*, char*, char*, char***,int,char*);
	/**************************************************************
	函数名称：deleteCoach
	形参表：内部验证密码（char*）,汽车ID(char*)
	返回值：bool(true：成功，false：失败)
	功能：删除车辆信息
	**************************************************************/
	bool deleteCoach(char*,char*);
	char verify(char*);
private:
	const char innerPassword[40];
};
#endif // !CONDUCTOR_H
