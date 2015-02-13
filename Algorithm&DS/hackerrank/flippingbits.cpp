#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  
  int num; 
  cin >> num;
  int i = 0;
  vector<unsigned int> data;
  
  unsigned int tmp;
  

  for(i = 0; i<num; i++) {
    cin >> tmp;
    data.push_back(tmp);
  }
  
  for(i = 0; i < num; i++) {
    data[i] = data[i] ^ 0xffffffff;
  }
  
  for(i = 0; i < num; i++) {
    cout << data[i] << endl;
  }

  return 0;
}

