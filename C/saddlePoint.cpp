
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxRow 256
#define MaxCol 256

void  getInputData(int *rNum, int *cNum, double (*buf)[MaxCol])
{
	char line[100];

	int rowNum = 0;
	int icol = 0;
	int colNum = 0;

	while(true)
	{
		if (fgets (line, 100, stdin)==NULL)
			break;
	
		char* fliter = " ";
		char* token = strtok(line, fliter);

		while (token != NULL)
		{
			float val = atof(token);
			

			buf[rowNum][icol++] = val;

			token = strtok(NULL, fliter);
		}
		++rowNum;

		colNum = icol;
		icol = 0;
	}

	*rNum = rowNum;
	*cNum = colNum;
}


int main()
{
    int rowNum=0, colNum=0;
	int rowIndex=0, colIndex=0, k = 0, l = 0;
	int minRow=0, maxColumn=0, isFound = 0;
    int tmpBuf = 0;
	int i=0,j=0;
	double data[MaxCol][MaxCol];

	getInputData(&rowNum, &colNum, data);
	
	
	int spaceNum = 0;
	int spaceFlag = 0;

     
	for(rowIndex=0; rowIndex < rowNum; rowIndex++)
    {
        for( colIndex = 0; colIndex < colNum; colIndex++)
        {
            minRow = data[rowIndex][colIndex];
            for( k = 0 ; k < colNum; k++)
            {
                if( minRow > data[rowIndex][k])
                    break;
            }

			//make sure a[i][j] is the smallest in row[i]
            if( k==colNum )
            {
                maxColumn = data[rowIndex][colIndex];
                for(l=0; l < rowNum; l++)
                {
                    if(maxColumn < data[l][colIndex])
                        break;
                }

				// make sure a[i][j] is the biggest in column[j]
                if( l == rowNum )
                {
                    printf("(%d,%d)\n",rowIndex , colIndex);
                    isFound = 1;
                }
            }
        }
    }

    if(isFound==0)
        printf("Not Found\n");
    
    return 0;
}