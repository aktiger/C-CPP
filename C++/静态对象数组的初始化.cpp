/*
*
*时间：2012年3月9日13:07:20
*作者：张超
*Email:uestczhangchao@gmail.com
*/


#include <iostream>
using namespace std;

void func()
{
	cout << "in func" << endl;
}

class ScheduleTable
{
public:
	static ScheduleTable stb[10];

	ScheduleTable()
	{
		cout << "ScheduleTable constructor!!\n";
		//cout << "in func" << endl;
	}
	ScheduleTable(int x,int y)
	{
		cout << "ScheduleTable(int x)" << endl;
		this->x = x;
	}
protected:
private:
	int x;
};




ScheduleTable ScheduleTable::stb[10];//={0};



int main()
{
	//ScheduleTable stb = ScheduleTable(1);
	return 0;
}