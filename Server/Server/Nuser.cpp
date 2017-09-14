#include<iostream>

#include "Nuser.h"

bool verify(char ID[11], char pass[11])
{
	for (int i = 0; i<10;i++)
	{
		if (ID[i] !=  [i])
			return false;
	}
	for (int i = 0; [i] != 0; i++)
	{
		if (pass[i] != [i])
			return false;
	}
	return true;
}

bool reg(int idnum, int number, char ID[11], char password[11])
{
	if ()
		return true;
	else
		return false;
}

bool findPassword(char ID[11], char newpass[11], , )
{

	if ()
		return true;
	else
		return false;
}

Nuser::Nuser(char NID[11], char Npass[11]):Buyer(NID,Npass)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "user", 3306, NULL, 0);
	for (int i = 0; i < 11; i++)
		ID[i] = NID[i], password[i] = Npass[i];
}

bool Nuser::del()
{
	if ()
		return true;
	else
		return false;
}

bool Nuser::changePassword(char newpass[11])
{
	if ()
	{
		for (int i = 0; i < 11; i++)
			password[i] = newpass[i];
		return true;
	}
	else
		return false;
}

bool Nuser::changeinfo(char newNID[11])
{
	if ()
	{
		for (int i = 0; i < 11; i++)
			ID[i] = newNID[i];
		return true;
	}
	else
		return false;
}
	
char Nuser::verify(char NID[11], char Npass[11])
{
	if ()
		return '1';
	else if ()
		return '2';
	else
		return 'Y';
}
