#pragma once
#ifndef SELLER_H
#define SELLER_H

#include<iostream>
#include"Buyer.h"
using namespace std;

class Suer :public Buyer
{
public:
	/**************************************************************
	�������ƣ����캯��
	�βα��û�ID(char*)������(char*)
	**************************************************************/
	Suer(char*, char*);
	/**************************************************************
	�������ƣ�inquireNuser
	�βα��û�ID(char*)
	����ֵ��char**
	���ܣ���ѯ�û���Ϣ
	**************************************************************/
	(char**) inquireNuser(char*);


};
#endif // !SELLER_H
