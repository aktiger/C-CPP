#include <iostream>
#include <ctime>
#include <iterator>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(){}
	Point(int m_x, int m_y)
		:x(m_x), y(m_y){}
};
/************************************************************************/
/* 函数功能：按点的X坐标排序                                            */
/************************************************************************/
struct CmpX : public binary_function<bool, Point, Point>
{
	bool operator() (const Point& lhs, const Point& rhs)
	{
		return (lhs.x < rhs.x);
	}
};
/************************************************************************/
/* 函数功能：按点的Y坐标排序                                            */
/************************************************************************/
struct CmpY : public binary_function<bool, Point, Point>
{
	bool operator() (const Point& lhs, const Point& rhs)
	{
		return (lhs.y < rhs.y);
	}
};
/************************************************************************/
/*  类功能：产生无重复的随机数	
类成员：num    表示要产生的随机数的个数
bound  表示每个随机数的范围[0, bound-1).                    */
/************************************************************************/
class Random
{
public:
	explicit Random(int m_num, int m_bound)
		:num(m_num), bound(m_bound)
	{
		arr = new int[m_bound];
		for(int i = 0; i < bound; i++)
			arr[i] = i;
	}
	int* GetResult()
	{
		int temp = 0;
		srand((unsigned)time(0));
		for (int i = 0; i < num; i++)
		{
			temp = rand() % (bound - i - 1) + i;
			swap(arr[i], arr[temp]);
		}
		return arr;
	}
	~Random()
	{
		delete []arr;
	}
private:
	int *arr;
	int num;	//随机数的个数
	int bound;  //随机数的范围
};
/************************************************************************/
/* 函数功能：求两点间的距离                                             */
/************************************************************************/
inline double Distance(const Point& lhs, const Point& rhs)
{
	int x_diff = lhs.x - rhs.x;
	int y_diff = lhs.y - rhs.y;
	double res = x_diff * x_diff + y_diff *y_diff;
	return sqrt(res);
}
/************************************************************************/
/* 函数功能：求数组中两点间的最短距离                                   */
/************************************************************************/
double GetShortestDistace(Point arr[], int low, int high)
{
	double result = 0.;

	if (high - low < 3) //小于等于3个点时
	{
		if (high - low == 1) //2个点时
		{
			double distance = Distance(arr[low], arr[high]);
			return distance;
		}
		else //3个点
		{
			double distance1 = Distance(arr[low], arr[low + 1]);
			double distance2 = Distance(arr[low], arr[low + 2]);
			double distance3 = Distance(arr[low + 1], arr[low + 2]);
			return min(min(distance1, distance2), distance3);
		}
	}
	int middle = (low + high) / 2;
	double left_distance = GetShortestDistace(arr, low, middle);		//求middle左边的最短距离
	double right_distance = GetShortestDistace(arr, middle + 1, high);	//求middle右边的最短距离

	double delta = min(left_distance, right_distance); //中间区域的界限
	result = delta;
	vector<Point> midArea;	//存放中间条带区域的点
	for (int k = low; k < high; k++)
	{
		if(arr[k].x > arr[middle].x - delta && arr[k].x < arr[middle].x + delta)
			midArea.push_back(arr[k]);
	}
	sort(midArea.begin(), midArea.end(), CmpY()); //按Y坐标排序
	int size = midArea.size();
	for (int i = 0; i < size; i++)
	{
		int k = (i + 7) > size ? size : (i+7);	//只有选取出7个点(证明过程没看懂)
		for (int j = i+1; j < k; j++)
		{
			if(Distance(midArea.at(i), midArea.at(j)) < result)
				result = Distance(midArea.at(i), midArea.at(j));
		}
	}
	return result;
}

#define N 100 //点的个数
int main()
{
	Point arr[N];
	Random random(2*N, 1000);
	int *result = random.GetResult();
	for (int i =0; i < N; i++)
		arr[i] = Point(result[i], result[i + N]);
	sort(arr, arr + N, CmpX());
	double res = GetShortestDistace(arr, 0, N);
	cout<<"The shortest distance is:"<<res<<endl;
}