#pragma once
#ifndef SELLER_H
#define SELLER_H

#include<iostream>
#include"Buyer.h"
using namespace std;

class Suser :public Buyer
{
public:
	/**************************************************************
	�������ƣ����캯��
	�βα��û�ID(char*)������(char*)
	**************************************************************/
	Suser(char*, char*);
	/**************************************************************
	�������ƣ�inquireNuser
	�βα��û�ID(char*)
	����ֵ��char**
	���ܣ���ѯ�û���Ϣ
	**************************************************************/
    bool inquireNuser(char*,char**);
private:
	char *id;


};
#endif // !SELLER_H
