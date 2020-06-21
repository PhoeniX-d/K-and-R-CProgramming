#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getlinex(char* line)
{
	int i = 0,c = 0;
	while(i < MAXLINE-1 && (c = getchar()) !=EOF && c != '\n')
	{
		*(line+i) = c;
		i++;
	}
	if(c == '\n')
	{
		*(line+i)  = c;
		i++;
	}

	*(line+i) = '\0';
	return i;
}

int main(int argc,char** argv)
{
	char line[MAXLINE];
	long lineno = 0;
	int c,except = 0,number = 0,found = 0;

	while(--argc > 0 && *(*(++argv) + 0) == '-')
	{
		while(c == *++argv[0])
		{
			switch(c)
			{
				case 'x':
					except = 1;break;
				case 'n':
					number = 1;break;
				default:
					printf("find illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}
	if(argc != 1)
		printf("Usage Find -x -n Pattern\n");
	else
	{
		while((getlinex(line)) > 0)
		{
			lineno++;
			if(((strstr(line,*argv)) != NULL) != except)
			{
				if(number)
					printf("%ld",lineno);
				printf("%s\n",line);
				found++;
			}
		}
	}	
	return 0;
}