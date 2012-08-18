#include <iostream>
using namespace std;
const int MAXN = 151;
const int M = 7;
int main()
{
         int n;
         char s[M];
         while(cin >> s >> n) {
                int a[M], b[MAXN], c[MAXN];
                memset(a, 0, sizeof(a));
                memset(b, 0, sizeof(b));

                int left = 0;
                while(s[left] == '0') left ++;
                int right = strlen(s)-1;
                while(s[right] == '0') right --;
                int cnt, digit;
                cnt = digit = 0;
                for(int i = right; i >=left; i--) {
                      if(s[i] == '.') digit = right - i;
                      else a[cnt++] = s[i] - '0';
                }
                for(int i = 0; i < cnt; i++) b[i] = a[i];
                for(int i = 1; i < n; i++) {
                      memset(c, 0, sizeof(c));
                      for(int j = 0; j < cnt; j++) {
                           for(int k = 0; k < i*cnt; k++) {
                                c[j+k] += a[j] * b[k];
                                c[j+k+1] += c[j+k]/10;
                                c[j+k] %= 10;
                           }
                      }
                      for(int l = 0; l < (i+1)*cnt; l++) b[l] = c[l];
                }
                int count = 0;
                char ans[MAXN];
                right = MAXN - 1;
                while(!b[right])  right--;
                if(right < n*digit) {
                      ans[count++] = '.';
                      right = n*digit - 1;
                }
                for(int i = right; i >= 0; i--) {
                      ans[count++] = b[i] + '0';
                      if(digit && (i == n*digit)) ans[count++] = '.';
                }
                ans[count++] = '\0';
                cout << ans << endl;
       }
       return(0);
}
