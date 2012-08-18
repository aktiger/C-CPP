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
/* �������ܣ������X��������                                            */
/************************************************************************/
struct CmpX : public binary_function<bool, Point, Point>
{
	bool operator() (const Point& lhs, const Point& rhs)
	{
		return (lhs.x < rhs.x);
	}
};
/************************************************************************/
/* �������ܣ������Y��������                                            */
/************************************************************************/
struct CmpY : public binary_function<bool, Point, Point>
{
	bool operator() (const Point& lhs, const Point& rhs)
	{
		return (lhs.y < rhs.y);
	}
};
/************************************************************************/
/*  �๦�ܣ��������ظ��������	
���Ա��num    ��ʾҪ������������ĸ���
bound  ��ʾÿ��������ķ�Χ[0, bound-1).                    */
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
	int num;	//������ĸ���
	int bound;  //������ķ�Χ
};
/************************************************************************/
/* �������ܣ��������ľ���                                             */
/************************************************************************/
inline double Distance(const Point& lhs, const Point& rhs)
{
	int x_diff = lhs.x - rhs.x;
	int y_diff = lhs.y - rhs.y;
	double res = x_diff * x_diff + y_diff *y_diff;
	return sqrt(res);
}
/************************************************************************/
/* �������ܣ�����������������̾���                                   */
/************************************************************************/
double GetShortestDistace(Point arr[], int low, int high)
{
	double result = 0.;

	if (high - low < 3) //С�ڵ���3����ʱ
	{
		if (high - low == 1) //2����ʱ
		{
			double distance = Distance(arr[low], arr[high]);
			return distance;
		}
		else //3����
		{
			double distance1 = Distance(arr[low], arr[low + 1]);
			double distance2 = Distance(arr[low], arr[low + 2]);
			double distance3 = Distance(arr[low + 1], arr[low + 2]);
			return min(min(distance1, distance2), distance3);
		}
	}
	int middle = (low + high) / 2;
	double left_distance = GetShortestDistace(arr, low, middle);		//��middle��ߵ���̾���
	double right_distance = GetShortestDistace(arr, middle + 1, high);	//��middle�ұߵ���̾���

	double delta = min(left_distance, right_distance); //�м�����Ľ���
	result = delta;
	vector<Point> midArea;	//����м���������ĵ�
	for (int k = low; k < high; k++)
	{
		if(arr[k].x > arr[middle].x - delta && arr[k].x < arr[middle].x + delta)
			midArea.push_back(arr[k]);
	}
	sort(midArea.begin(), midArea.end(), CmpY()); //��Y��������
	int size = midArea.size();
	for (int i = 0; i < size; i++)
	{
		int k = (i + 7) > size ? size : (i+7);	//ֻ��ѡȡ��7����(֤������û����)
		for (int j = i+1; j < k; j++)
		{
			if(Distance(midArea.at(i), midArea.at(j)) < result)
				result = Distance(midArea.at(i), midArea.at(j));
		}
	}
	return result;
}

#define N 100 //��ĸ���
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