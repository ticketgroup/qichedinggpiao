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
	/**************************************************************
	函数名称：changeinfo
	形参表：手机号：(char*)
	返回值：bool(true：修改成功，false：修改失败)
	功能：更改用户信息
	**************************************************************/
	bool changeinfo();

private:
	int id;
	int number;

};

#endif // !NUSER_H
