/*
Author:justinzhang && zhangzhikai
Email:uestczhangchao@gmail.com
������������ǿ���2011��5��13��23:00:32�����Ұ����޸ĵģ�
˵���������һ���1����Сʱ���ҵ�����ԭ������Ϊ��������һ��
H[4]�����飬Ȼ��ֱ�ӷ���H[4]���������±�Խ�硣
��Ȼ�˷���Щʱ�䣬����Ϊ���ֵܻ���ֵ�õ�~~
���⣬��֪���˿�����VC��ʹ�õ���TC��graphic�⣬��˵�Ǻܺ��õģ�
��ʱ�����Һú��о��£�������������ַ~~
http://www.easyx.cn/
*/

/**************************************************************
ϵͳ����˵��
N--ϵͳ�״�
R--��Ծ�ź������ֵ
V--ϵͳ����ϵ��
M--���ַ���ѡ�����
Q1--���㲽��
Q2--��ӡ���
Q3--��ӡ����

subin()--����ģ��
subkey()--��������ϵͳ����
subfile()--���ļ�����ϵͳ����
subkij()--����kij
subhead()--��ӡ��ʾ�����������ֵ
subcrt()--��ӡ��ʾ������
subout()--���ģ��

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
float K[10][5],D[10][5],H[5],P[10][5],Z[10];//ԭ���Ĵ�����������H[4],��79�е�ʱ��ֱ������H[4],���������±�Խ��
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
	if((fp1=fopen("z-data1.txt","w+"))==NULL) //���ı��ļ�txt�ļ�
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	if((fp2=fopen("z-data2.txt","w+"))==NULL) //���ı��ļ�txt�ļ�
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
	if((fp1=fopen("z-data1.txt","w+"))==NULL) //���ı��ļ�txt�ļ�
        {
         	printf("can not open this file\n");
		    exit(0);
        }
	if((fp2=fopen("z-data2.txt","w+"))==NULL) //���ı��ļ�txt�ļ�
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
		if((fpo=fopen("r-data.txt","w"))==NULL) //���ı��ļ�txt�ļ�
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