#pragma once
#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include"Coach.h"
using namespace std;

class User
{
public:
		User(char[]);
		void virtual verify(char[],string);
		void cancel();
		void carinfor();
		void allticketinfor();
		void virtual changeinfor();
		(char*) getpassword();
private:
	char id[11];
	char name[10];
	Coach *coach;



};
#endif