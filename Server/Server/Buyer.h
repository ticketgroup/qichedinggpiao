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
	�������ƣ����캯��
	�βα��û�ID(char*)������(char*)
	**************************************************************/
	Buyer(char*, char*);
	/**************************************************************
	�������ƣ�
	�βα�
	����ֵ��
	���ܣ�
	**************************************************************/
	void buyticket();
	void inquireticket();
	void changeticket();
	void refundtickket();
private:
	Ticket *ticket;

};
#endif // !NUSER_H
