#ifndef FUNC_H
#define FUNC_H

#include "mysql.h"

void getse(char*id, char*tNum, char *st, char*en);


/**************************************************************
�������ƣ�str2int
�βα���������ɵ��ַ�(char*)
����ֵ��int
���ܣ����ַ��е���ת������(Ŀǰ�İ汾��Ϊ�򵥣����õ�ʱ����ȷ���ַ�����һ����)
**************************************************************/
int str2int(char*s);

/**************************************************************
�������ƣ�gettnum
�βα�����ID(char*)����ʼ��(char*)���յ�(char*)�����(char*)
����ֵ��bool(true���ɹ���false��ʧ��)
���ܣ�ͨ��ID����㣬�յ㣬���Ʊ�ı���
**************************************************************/
bool gettnum(char *id, char *st, char *en, char *source);
void timeAdd(char *time, char *addM, char *res);
void timeSub(char *time, char *addM, char *res);
int getSeatNum(char *id, char *st, char *en);

#endif //  FUNC_H