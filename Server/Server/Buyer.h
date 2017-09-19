#ifndef BUYER_H
#define BUYER_H

#include <iostream>
#include <string>
#include "user.h"
#include "Ticket.h"
using namespace std;

class Buyer :public User
{
public:
	/**************************************************************
	函数名称：构造函数
	形参表：用户ID(char*)，密码(char*)
	**************************************************************/
	Buyer(char*, char*);
	/**************************************************************
	函数名称：carinfo
	形参表：日期(char*(MMDD))，起点(char*)，终点(char*)
	返回值：char***(符合条件的汽车固定信息，按照时间排序)
	功能：查询汽车固定信息
	注释：一天一发
	**************************************************************/
	bool carinfo(char*, char*, char*,char***);
	/**************************************************************
	函数名称：allticketinfo
	形参表：汽车ID(char*)，日期(char*(MMDD)),起点（char*），终点（char*)
	返回值：票数(char)
	功能：获得剩余车票数
	**************************************************************/
	int allticketinfo(char*, char*,char*,char*);
	/**************************************************************
	函数名称：chooseticket
	形参表：要操作的票(Ticket*)
	返回值：void
	功能：绑定需要操作的票
	**************************************************************/
	void chooseticket(const char*,const char*,const char*,const char*,const char*,const char*);
	/**************************************************************
	函数名称：buyticket
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：买票
	**************************************************************/
	bool buyticket();
	/**************************************************************
	函数名称：changeticket
	形参表：汽车ID(char*)，日期(char*(MMDD))
	返回值：bool(true：成功，false：失败)
	功能：改签
	**************************************************************/
	bool changeticket(char*, char*,char*);
	/**************************************************************
	函数名称：refundticket
	形参表：none
	返回值：bool(true：成功，false：失败)
	功能：退票
	**************************************************************/
	bool refundticket();
protected:
	Ticket *ticket;

};
#endif // !NUSER_H
