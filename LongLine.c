#include<stdio.h>
#define MAXLINE 	 100

int getlinex(char line[]);
void copy(char to[],char from[]);
int main()
{
	
	int len = 0,max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((len = getlinex(line)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(longest,line);
		}
	}
	if (max > 0)
		printf("%s",longest);
	return 0;
}

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
/*
getlinex(char line[])
{
	int i = 0,c = 0;
	for(i = 0;(i < MAXLINE - 1) && (c = getchar()) !=EOF && (c != '\n'); i++)
	{
		line[i] = c;
	}
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}*/

void copy(char *to,char *from)
{
	while(*from != '\0')
	{
		*to++ = *from++;
	}
	*to = '\0';
}