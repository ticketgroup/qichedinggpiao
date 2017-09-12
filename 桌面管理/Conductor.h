#pragma once
#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include<iostream>
#include"user.h"
#include"Suser.h"
#include"Nuser.h"
using namespace std;

class Conducor :public user
{
public:
	void inquireUser();
	void check();
	void addUser();
	void changeUserInfor();
	void deleteSuser();
	void addCoach();
	void changeCoachInfor();
	void deleteCoach();
private:
	char setPassword[40];



};
#endif // !CONDUCTOR_H
