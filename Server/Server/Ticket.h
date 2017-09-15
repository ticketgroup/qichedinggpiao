#pragma once
#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "mysql.h"

int str2int(char*);

class Ticket
{
public:
	/**************************************************************
	函数名称：getse
	形参表：起始地(输出)(char*)，到达地(输出)(char*)
	返回值：void
	功能：查询票对应的起始地与到达地
	**************************************************************/
	void getse(char*, char*);
	/**************************************************************
	函数名称：构造函数
	形参表：汽车ID(char*)，票num(char*)，日期(char*(MMDD))，购票人(char*)，乘车人(char*)，座位号(char*)
	**************************************************************/
	Ticket(const char*, const char*, const char*, const char*, const char*, const char*);
	/**************************************************************
	函数名称：buy
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：购买车票
	**************************************************************/
	bool buy();
	/**************************************************************
	函数名称：change
	形参表：汽车ID(char*)，日期(char*(MMDD))，座位号(char*)
	返回值：bool(true：成功，false：失败)
	功能：修改车票信息
	**************************************************************/
	bool change(char*, char* , char*);
	/**************************************************************
	函数名称：refund
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：退票
	**************************************************************/
	bool refund();
	/**************************************************************
	函数名称：getinfo
	形参表：车票信息(char***)
	返回值：bool(true：成功，false：失败)
	功能：获取车票信息
	**************************************************************/
	bool getinfo(char**);
private:
	char id[6];
	char seatnum[3];
	char tNum[21];
	char date[5];
    char buyer[10];
	char passenger[10];
	MYSQL con;
	MYSQL_RES* res;
	MYSQL_ROW row;
};
#endif // !TICKET_H
