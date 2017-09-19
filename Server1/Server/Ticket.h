#pragma once
#ifndef TICKET_H
#define TICKET_H

#include<iostream>
#include<string>
using namespace std;


int str2int(char*);
bool getnum(char*, char*, char*, char*);
int getSeatNum(char*, char*,char*);
class Ticket
{
public:
	/**************************************************************
	函数名称：买票时的构造函数
	形参表：汽车ID(char*)，票num(char*)，日期(char*(MMDD))，购票人(char*)，乘车人(char*),座位号（char*)
	**************************************************************/
	Ticket(const char*,const char*,const char*,const char*,const char*,const char*);
	/**************************************************************
	函数名称：查票时的构造函数
	形参表：汽车ID(char*)，座位号(char*)，票num(char*),日期(char*(MMDD))
	**************************************************************/
	//Ticket(char*,char*,char*,char*);
	/**************************************************************
	函数名称：buy
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：购买车票
	**************************************************************/
	bool buy();
	/**************************************************************
	函数名称：change
	形参表：汽车ID(char*)，日期(char*(MMDD))
	返回值：bool(true：成功，false：失败)
	功能：修改车票信息
	**************************************************************/
	bool change(char*,char*,char*);
	/**************************************************************
	函数名称：refund
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：退票
	**************************************************************/
	bool refund();
	void getse(char*, char*);
private:
	int seatnum;
	char date[5];
    char *buyer[10];
	char *passenger[10];
	char tNum;
	char id;
};
#endif // !TICKET_H
