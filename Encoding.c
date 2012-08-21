#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char letter[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char message[120][250];
	char temp[200];
	int count = 0;
	int i, j;
	scanf("%[^\n]", temp);
	fflush(stdin);
	while(strcmp(temp,"ENDOFINPUT") != 0)
	{

		if((strcmp(temp,"START")!=0)&&(strcmp(temp,"END")!=0) && (strcmp(temp,"ENDOFINPUT")!=0))
		{
			fflush(stdout);
			//printf("templen= %d\n",strlen(temp));



			for(i=0; i<strlen(temp); i++)
			{
				if (isalpha(temp[i]))
				{
					int pos = strchr(letter,toupper(temp[i]))-letter;
					char target = letter[(pos-5 +26)%26];
					temp[i] = target;
				}

			}

			memcpy(message[count++],temp,strlen(temp));
			message[count-1][strlen(temp)+1]='\0';
		//	printf(message[count-1]);
		//	printf("\n");

		}


		scanf("%[^\n]", temp);
		fflush(stdin);

	}

	for(j=0; j<count; j++)
	{
		printf(message[j]);
		printf("\n");
	}


	return 0;
}
