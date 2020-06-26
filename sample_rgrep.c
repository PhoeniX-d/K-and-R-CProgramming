<<<<<<< HEAD
#include<stdio.h>
#define MAXLINE 1000

int getlinex(char line[]);
int strrindex(char src[],char searchfor[]);
char pattern[] = "ould";
int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getlinex(line) >0)
	{
		if((found = strrindex(line,pattern)) >= 0)
		{
			printf("%d %s",found,line);
		}
	}
	return 0;
}

int getlinex(char line[])
{
	int i=0,c=0;
	while((c=getchar())!=EOF && c!='\n')
	{
		line[i++]=c;
	}
	if(c == '\n')
	{
		line[i++]=c;
	}
	line[i]='\0';
	return i;
}

int strrindex(char s[],char pattern[])
{
	int i=0,j=0,k=0,pos=-1;
	for(i=0;s[i]!='\0';i++)
	{
		//printf("i %d\n",i);
		for(j=i,k=0;pattern[k]!='\0' && s[j]==pattern[k];j++,k++);
		if(k > 0 && pattern[k]=='\0')
		{
			printf("i %d\n",i);
			pos = i;
		}
	}
	printf("i %d\n",pos);
	return pos;
=======
#include<stdio.h>
#define MAXLINE 1000

int getlinex(char line[]);
int strrindex(char src[],char searchfor[]);
char pattern[] = "ould";
int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getlinex(line) >0)
	{
		if((found = strrindex(line,pattern)) >= 0)
		{
			printf("%d %s",found,line);
		}
	}
	return 0;
}

int getlinex(char line[])
{
	int i=0,c=0;
	while((c=getchar())!=EOF && c!='\n')
	{
		line[i++]=c;
	}
	if(c == '\n')
	{
		line[i++]=c;
	}
	line[i]='\0';
	return i;
}

int strrindex(char s[],char pattern[])
{
	int i=0,j=0,k=0,pos=-1;
	for(i=0;s[i]!='\0';i++)
	{
		//printf("i %d\n",i);
		for(j=i,k=0;pattern[k]!='\0' && s[j]==pattern[k];j++,k++);
		if(k > 0 && pattern[k]=='\0')
		{
			printf("i %d\n",i);
			pos = i;
		}
	}
	printf("i %d\n",pos);
	return pos;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}