#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Morphological_filters.h"

int min_array( int *dInput,int iSigLen)
{
	int dMinValue;
	int i;
	dMinValue = dInput[0];
	for( i = 1;i <= iSigLen - 1 ;i++ )	{
		
		if( dMinValue > dInput[i])	{
			
			dMinValue = dInput[i];
		}
	}
	return dMinValue;
}
int max_array( int *dInput,int iSigLen)
{
	int dMaxValue;
	int i;
	dMaxValue = dInput[0];
	for( i = 1;i <= iSigLen - 1 ;i++ )	{
		
		if( dMaxValue < dInput[i])	{
			
			dMaxValue = dInput[i];
		}
	}
	return dMaxValue;
}


void kaibilvbo(int InputSignal[],int Structure[] ,int SignalLength,int StructureLength, char Flag,int ReturnSignal[])
{

	int lengthf=SignalLength;
	int lengthg=StructureLength;
	int i,m,n;
	int min_value;
	int a1;
	int *a=(int *)malloc(sizeof(int) * StructureLength);


	int *f_g1=(int *)malloc(sizeof(int) * SignalLength);//一次腐蚀存储
	int *f_gg1=(int *)malloc(sizeof(int) * SignalLength);//一次膨胀存储
	int *f_g2=(int *)malloc(sizeof(int) * SignalLength);//二次膨胀存储
	int *f_gg=(int *)malloc(sizeof(int) * SignalLength);//二次腐蚀存储


	if (Flag!='1'){
		printf("error input :kaibilvbo Flag !=1\n;");
		return ;
	}

	for (n=0;n<lengthf;n++){
	   min_value=min(lengthg,(lengthf-n));
	   if (min_value!=lengthg)
			RENEW(a,int,min_value);
	   for ( m=0;m<min_value;m++){
	      a1=InputSignal[n+m]-Structure[m];
		   a[m]=a1;
		}
	      f_g1[n]= min_array(a,min_value);
	}
	//完成腐蚀运算

	for (n=0;n<SignalLength;n++){
		min_value=min(n+1,lengthg);
		if (min_value!=lengthg)
			RENEW(a,int,min_value);
		for (m=0;m<min_value;m++){
			 a1=f_g1[n-m]+Structure[m];
			  a[m]=a1;
		}
		  f_gg1[n]=max_array(a,min_value+1);
	}
	//完成膨胀运算;------------完成一次开运算。
	for (n=0;n<SignalLength;n++){
		min_value=min(n+1,lengthg);
		if (min_value!=lengthg){
		  RENEW(a,int,min_value);
		}
		for (m=0;m<min_value;m++){
		      a1=f_gg1[n-m]+Structure[m];
			  a[m]=a1;
		}
		 f_g2[n]=max_array(a,min_value);
		
	}
	//完成二次膨胀运算
	for (n=0;n<SignalLength;n++){
		min_value=min((lengthf-n),lengthg);
		 if (min_value!=lengthg){
			RENEW(a,int,min_value);
		 }
		for (m=0;m<min_value;m++){
		   a1=f_g2[n+m]-Structure[m];
		   a[m]=a1;
		}
		  f_gg[n]=min_array(a,min_value);
	}
//完成二次腐蚀运算。完成闭运算。
	//memcpy(ReturnSignal,f_gg,SignalLength);
	for (i=0;i<SignalLength;i++)
		ReturnSignal[i]=f_gg[i];

	free(f_g1);
	f_g1=NULL;
	free(f_gg1);
	f_gg1=NULL;
	free(f_g2);
	f_g2=NULL;
	free(f_gg);
	f_gg=NULL;


	free(a);
	a=NULL;
}
