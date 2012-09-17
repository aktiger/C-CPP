/**
Author:	Justinzhang
Email:	uestczhangchao@gmail.cm
Time:	2012-9-17 15:49:36
Desc:	for the review of oppo written test;
		From this file we can learn that:
		1>Friend function can not be declared as virtual, but a virtual function can
		  be a friend function of another class;
		2>when declare a friend function or a friend class , you must pay attention
		  to the sequence of defination a friend function; when a function is a friend function
		  named fun_friend() of class CC, fun_friend() must be defined after CC
		  has been defined, cause only after CC has been defined that fun_friend is allowed to
		  access CC's members; when a functionx() is a class C1, C1 is a friend class of C2,
		  functionx() must be defined after C2 has been defined, cause only when C2 is defined
		  that C1's  functionx() is allowed to access C2's member;
		3>the virtual function is used in order to implement polymorphic, polymorphic is implemt 
		  during run time and is base inheritence, when there is no inheritence, polymorhpic is
		  no meaning, so do virtual function no use; As friend does not belong to its friend
		  class, so a friend function can't been virtual;
**/

#include <iostream>
using namespace std;


/* member function of a class can be declared and defined as inline function;
   we can use keyword inline at both declaration and defination;
   if we define a member funcion in class , by default it is an inline;
*/
class Point
{
     public:
      inline void Init(int initX, int initY);
     private:
        int x, y;
};
 inline void Point::Init(int initX, int initY)
{
     x=initX, y=initY;
}


 /**
	The following is the use of friend function;
	In class Y, friend_x1 can not be defined within class Y, because at this
	time, the full defination of class X is still unknown;
 **/
class X;
class Z;
class Y
{
	 friend Z;
 public:

	 Y()
	 {
		 this->y = -99;
	 }
	 //virtual function can be a friend function of another class.
	 //but friend function of a class can not be declared as virtual, the
	 //reason is simple, cause a friend function doesn't belong the class,
	 //it has no use even if it is declared as virtual;
	 virtual void friend_x1(X& objx);
	 void chargez(Z &z);	
	 int y;
};

 class X
{
public:
	X(){
		num = -33;
	}
	friend void Y::friend_x1(X& objx);// friend funciton declaration can not be virtual
	int num;
};

/* The following function must been defined after class X is defined, cause in class X
   ,there is a declaration that says:"friend_x1 is a friend function of class X;
*/
void Y::friend_x1(X& objx)
{
	objx.num = 79;
}

class Z
{
public:
	friend Y;
	int zz;
	Z()
	{
		this->zz = -121;
	}
	void changey(Y & y)
	{
		y.y = 123;
	}
};
/* the following function must be defined after class Z has been defined,
	because in class Z, there is a declaration that says:"class Y is a friend of Z;
	if the following function is defined before class Z if defined, there is not enouth
	information about class Y,that is the compiler does not konw class Y is a friend of Z;
*/
void Y::chargez(Z &z)
{
		 z.zz = 2323;
}

int main()
{
	X x;
	Y y;
	y.friend_x1(x);
	cout << "x.num" <<  x.num << endl;
	Z z;
	z.changey(y);
	cout << "y.y=" << y.y << endl;
	y.chargez(z);
	cout << "z.zz=" << z.zz << endl;

	return 0;
}