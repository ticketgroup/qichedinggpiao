#pragma once
#ifndef USER_H
#define USER_H

#include "mysql.h"
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	/**************************************************************
	�������ƣ����캯��
	�βα��û�ID(char*)������(char*)
	**************************************************************/
	User(char[], char[]);
	/**************************************************************
	�������ƣ�verify                                               
	�βα��û�ID(char*)������(char*)                             
	����ֵ��char('Y'����½�ɹ���'1'���û��������ڣ�'2'�����벻��ȷ)
	���ܣ��û���¼                                                 
	**************************************************************/
	char virtual verify(char[]) = 0;
	/**************************************************************
	�������ƣ�cancel
	�βα�none
	����ֵ��bool(true��ע���ɹ���false��ע��ʧ��)
	���ܣ��û�ע��
	**************************************************************/
	friend bool cancel(User*);
	
	//(char*) getpassword();
protected:
	char id[11];
	MYSQL con;
	MYSQL_RES res;
	MYSQL_ROW result;
};
#endif