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
	int getcaachnum();
	int getsitnum();
	int stationnum();
	char *getstation();
	char *gettime();

private:
    int coachnum;
	int sitnum;
	int stationnum;
	char *station[32];
	char *time[4];

		

};
#endif // !COACH_H
	