#include <iostream>
using namespace std;

int main()
{
    char a[101];
    char b[101];
    int fa[26]={0};
    int fb[26]={0};
    int i, j, len;
    
            cin >> a;
            cin >> b;
            len = strlen(a);
            for(i=0; i < len; i++)
            {
                 fa[a[i]-'A'] ++; 
                 fb[b[i]-'A'] ++;     
            }
            
            for(i=0; i<26; i++)
            {
                     for(j=0; j<26; j++)
                     {
                              if(fa[i] == fb[j])
                              {
                                       fb[j] = 0;
                                       break;
                              }
                     }
                     
                     if (j==26)
                     {
                               cout << "NO" << endl;
                               break;
                     }
            }
            if (i==26)
            cout << "YES" << endl;
            system("pause");
    
    
    return 0;
}

