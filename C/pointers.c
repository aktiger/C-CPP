/*
*
*This program file is used to practice the use of pointers and arrays.
*The aim of this program is to test the appconfig of autosar os.
*
*时间：2011年8月17日16:35:52
*作者：张超
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\编程练习\C-C++\global.h"

#if pointers==stdon

#include <stdio.h>

#define OS_APPLICATION_CNT 2
#define CONFIG_OSEK_ALARM_NUMBER 3

typedef struct 
{
	int alarmid;
	int period;
}T_OSEK_ALARM_ControlBlock;

typedef T_OSEK_ALARM_ControlBlock*  AlarmType;

typedef struct
{
	AlarmType * alarmref;

}T_AUTOSAR_APPLICATION_ConfigTable;

T_AUTOSAR_APPLICATION_ConfigTable Autosar_Config_AppTable[OS_APPLICATION_CNT];

int Autosar_Config_Application_AlarmCount[OS_APPLICATION_CNT]={3,2};

T_OSEK_ALARM_ControlBlock osekAlarm_AlarmTable[CONFIG_OSEK_ALARM_NUMBER]={{1,2},{3,4},{5,6}};

AlarmType Autosar_Config_Application_AlarmTable[OS_APPLICATION_CNT][CONFIG_OSEK_ALARM_NUMBER]=
{
	{&osekAlarm_AlarmTable[0],&osekAlarm_AlarmTable[2],&osekAlarm_AlarmTable[1]},
	{&osekAlarm_AlarmTable[1],&osekAlarm_AlarmTable[2]},
};

int main()
{
	int i;
	int j;
	for (i=0; i<OS_APPLICATION_CNT;i++)
	{
		Autosar_Config_AppTable[i].alarmref = &Autosar_Config_Application_AlarmTable[i];
	}

	for (i=0;i<OS_APPLICATION_CNT;i++)
	{
		printf("App%d\n",i+1);
		for (j=0;j<Autosar_Config_Application_AlarmCount[i];j++)
		{
			printf("Alarm%d :%d\t%d\t",j+1,Autosar_Config_AppTable[i].alarmref[j]->alarmid,Autosar_Config_AppTable[i].alarmref[j]->period);
		}
		printf("\n**********************************************************************\n");
	}
	system("pause");
	return 0;
}

#endif