#pragma once
#ifndef COACH_H
#define COACH_H

#include<iostream>
#include<string>
using namespace std;

class Coach
{
public:
	Coach();
	bool setcoachnum(int);
	bool setseatnum(int);
	bool setstation(char**);
	bool settime(int[]);
	(const char**)getinfo();
private:
    int coachnum;
	int seatnum;
	int stationnum;
	char *(station[9]);
	char *(time[5]);

		

};
#endif // !COACH_H
	