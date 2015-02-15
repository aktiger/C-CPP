#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*

author: justinzhang
time:2015-2-15 16:19:33
url: https://www.hackerrank.com/challenges/insertionsort1

*/




void display(vector<int> ar) {
  int i = 0;

  for(i = 0; i < ar.size(); i++) {
    cout << ar[i] << " " ;
  }

  cout << endl;

}

void insertionSort(vector <int>  ar) {
  int i=0,j=0;
  int last = ar[ar.size()-1];
  for(i=ar.size()-2; i>=0; i--) {

    if(last < ar[i] ) {
      ar[i+1] = ar[i];
      display(ar);    

    } else {
      ar[i+1] = last;
      display(ar);    
      break;
    }


  }
  
  if(i<0) {
    ar[0] = last;
    display(ar);
  }
 

  


}
int main(void) {
  vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }

  insertionSort(_ar);
   
  return 0;
}
