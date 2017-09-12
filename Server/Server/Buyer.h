#pragma once
#ifndef BUYER_H
#define BUYER_H

#include<iostream>
#include<string>
#include"user.h"
#include"Ticket.h"
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
	函数名称：
	形参表：
	返回值：
	功能：
	**************************************************************/
	void buyticket();
	void inquireticket();
	void changeticket();
	void refundtickket();
private:
	Ticket *ticket;

};
#endif // !NUSER_H
