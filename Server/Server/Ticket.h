#pragma once
#ifndef TICKET_H
#define TICKET_H

#include<iostream>
#include<string>
#include"Coach.h"
using namespace std;

class Ticket
{
public:
	Ticket();
	static void search(char[]);
	void getinfo();
	void buy();
	void change();
	void refund();
	int getsitnum();
	int getmonth();
	int getday();
	char *getbuyer();
    char *getpassenger();
	Coach *getcoach();
private:
	int sitnum;
	Coach *coach;
	int month;
	int day;
    char *buyer[10];
	char *passenger[10];
};
#endif // !TICKET_H
