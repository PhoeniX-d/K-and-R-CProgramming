<<<<<<< HEAD
#include<stdio.h>
#define SIZE	10

void strncatX(char *src,char *dst,int ncp)
{ 
	while(*src != '\0')
		src++;

	while(*dst != '\0' && ncp > 0)
	{
		*src = *dst;
		src++;
		dst++;
		ncp--;
	}
	*src = '\0';
}
int main()
{
	int iRet = 0,cp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("Enter the number of char do you want to concate with s1 from s2\n");
	scanf("%d",&cp);

	strncatX(s1,s2,cp);
	printf("%s\n",s1);
	
	return 0;
=======
#include<stdio.h>
#define SIZE	10

void strncatX(char *src,char *dst,int ncp)
{ 
	while(*src != '\0')
		src++;

	while(*dst != '\0' && ncp > 0)
	{
		*src = *dst;
		src++;
		dst++;
		ncp--;
	}
	*src = '\0';
}
int main()
{
	int iRet = 0,cp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("Enter the number of char do you want to concate with s1 from s2\n");
	scanf("%d",&cp);

	strncatX(s1,s2,cp);
	printf("%s\n",s1);
	
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}