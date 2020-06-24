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
		printf("%d , %d ",len,line);
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

int getlinex(char line[])
{
	int i = 0,c = 0,j = 0;
	for(i = 0; (c = getchar()) !=EOF && (c != '\n'); i++)
	{
		if(i < (MAXLINE - 2))
		{
			line[j] = c;
			j++;
		}
	}
	if(c == '\n')
	{
		line[j] = c;
		i++;
		j++;
	}
	line[j] = '\0';
	return i;
}

void copy(char to[],char from[])
{
	int i = 0;
	while(from[i] != '\0')
	{
		to[i] = from[i];
		i++;
	}
}