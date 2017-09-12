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
	Buyer();
	void buyticket();
	void inquireticket();
	void changeticket();
	void refundtickket();
private:
	Ticket *ticket;

};
#endif // !NUSER_H
