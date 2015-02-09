#include <stdio.h>

/*

desc: scanf will return the count of successful read character, if it fails to read the desired input, the input buffer is never
      consumed, so the while loop will loop forever. so there should be a way to clear the input buffer after scanf failed to read
      the input buffer.

time:2015-2-9 09:50:59

author: justinzhang(uestczhangchao@gmail.com)

*/




int main() {

  int num;
 
  while(1 != scanf("%d", &num)) {

    puts("OK");

    //    fflush(stdin);  // plan A: it is not support by linux, so it will not flush the buffer.

    //    getchar(); // plan B: call getchar without parameter, will clear the input buffer, but only one character is consumed.

    char c;

    while((c=getchar()) != '\n' && (c != EOF) ) ; // plan c: perfectly solve the problem, consume all the characters in input buffer.

  }

  return 0;

}
