#ifndef FUNC_H
#define FUNC_H

#include "mysql.h"

void getse(char*id, char*tNum, char *st, char*en);


/**************************************************************
函数名称：str2int
形参表：由数字组成的字符(char*)
返回值：int
功能：将字符中的数转换成数(目前的版本较为简单，调用的时候请确保字符串是一个数)
**************************************************************/
int str2int(char*s);

/**************************************************************
函数名称：gettnum
形参表：汽车ID(char*)，起始地(char*)，终点(char*)，输出(char*)
返回值：bool(true：成功，false：失败)
功能：通过ID，起点，终点，获得票的编码
**************************************************************/
bool gettnum(char *id, char *st, char *en, char *source);
void timeAdd(char *time, char *addM, char *res);
void timeSub(char *time, char *addM, char *res);
int getSeatNum(char *id, char *st, char *en);

#endif //  FUNC_H