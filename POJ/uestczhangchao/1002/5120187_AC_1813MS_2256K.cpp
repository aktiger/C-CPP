    #include <iostream>
    #include <cstdlib>
    using namespace std;
    
    #define ROW 100001    
    char format(const char &s);
    char RegularTel[ROW][20];
    int OccurTimes = 1;
    int compare(const void *a, const void *b);
    int main()
    {
        long int testnum;
           
        cin >> testnum;  //cin 过后有回车，所以应该用getchar()将回车接收 
        getchar();
        
               
        for (int i=0; i < testnum; i++)
        {
            char ch;
            int j=0;
            while(true)
            {
                scanf("%c", &ch);
                if (ch == '\n')
                break;
                if (ch == '-')
                continue;
                RegularTel[i][j] = ch;
                j++;
            }
            RegularTel[i][j] = '\0';
            
        }
        
     
        int kkk;
           
        for (int i=0; i < testnum; i++)
        {
            for (kkk=0; kkk < strlen(RegularTel[i]); kkk++)
            {

                 if (RegularTel[i][kkk] >= '0' && RegularTel[i][kkk] <= '9')
                 {
                    ;
                 }
                 else
                 {
                     RegularTel[i][kkk] = format(RegularTel[i][kkk]);
                 }
                                                      
            }
           
            RegularTel[i][kkk]='\0';
 
        }
     
       qsort(RegularTel, testnum, 20, compare);

       int tmp2;
       int flag=0;
       
      for (int i=0; i < testnum; i++)
      {
          tmp2 = i;
           
           if ((i+1) < testnum)
           {
            while (strcmp(RegularTel[i],RegularTel[i+1]) == 0 )
            {
                OccurTimes++;
                i++;
                if ( i >= testnum )
                break;
            }    
           }    
            if (OccurTimes >=2)
            {
            for (int ii=0; ii < 3; ii++)
            cout << RegularTel[tmp2][ii];
            cout << '-';
            for (int jj=3; jj < 7; jj++)
            cout << RegularTel[tmp2][jj];
            cout << " " << OccurTimes <<endl;
            flag=1;
            }    
            OccurTimes = 1;            
      }
      
      if (flag ==0)
      {
          cout << "No duplicates." <<endl;
      }
     
               return 0;
    }
   
    char format(const char &s)
    {
         char tmp;
         switch(s)
         {
          case 'A':
          case 'B':
          case 'C':tmp = '2';break;
          
          case 'D':
          case 'E':
          case 'F':tmp='3';break;
          
          case 'G':
          case 'H':
          case 'I':tmp='4';break;
               
          case 'J':
          case 'K':
          case 'L':tmp='5';break;
          
          case 'M':
          case 'N':
          case 'O':tmp='6';break;
          
          case 'P':
          case 'R':
          case 'S':tmp='7';break;
          
          case 'T':
          case 'U':
          case 'V':tmp='8';break;
          
          case 'W':
          case 'X':
          case 'Y':tmp='9';break;
                   
         }
         return tmp;             
         
    }
    
    int compare(const void *a, const void *b)
    {
 
       return strcmp((char *)a,(char *)b); 
    }




    



