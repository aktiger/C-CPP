/*
Author:justinzhang && zhangzhikai
Email:uestczhangchao@gmail.com
这个程序是章智凯于2011年5月13日23:00:32，叫我帮他修改的，
说来惭愧，我花了1个半小时才找到错误，原来是因为他声明了一个
H[4]的数组，然后直接访问H[4]导致数组下标越界。
虽然浪费了些时间，但是为了兄弟还是值得的~~
另外，我知道了可以在VC下使用的类TC的graphic库，据说是很好用的，
有时间了我好好研究下，下面是它的网址~~
http://www.easyx.cn/
*/

/**************************************************************
系统变量说明
N--系统阶次
R--阶跃信号输入幅值
V--系统反馈系数
M--积分方法选择变量
Q1--计算步长
Q2--打印间隔
Q3--打印点数

subin()--输入模块
subkey()--键盘输入系统参数
subfile()--打开文件读入系统参数
subkij()--计算kij
subhead()--打印显示输出变量及初值
subcrt()--打印显示输出结果
subout()--输出模块

***************************************************************/



# include <graphics.h>
# include <stdio.h>
#include <iostream>
using namespace std;
# include <math.h>
# include <stdlib.h>
# include <conio.h>
//#pragma comment(lib,"graphics.lib")

float A[10][10],B[10],C[10],X[10];
float F[10][10];
float T1[200],YOUT[200],Y;
float K[10][5],D[10][5],H[5],P[10][5],Z[10];//原来的代码这里申明H[4],在79行的时候直接引用H[4],导致数组下标越界
int N,Q2,Q3,V,M;
float Q1,R,T;

void subin();
void subkij();
void subcrt();
void subout();
void subkey();
void subhead();
void subfile();

int main()
{
	int i,j,e,g;

	/***************************************************************/
	
	subin();
	/***************************************************************/
	if(V!=0)
	{
		for(i = 1;i <= N;i++)
			for(j = 1;j <= N;j++)
			{
				F[i][j] = B[i] * C[j] * V;
				A[i][j] = A[i][j] - F[i][j];
			}
	}
	for(i = 1;i <= N;i++)
		K[i][0] = 0.0;
	H[1] = 0.0;
	H[2] = Q1/2;
	H[3] = H[2];
	H[4] = Q1;
	T = 0.0;
	Y = 0.0;
	for(i = 1;i <= N;i++)
		Y = Y + C[i] * X[i];
	YOUT[0] = Y;
	T1[0] = T;

	/***********************************************************************/
	subhead();
	/************************************************************************/
	T1[0] = 0.0;
	for(e = 1;e <= Q3;e++)
	{
		for(g = 1;g <= Q2;g++)
		{
			/************************************************************************/
			subkij();
			/*************************************************************************/
			for(i = 1;i <= N;i++)
			{
				if(M == 1)
					X[i] = X[i] + Q1 * K[i][1];
				else 
					if(M == 2)
						X[i] = X[i] + Q1 * (K[i][1] + K[i][2]/2);
					else
						if(M ==4)
							X[i] = X[i] + Q1 * (K[i][1] + 2 * K[i][2] + 2 * K[i][3] + K[i][4])/6;
			}
			T = T + Q1;
			Y = 0.0;
			for(i = 1;i <= N;i++)
				Y = Y + C[i] * X[i];
		}
		/******************************************************************************************/
		subcrt();
		/******************************************************************************************/
		YOUT[e] = Y;
		T1[e] = T;
	}
	getch();
	closegraph();
	while (1);
}
/********************************* end main  *************************************************/

/**********************************************************************************************/
void subin()
{
	int KK;
	printf("Please Input N,R,V,M\n");
	
	scanf("%d,%f,%d,%d",&N,&R,&V,&M);
	cout << N << " " << R << " " << V << " " << M << endl;
	printf("Please Input Q1,Q2,Q3\n");
	scanf("%f,%d,%d",&Q1,&Q2,&Q3);
	cout << Q1 << Q2 << Q3 << endl;
	printf("**********************************************************************\n");
	printf("* 1.First time input or modify system parameters .\n0.not .   *\n");
	printf("**********************************************************************\n");
	printf("Please Choose the number of iut model\n");
	scanf("%d",&KK);
	if(KK == 1)
		subkey();
	else
		subfile();
}


/***************************************************************************************/
void subkey()
{
	int i,j,I1,J1;
	float A1;
	FILE *fp1,*fp2;
	for(i = 1;i <= N;i++)
		for(j = 1;j <= N;j++)
			A[i][j] = 0.0;
	printf("Please Enter I1,J1,A1\n");
	do
	{
		//scanf("%d,%d,%f",&I1,&J1,&A1);
		cin>>I1>>J1>>A1;
		cout << "****"<< endl;
		cout << I1 << J1 << A1 << endl;
		cout << "****"<< endl;
		A[I1][J1] = A1;
	}while((I1 + J1) != 0);
	for(i = 1;i <= N;i++)
	{
		printf("Please Enter B[%d],C[%d],X[%d]\n",i,i,i);
		scanf("%f,%f,%f",&B[i],&C[i],&X[i]);
	}
	if((fp1=fopen("z-data1.txt","w+"))==NULL) //打开文本文件txt文件
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	if((fp2=fopen("z-data2.txt","w+"))==NULL) //打开文本文件txt文件
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	for(i = 1;i <= N;i++)
		for(j = 1;j <= N;j++)
			fprintf(fp1,"%f\n",A[i][j]);
	for(i = 1;i <= N;i++)
		fprintf(fp2,"%f,%f,%f\n",B[i],C[i],X[i]);
	fclose(fp1);
	fclose(fp2);
}

/************************************************************************/
void subfile()
{
	int i,j;
	FILE *fp1,*fp2;
	if((fp1=fopen("z-data1.txt","w+"))==NULL) //打开文本文件txt文件
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	if((fp2=fopen("z-data2.txt","w+"))==NULL) //打开文本文件txt文件
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	for(i = 1;i <= N;i++)
		for(j = 1;j <= N;j++)
			fscanf(fp1,"%16f\n",&A[i][j]);
	for(i = 1;i <= N;i++)
		fscanf(fp2,"%16f,%16f,%16f\n",&B[i],&C[i],&X[i]);
	fclose(fp1);
	fclose(fp2);
}


/****************************************************************/
void subhead()
{
	printf("T\t\tY\n");
	printf("%-8f\t%-8f\n",T,Y);
}

/***************************************************************/
void subkij()
{
	int i,j,L;
	for(j = 1;j <= M;j++)
	{
		for(i = 1;i <= N;i++)
		{
			P[i][j] = H[j] * K[i][j - 1];
			Z[i] = P[i][j] + X[i];
		}
		for(i = 1;i <= N;i++)
		{
			D[i][j] = 0.0;
			for(L = 1;L <= N;L++)
				D[i][j] = D[i][j] + A[i][L] * Z[L];
			K[i][j] = D[i][j] + B[i] * R;
		}
	}
}


/*************************************************************************/
void subcrt()
{
	printf("%-8f\t%-8f\n",T,Y);
}

/**************************************************************************/
void subout()
{
	int i,j;
	int xx0[100],yy0[100],N1,ip;
	FILE *fpo;
	setbkcolor(0);
	printf("**********************************************************************\n");
	printf("*     1.CRT\n2.Printer\n ");
	printf("**********************************************************************\n");
	printf("Please Choose the number of output model\n");
	scanf("%d",&ip);
	printf("Please Enter the number of printed N1\n");
	scanf("%d",&N1);

	switch(ip)
	{
	case 1:
		printf("T\t\tY\n");
		for(i = 0;i <= N;i++)
			printf("%-8f\t%-8f\n",T1[i],YOUT[i]);
		break;
	case 2:
		if((fpo=fopen("r-data.txt","w"))==NULL) //打开文本文件txt文件
        {
         	printf("can not open this file\n");
		    exit(0);
        }
		fprintf(fpo,"T\t\tY\n");
	    for(i = 0;i <= N1;i++)
		fprintf(fpo,"%-8f\t%-8f\n",T1[i],YOUT[i]);
	    fclose(fpo);
		break;
	}
}