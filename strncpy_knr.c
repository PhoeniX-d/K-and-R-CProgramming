<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
#define SIZE	20
int strlenX(char *s)
{
	int i = 0;
	while(*s++)
	{
		i++;
	}
	return i;
}

void strncpyX(char *src,char *dst,int ncp)
{
	int len = strlenX(src); 
	while(*src != '\0' && ncp != 0)
	{
		*dst++ = *src++;
		ncp--;
	}
	*dst = '\0';
}
int main()
{
	int iRet = 0,cp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE - 10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	/*
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	*/
	
	printf("Enter the number of char do you want to copy\n");
	scanf("%d",&cp);

	strncpyX(s1,s2,cp);
	printf("%s\n",s2);
	
	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
#define SIZE	20
int strlenX(char *s)
{
	int i = 0;
	while(*s++)
	{
		i++;
	}
	return i;
}

void strncpyX(char *src,char *dst,int ncp)
{
	int len = strlenX(src); 
	while(*src != '\0' && ncp != 0)
	{
		*dst++ = *src++;
		ncp--;
	}
	*dst = '\0';
}
int main()
{
	int iRet = 0,cp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE - 10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	/*
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	*/
	
	printf("Enter the number of char do you want to copy\n");
	scanf("%d",&cp);

	strncpyX(s1,s2,cp);
	printf("%s\n",s2);
	
	return 0;
<<<<<<< HEAD
=======
#include<stdio.h>
#define SIZE	20
int strlenX(char *s)
{
	int i = 0;
	while(*s++)
	{
		i++;
	}
	return i;
}

void strncpyX(char *src,char *dst,int ncp)
{
	int len = strlenX(src); 
	while(*src != '\0' && ncp != 0)
	{
		*dst++ = *src++;
		ncp--;
	}
	*dst = '\0';
}
int main()
{
	int iRet = 0,cp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE - 10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	/*
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	*/
	
	printf("Enter the number of char do you want to copy\n");
	scanf("%d",&cp);

	strncpyX(s1,s2,cp);
	printf("%s\n",s2);
	
	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}