#include <iostream>
#include<string> 
using namespace std;
long ok(long num){
    long len(0),tmp(num);
    while(tmp){
               tmp/=10;
               len++;
    }
    tmp=0;
    for(long i=0;i!=len;++i){
            tmp+=num%10;
            num/=10;
    }
    return tmp;
}

int main(){
    string num;
    cin>>num;
    while(num!="0"){
               do{
                   string result;
                   int wd(0);
                   char a;
               
                   for(int i=0;i!=num.size();++i){
                          wd+=num[i]+1-'1';
                          if(wd>9){
                               a=wd/10+'1'-1;
                               result+=a;
                               a=wd%10+'1'-1;
                               result+=a;
                               wd=0;
                          }
                   }
                   if(wd>9){
                           a=wd/10+'1'-1;
                           result+=a;
                           a=wd%10+'1'-1;
                           result+=a;
                           wd=0;
                   }else
                           result+=wd+'1'-1;
                   num=result;
               }while(num.size()>1);        
               cout<<num<<endl;
               cin>>num;
    }
    return 0;
}
