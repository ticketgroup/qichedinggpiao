#pragma once
#ifndef USER_H
#define USER_H

#include "mysql.h"
#include<iostream>
#include<string>
#include"Coach.h"
using namespace std;

class User
{
public:
	/**************************************************************
	�������ƣ����캯��
	�βα��û�ID(char*)������(char*)
	**************************************************************/
	User(char*, char*);
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
	friend bool cancel();
	/**************************************************************
	�������ƣ�allticketinfo
	�βα�����ID(char*)������(char*(MMDD))
	����ֵ��Ʊ��(char)
	���ܣ����ʣ�೵Ʊ��
	**************************************************************/
	int allticketinfo(char*, char*);
	//(char*) getpassword();
protected:
	char id[11];
	char name[10];
	Coach *coach;
	MYSQL con;
	MYSQL_RES res;
	MYSQL_ROW result;
};
#endif