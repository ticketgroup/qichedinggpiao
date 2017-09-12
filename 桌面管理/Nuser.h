#pragma once
#ifndef NUSER_H
#define NUSER_H

#include<iostream>
#include<string>
#include"Buyer.h"
using namespace std;

class Nuser :public Buyer
{
public:
	Nuser( );
	void registe();
	void delet();
	void findpassword();
	void changepassword();

private:
	int id;
	int number;

};

#endif // !NUSER_H
