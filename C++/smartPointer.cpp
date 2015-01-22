#include <iostream>
#include <malloc.h>

/*

 desc:   A smart pointer to automatic alloc and dellocat memories.
 author: justinzhang(uestczhangchao@gmail.com).
 time: 2015-1-22 09:44:24

*/

template <class T>
class smartPtr {

public:
  smartPtr() {
    ptr = NULL;
    refCnt = (unsigned *) malloc(sizeof(unsigned));
  }

  smartPtr( T * pt) {


    this->ptr = pt;
    refCnt = (unsigned *) malloc(sizeof(unsigned));
    std::cout << "Enter constructor, refCnt is "<< *refCnt << std::endl;
    *refCnt = 1;
    
    std::cout << "Leave constructor, refCnt is " << *refCnt << std::endl;
    
  }

  smartPtr(smartPtr<T> &copy) {

   
    ptr = copy.ptr;
    
    refCnt = copy.refCnt;
    std::cout << "Enter copy constructor, refCnt is " << *refCnt << std::endl;
    
    ++*refCnt;
    
    std::cout << "Leave copy constructor, refCnt is "<< *refCnt << std::endl;

  }
  
  smartPtr<T> & operator=(smartPtr<T> &copy) {
    
    std::cout << "Enter operator=, refCnt is "<< *copy.refCnt << std::endl;
    
    if(this != &copy) {
      ptr = copy.ptr;
      refCnt = copy.refCnt;
      ++*refCnt;
    }
    std::cout << "Leave operator=, refCnt is " << *refCnt << std::endl;
    return *this;

  }
  
  ~smartPtr() {
  
    std::cout << "Enter destructor, refCnt is " << *refCnt << std::endl;

    --*refCnt;

    if(*refCnt == 0 ) {
      std::cout << "In destructor, refCnt is 0 , this pointer will be freed." << std::endl;
  
      if( NULL != ptr ) {

	delete ptr;
        ptr = NULL;

      }

      if(NULL != refCnt ) {
	free(refCnt);
	refCnt = NULL;
      }


    } else {

      std::cout << "Leave destructor, refCnt is " << *refCnt << std::endl;
    }

  }

  T getValue() {

    return *ptr;
  }

protected:
  T * ptr;
  unsigned *refCnt;

};


int main() {

  int * p = new int[2];

  smartPtr<int > intSmart(p) ; 
  smartPtr<int> copySmart(intSmart); // copy constructor will be called.
  smartPtr<int> operatorSmart = intSmart ; // Here the copy consturctor will be called, not the assignment operator.
  operatorSmart = intSmart; // Here the assignment operator will  be called.
  
  return 0;

}
