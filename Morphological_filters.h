#ifndef _Morphological_MY_H
#define _Morphological_MY_H
/***********************************
author:enjoy_learn@126.com
edit data:2018-04-09
***********************************/
#define RENEW(a,b,c) a=(b *) realloc((b *)(a),(c)*sizeof(b))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
typedef short S16;//-32768~32767
typedef unsigned short U16;//0~65535
int min_array( int *dInput,int iSigLen);

int max_array( int *dInput,int iSigLen);
/**************************************************
输入：int InputSignal[]：输入波形        int Structure[] ：结构元素数组
      int SignalLength： 波形长度        int StructureLength：结构长度     开闭运算标记：char Flag='1'
输出：int ReturnSignal[]：
编辑日期：
功能：形态滤波开运算
*****************************************************/
void kaibilvbo(int InputSignal[],int Structure[] ,int SignalLength,int StructureLength, char Flag,int ReturnSignal[]);

#endif
