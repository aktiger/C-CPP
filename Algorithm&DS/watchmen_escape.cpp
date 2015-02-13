#include <cstdlib>
#include <iostream>

using namespace std;

long runDistance(long t) 
{
     return 17*t;
}

long min(long num1, long num2) {
    if(num1 < num2 ) {
        return num1;  
    } else {
        return num2;
    }
}

long fastMoveDistance(long t, long m) {
    long firstRunTime = min(t, m/10);
    long R = t - firstRunTime; 
    long distanceFirst = firstRunTime * 60 ;
    long distanceSecond = 0;
    long r1 = 0;
    long r2 = 0;
    for(r1 = 0; r1 <= t; r1++) {
        r2 = R - r1;
	long tmp =0;
	long recM = (m%10 + 4*r1)/10;
	tmp = min(r2, recM) * 60;
	if(tmp >= distanceSecond) {
            distanceSecond = tmp;
	}
    } 
    return distanceFirst + distanceSecond;
}


int main(int argc, char *argv[])
{   
    int T = 0; //岛沉没的时间 
    int M = 0; //魔法初始值 
    int S = 0; // 距离出口的距离
    
    cin >> T;
    cin >> M;
    cin >> S;
    
    cout << T << " " << M << " " << S << endl;
    long T1 = 0;
    long T2 = T - T1;
    long runDist = 0;
    long moveDist = 0;
    for(T1 = 0; T1 <= T; T1++) {
        T2 = T - T1;
	runDist = runDistance(T1);
	moveDist = fastMoveDistance(T2, M);
	if( runDist + moveDist >= S){
      	    cout << "succeed!!";
	    break;
	}
    }
    
    if(T1 > T ) {
        cout << "Failed";
    }
     
    system("PAUSE");
    return EXIT_SUCCESS;
}
