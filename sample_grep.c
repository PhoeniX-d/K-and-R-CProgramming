<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
#define MAXLINE 1000

int getlinex(char line[]);
int strindex(char src[],char searchfor[]);
char t[] = "ould";
int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getlinex(line) > 0)
	{
		if((found = strindex(line,t)) >= 0)
		{
			printf("%s",line);
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

int strindex(char s[],char t[])
{
	int i=0,j=0,k=0;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
		;
		if(k > 0 && t[k]=='\0')
		{
			return i;
		}
	}
	return -1;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
#define MAXLINE 1000

int getlinex(char line[]);
int strindex(char src[],char searchfor[]);
char t[] = "ould";
int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getlinex(line) > 0)
	{
		if((found = strindex(line,t)) >= 0)
		{
			printf("%s",line);
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

int strindex(char s[],char t[])
{
	int i=0,j=0,k=0;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
		;
		if(k > 0 && t[k]=='\0')
		{
			return i;
		}
	}
	return -1;
<<<<<<< HEAD
=======
#include<stdio.h>
#define MAXLINE 1000

int getlinex(char line[]);
int strindex(char src[],char searchfor[]);
char t[] = "ould";
int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getlinex(line) > 0)
	{
		if((found = strindex(line,t)) >= 0)
		{
			printf("%s",line);
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

int strindex(char s[],char t[])
{
	int i=0,j=0,k=0;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
		;
		if(k > 0 && t[k]=='\0')
		{
			return i;
		}
	}
	return -1;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}