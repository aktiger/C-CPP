#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

/*
  author: justinzhang
  time:2015-2-15 16:18:52
  url: https://www.hackerrank.com/challenges/insertionsort2

*/


void display(int ar_size, int *ar) {

  for(int i = 0; i < ar_size; i++) {
    cout << ar[i] << " " ;
  }

  cout << endl;

}


void insertionSort(int ar_size, int *  ar) {
  int i=0, j=0;

  for(i=1; i < ar_size; i++) {

    int tmp = ar[i];
    for(j=i-1; j >= 0 ; j--) {



      if(tmp < ar[j]) {
	ar[j+1] = ar[j];
	
      } else {
	ar[j+1] = tmp;
	break;
      }

   

    } //end for j=i+1
    if( j < 0 ) {
      ar[j+1] = tmp;
    }
    
   display(ar_size, ar);

  } //end for i = 1

}

int main(void) {
   
  int _ar_size;
  cin >> _ar_size;
  //scanf("%d", &_ar_size);
  int _ar[_ar_size], _ar_i;
  for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
    cin >> _ar[_ar_i];
    //scanf("%d", &_ar[_ar_i]); 
  }

  insertionSort(_ar_size, _ar);
   
  return 0;
}

