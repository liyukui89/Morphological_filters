#ifndef _Morphological_MY_H
#define _Morphological_MY_H

#define RENEW(a,b,c) a=(b *) realloc((b *)(a),(c)*sizeof(b))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
typedef short S16;//-32768~32767
typedef unsigned short U16;//0~65535
int min_array( int *dInput,int iSigLen);

int max_array( int *dInput,int iSigLen);
/**************************************************
���룺int InputSignal[]�����벨��        int Structure[] ���ṹԪ������
      int SignalLength�� ���γ���        int StructureLength���ṹ����     ���������ǣ�char Flag='1'
�����int ReturnSignal[]��
�༭���ڣ�
���ܣ���̬�˲�������
*****************************************************/
void kaibilvbo(int InputSignal[],int Structure[] ,int SignalLength,int StructureLength, char Flag,int ReturnSignal[]);

#endif