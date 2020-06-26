<<<<<<< HEAD
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
=======
#include<stdio.h>
#define MAXLINE     100

int getlinex(char line[]);
void reverse(char line[]);

int main()
{
    char line[MAXLINE];
   // int len = 0;

    while(getlinex(line) > 0)
    {
        reverse(line);
        printf("%s",line);
    }
    return 0;
}

int getlinex(char line[])
{
    int i = 0,c = 0;
    for(i = 0;(i < (MAXLINE -1)) && ((c = getchar()) != EOF) && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char line[])
{
    printf("Inside Reverse\n");
    int i = 0,j = 0;
    char temp;

    while(line[i]!='\0')
        ++i;
    --i;
    if(line[i]=='\n')
        --i;
    while(j<i)
    {
        temp = line[j];
        line[j] = line[i];
        line[i] = temp;
        i--;
        j++;
    }
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}