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


void print(int element) {
    std::cout << element << std::endl;
}

template <class T>
class  myprint
{
public:
    void operator() (T i) {
        std::cout << i << ",," ;
    }
};

template <class T>
void print_fun(T i) {
    std::cout << i << " " << std::endl;
}

template <class T>
class type_conversion_class {
 public:
  operator int() {return x - y;}
  type_conversion_class(int xx, int yy):x(xx), y(yy) {
   };
 private:
  T x;
  T y;
};


template <class T>
class mem_func_class {
  public:
  static std::vector<T> data;

  void  print(T element) {
          std::cout << element << " " << std::endl;
        }
  // void visit(){
  //   std::for_each(data.begin(), data.end(), std::bind1st(std::mem_fun(&mem_func_class<T>::print), this));
  //}

  mem_func_class() {
    std::cout << "in constructor:" << std::endl;
    data.push_back(9991);
    data.push_back(2999);
    data.push_back(4449);
  }
  
  ~mem_func_class(){
    std::cout << "in destructor" << std::endl;
  }
    
};

template <class T>
std::vector<T> mem_func_class<T>::data;



class no_template {
 public:
  static std::vector<int> data;
  no_template() {
    data.push_back(23);
    data.push_back(33);
  }
  
};

std::vector<int> no_template::data;

no_template obj_no_temp;

mem_func_class<int> obj_mem_fun_ref;// = mem_func_class<int>();

int main()
{
   std::cout << no_template::data.size() << " size " << std::endl;
   std::cout << (mem_func_class<int>::data).size() << " size " << std::endl;
   //   std::for_each(mem_func_class<int>::data.begin(), mem_func_class<int>::data.end(), myprint<int>());

  //    mem_func_class<int> obj_mem_fun_ref;// = mem_func_class<int>();
   std::cout << mem_func_class<int>::data.size() << " size " << std::endl;
   __gnu_cxx::hash_map<int, int> var;
    
    plus_<int>	plusobj;
    minus_<int>	minusobj;

    //using function operator, just like using common functions
    cout << plusobj(3,5) << endl;
    cout << minusobj(3,5) << endl;

    //using function operator's tmp object, and call it
    cout << plus<int>()(43,50) << endl;
    cout << minus<int>()(43, 50) << endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    myprint<int> obj;
    // std::transform(vec.begin(), vec.end(), vec.begin(), print<int>());
    std::for_each(vec.begin(), vec.end(), print_fun<int>);
    std::for_each(vec.begin(), vec.end(), myprint<int>());
    std::for_each(vec.begin(), vec.end(), obj);

    type_conversion_class<int> obj_t = type_conversion_class<int> (1,22);
    int ret = obj_t;
    std::cout << std::endl;
    std::cout << "ret=" << ret << std::endl;

    //obj_mem_fun_ref.visit();


    return 0;
}
