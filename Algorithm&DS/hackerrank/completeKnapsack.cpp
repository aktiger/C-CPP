#include <iostream>
#include <vector>
using namespace std;

/*
  desc:complete knapsack problem, each items can select zero or more times.
  auther: justinzhang(aktiger87@gmail.com)
  time:2015年2月15日10:14:02
  testcase#7:
  input:
  4
1 2000
1
2 10
5 9
2 2000
2 1
2 2000
1999 1999
=======
output:
2000
10
2000
1999

=====
input:
3
1 6
5
6 8
3 3 3 3 3 3
9 10
9 4 4 9 4 9 9 9 9

output:
5
6
9

*/

#define MAXLEN  5000


int main() {

  int T = 0;   // The number of test cases;
  
  int n = 0, k = 0;  // n is the number of integers, k is the volume of packages.
  
  int **array =new int* [MAXLEN];
  for(int i = 0; i< MAXLEN; i++) {
    array[i] = new int[MAXLEN];
  }
  


  int tmp = 0;

  cin>>T;
  
  for(int i = 0; i < T; i++) {
    vector<int> arrayN;  // arrayN should be in this for loop, if it is a global one, you should clear it each time.

    cin >> n; // the number of integers.
    cin >> k; // the volume of package.
    for(int j=0; j<n; j++) {

      cin >> tmp;
      arrayN.push_back(tmp);

    }

    
    // here we need to construct the logic of select zero or more times for each item.
    for(int j = 0; j < n; j++) {
      int maxSelectNum = k/arrayN[j];

      for(int select = 0; select < maxSelectNum; select++) {

	int item = arrayN[j];
	arrayN.push_back(item);
	
      }
      
    } // end of int j=0  , here we finish transition of complete knapsack problem to zeroone knapsack problem
    
    //    cout << "size of arrayN is :" << arrayN.size() << endl;

    for(int i=0; i<arrayN.size(); i++) {
      //                  cout << "arrayN:" << arrayN[i] << endl;
    }
    //cout << "end output arrayN" << endl;
    
    for(int vecIndex = 0; vecIndex <=arrayN.size(); vecIndex++) {
      for(int volIndex = 0; volIndex <=k ; volIndex++) {

	array[vecIndex][volIndex] = 0;

      }
    }


    
    
    for(int vecIndex = 1; vecIndex <= arrayN.size(); vecIndex++) {

      for(int volIndex = 1; volIndex <= k; volIndex++) {
	int v1 = 0;
	int v2 = 0;

	v1 = array[vecIndex-1][volIndex];

	if(volIndex - arrayN[vecIndex] >= 0 ) {  // here we use >=0 , not >0, >0 will be an error, =0 filled the package.
	  
	  v2 = array[vecIndex-1][volIndex-arrayN[vecIndex]] + arrayN[vecIndex];

	}

	if(v1 > v2 ) {

	  array[vecIndex][volIndex] = v1;

	} else {

	  array[vecIndex][volIndex] = v2;

	}

      } // end of for loop volIndex 
    } // end of for loop int vecIndex
    
    cout << array[arrayN.size()][k] << endl;
  } // end of loop for int T

  //释放动态申请的内存
  for(int i =0; i < MAXLEN; i++) {

    delete [] array[i];
  }

  delete[]array;

  return 0;
}
