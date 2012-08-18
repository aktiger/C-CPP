/*
Author:JustinZhang
Time:2012��4��24��11:29:25
End: 2012��4��25��16:56:35
Email:uestczhangchao@gmail.com
Desc:ƽ������N���㣬�ҳ�N�����о�������������㣻�������ٷ�����ô�㷨�ĸ��ӶȽ��ﵽO(n^2)��
���㷨���÷��η������Խ����ӶȽ��͵�O(n*log(n));
*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

//delta=min{min(dest(S1), min(dest(S2}}.
double delta = INT_MAX;

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
//���������㷨
void insert_sort(vector<int>&A, int p, int r)
{
	int i,j;
	int key = 0;
	for (i=p+1; i<=r; i++)
	{
		key = A[i];
		j = i - 1;
		while (j>=p && A[j]>key)
		{
			A[j+1] = A[j];//��A[j]��ǰ�ƶ�
			j--;
		}
		A[j+1] = key;
	}
}

//��������������Ϊ��������
int partion(vector<int> &A,int p, int r)
{
	int count = p - 1;
	int key = A[r];

	for (int i=p; i<=r-1; i++)
	{
		if (A[i] < key)
		{
			count++;
			swap(A[count],A[i]);
		}
	}
	swap(A[count+1],A[r]);
	return count+1;
}

//�����㷨�����ϵ�˼�룬ȡ����λ������λ��
int get_median(vector<int>&data, int p, int r)
{
	int i=0, j=0;
	int n = r - p + 1;            //���ԭʼ�������ݸ���
	int remains = n%5;
	int int_count = n - remains;
	int int_group = int_count/5;
	int group_count = (n+4)/5;   //��������Ԫ��һ���������

	//int *group_median = new int[group_count];
	vector<int> group_median(group_count);

	if (p==r)
	{
		return data[p];
	}
	//���´���������Ԫ��Ϊһ�����λ��
	if (0 == remains) //���Ԫ�صĸ������ÿ��Է�Ϊ��5��Ԫ��Ϊ��λ��������
	{
		for (i=p; i<=r-4; i=i+5)
		{
			insert_sort(data, i, i+4);
			group_median[(i-p)/5] = data[p+2];
		}
	}
	else
	{
		for (i=p; i<=(r-remains-4);i=i+5)
		{
			insert_sort(data, i, i+4);
			group_median[(i-p)/5] = data[i+2];
		}
		//������5��Ԫ�ص��飬���鿪ʼ�����Ϊr-remains+1���������Ϊr
		insert_sort(data,r-remains+1,r);
		group_median[group_count-1] = data[r-remains+1+remains/2];
	}
	if (group_count==1)
	{
		return group_median[0];
	}
	else
	{
		return get_median(group_median,0,group_count-1);
	}
	return 0;
}

/*������Ϊget_position����д���ˣ����ºܾö�û���ܹ����ִ���Ҫ��ϸ��~~*/
int get_position(vector<int> &A, int p, int r, int key)
{
	for (int i=p; i<=r; i++)
	{
		if (A[i]==key)
		{
			return i;
		}
	}

	return -1;
}

//�ú�����Ϊ���ҵ�����A�У���seqС����
int select(vector<int> &A,int p, int r, int seq)
{
	//�������A����λ������λ����������Ϊ���������֧��
	int pivot_key = get_median(A, p, r);
	int pos = get_position(A,p,r,pivot_key);
	swap(A[pos],A[r]);
	int i = partion(A, p, r);
	int x = i - p + 1;
	if (seq == x)
	{
		return A[i];
	}
	else if (seq < x)
	{
		select(A, p, i-1, seq);
	}
	else
	{
		select(A, i+1, r, seq-x);
	}

}



class Point
{
public:
	int x;
	int y;
	Point(int x=0, int y=0)
	{
		this->x = x;
		this->y = y;
	}
	Point& operator=(const Point &p)
	{
		this->x = p.x;
		this->y = p.y;
		return *this;
	}
	Point(const Point &pp)
	{
		this->x = pp.x;
		this->y = pp.y;
	}
	friend ostream &operator<<(ostream &os, const Point & p)
	{
		os<<"("<<p.x<<"," << p.y << ")";
		
		return os;
	}

};
//�������㽻��
void swap_point(Point &p1, Point &p2)
{
	Point tmp = p1;
	p1 = p2;
	p2 = tmp;
}
//���ݵ����������һ���㣬���㼯�ϻ���Ϊ��������
int partion_Point_Set(vector<Point> &p,int l, int r)
{
	int count = -1;
	int key = p[r].x;
	for (unsigned i=0; i<=p.size()-2; i++)
	{
		if (p[i].x<key)
		{
			count++;
			swap_point(p[i],p[count]);
		}
	}
	swap_point(p[count+1],p[r]);
	return count+1;
}
//��������ľ���
double Distance(const Point &p1, const Point &p2)
{
	int x = (p1.x - p2.x);
	int y= (p1.y - p2.y);
	double distance = sqrt((double)(x*x+y*y));
	return distance;
}
//�ҵ�����������Сֵ
double min(double x, double y)
{
	if (x>y)
	{
		return y;
	}
	else
	{
		return x;
	}
		
}
//���յ��x�������������������е�λ��
int get_point_position_x(const vector<Point> &p, int l, int r, int x_key)
{
	for (int i=l; i<=r; i++)
	{
		if (p[i].x == x_key)
		{
			return i;
		}
	}
	return -1;
}
//���յ��y�������������������е�λ��
int get_point_position_y(const vector<Point> &p, int l, int r, int y_key)
{
	for (int i=l; i<=r; i++)
	{
		if (p[i].y == y_key)
		{
			return i;
		}
	}
	return -1;
}


//�ҵ�p��y�����order��ĵ�
Point select_point(vector<Point> &p,int l, int r, int order)
{
	vector<int> point_y; 
	for (int i=l; i<=r; i++)
	{
		point_y.push_back(p[i].y);
	}
	int key_y = select(point_y,0,point_y.size()-1,order);
	int position_y = get_point_position_y(p, 0, p.size()-1,key_y);
	return p[position_y];
}

double get_minimum_distance(vector<Point> &p,int l, int r,vector<Point> &result)
{

	int i=0,j=0;

   if ((r-l+1)==2)//�������Ϊ����
	{
		double ret = Distance(p[l],p[r]);

		if (ret < delta)
		{		
		result[0]=p[l];
		result[1]=p[r];
		}


		return ret;
	}
	else if ((r-l+1)==3) //�������Ϊ3��
	{
		double tmp_dis1 = Distance(p[l],p[l+1]);
		double tmp_dis2 = Distance(p[l],p[l+2]);
		double tmp_dis3 = Distance(p[l+1],p[l+2]);
		double ret = min(min(tmp_dis1,tmp_dis2),tmp_dis3);

	if (ret <delta )
	{
		
		if (tmp_dis1 == ret)
		{
			result[0] = p[l];
			result[1] = p[l+1];
		}
		else if (tmp_dis2==ret)
		{
			result[0]=p[l];
			result[1]=p[l+2];
		}
		else
		{
			result[0]= p[l+1];
			result[1]= p[l+2];
		}
	}
		return ret;
	}
	else //��������������
	{
		//����㼯p��x�����y����
		vector<int> Pointx;
		vector<int> Pointy;
		for (i=l; i<=r; i++)
		{
			Pointx.push_back(p[i].x);
			Pointy.push_back(p[i].y);
		}
		//�ҵ���x�������λ��
		int x_median = select(Pointx,0,Pointx.size()-1,(Pointx.size()+1)/2);
		int point_median_pos = get_point_position_x(p,l,r,x_median);
		swap_point(p[point_median_pos],p[r]);
		//�����ҵ�����λ���Ե㼯���л���
		int point_pivot_index = partion_Point_Set(p,l,r);
		//����x������Ϊ��λ�������㼯�ϻ��ֺú󣬵ݹ������λ����ߵ㼯S1���ұߵ㼯��S2������Сֵ��
		//������ν�������С�������㱣������
		double min_s1 = get_minimum_distance(p,l,point_pivot_index,result);
		double min_s2 = get_minimum_distance(p,point_pivot_index+1,r,result);
		if (min_s1>min_s2)
		{
			delta = min_s2;
		}
		else
		{
			//result[0] = tmp_result1;
			//result[1] = tmp_result2;
			delta = min_s1;
		}
		//�����Ѿ��ݹ������S1��S2�е㼯����̾��룬���濪ʼ��S1��S2֮���֮��ľ���
		//�ҳ��㼯��S2�У�y����ǰ����ĵ�,���|S2|<6����ֻ���ҳ�|S2|����
		int size_s2 = (r-point_pivot_index<6)?r-point_pivot_index:6;
		vector<Point> S2;
		Point tmp;
		for (i=1;i<=size_s2;i++)
		{
			tmp = select_point(p,point_pivot_index+1,r,i);
			S2.push_back(tmp);
		}

		for (i=l; i<=point_pivot_index; i++)
		{
			for (j=0; j<size_s2; j++)
			{
				double d = Distance(p[i],S2[j]);
				if (d < delta)
				{
					result[0]= p[i];
					result[1]= S2[j];
					delta = d;
				}
			}
		}
				
		return delta;
	}
}

void getinput(vector<Point> &p)
{
	int i;
	Point pp;
	int Pointnumber = 0;
	cout << "please input Point numbers" <<endl;
	cin >> Pointnumber;
	for (i=0; i<Pointnumber; i++)
	{
		cin >> pp.x;
		cin >> pp.y;
		p.push_back(pp);
	}

}


int main()
{

	vector<Point> result(2);
	vector<Point> input;
	getinput(input);
	
	double minimum_distance = get_minimum_distance(input,0,input.size()-1,result);
	cout << "The nearest point is: "<<result[0] << " and " << result[1] << endl;
	cout << "their distance is : "<<minimum_distance << endl;

	return 0;
}