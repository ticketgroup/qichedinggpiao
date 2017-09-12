#pragma once
#ifndef COACH_H
#define COACH_H

#include<iostream>
#include<string>
#include "mysql.h"
using namespace std;

class Coach
{
public:
	bool setcoachnum(int);
	bool setseatnum(int);
	bool setstation(char**);
	bool settime(int[]);
	static char** getinfo(char*);
private:
	int id;
	int coachnum;
	int seatnum;
	int stationnum;
	char *(station[9]);
	char *(time[5]);
	MYSQL con;
	MYSQL_RES res;
	MYSQL_ROW result;
};
#endif // !COACH_H
Coach::