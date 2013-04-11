#include <iostream>
#include <ext/hash_map>
using namespace __gnu_cxx;
using namespace std;
template <class T>
struct plus_ {
  T operator() (const T& x, const T& y)
  {
    return x + y;
  }
};
template <class T>
struct minus_
{
  T operator() (const T& x, const T& y)
  {
    return x - y;
  }
};


int main()
{
  __gnu_cxx::hash_map<int, int> var;
  plus_<int>	plusobj;
  minus_<int>	minusobj;

  //using function operator, just like using common functions
  cout << plusobj(3,5) << endl;
  cout << minusobj(3,5) << endl;

  //using function operator's tmp object, and call it
  cout << plus<int>()(43,50) << endl;
  cout << minus<int>()(43, 50) << endl;
  
  return 0;
}
