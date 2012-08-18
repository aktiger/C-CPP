#include <iostream>
using namespace std;


class TestA
{
      public:
             
      virtual void func1()
      {
              cout << "A in func1" << endl;
      }
      virtual void func2()
       {
              cout << "A in func2" << endl;
      }
};

class TestB: public TestA
{
     public:
       
       TestB()
      {
             func1();
      }
      
        void func1()
      {
              cout << "B in func1" << endl;
      };
       void func2(int a)
       {
              cout << "B in func2" << endl;
      };
      
};

int main()
{
    TestA a, *pa;
    TestB b;
    pa = &b;
    pa->func1();
    pa->func2();
    system("pause");
    return 0;
}
