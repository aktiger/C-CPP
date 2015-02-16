/*
author: justin
time:2015-2-15 16:44:18
desc: [url] https://www.hackerrank.com/challenges/quicksort1


*/


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

void swap(vector<int> &data, int i, int j) {
  int v = data[i];
  data[i] =data[j];
  data[j] = v;

}

void partition(vector <int>  ar) {

  vector <int> copyvec(ar.begin(), ar.end());

  int v1 = ar[0];

  int i=ar.size() - 1, j=ar.size();

  for(i = ar.size() -1; i>=1; i--) {
    if(ar[i] > v1) {
      swap(ar, i, --j);
    }

  }
  --j;
  swap(ar,j,0);

  //  cout << "ar[j]=:" << ar[j] << endl;

  for(int k=1; k < copyvec.size(); k++) {

    if(copyvec[k] < v1) {
      cout << copyvec[k] << " ";
    }

  }

  cout << v1 << " " ;

  for( int k=1; k < copyvec.size(); k++) {

    if(copyvec[k] >= v1 ) {
      cout << copyvec[k] << " ";
    }

  }
  
  cout << endl;
  

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

  partition(_ar);
   
  return 0;
}
