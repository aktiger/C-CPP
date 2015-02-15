#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int T = 0;
  cin >> T;
  vector<string> data;
  for(int i =0; i< T; i++) {
    string str;
    cin >> str;
    data.push_back(str);
  }
  int delStep = 0;
  for(int i=0; i< data.size(); i++){
    char ch = data[i][0];
    int k = 1;
    delStep = 0;

    for(int j =1; j<data[i].size(); j++) {
      if(ch == data[i][j]) {
	delStep = delStep + 1;

      } else {
	ch = data[i][j];
      }
    }

    cout << delStep << endl; 

  } 

  return 0;
}
