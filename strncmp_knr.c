<<<<<<< HEAD
#include<stdio.h>
#define SIZE	10

int strncmpX(char *src,char *dst,int ncp)
{ 
	while(*src != '\0' && *dst != '\0' && ncp > 0)
	{
		if(*src != *dst)
			break;
		ncp--;
		src++;
		dst++;
	}
	if(*dst == '\0' || ncp == 0)
		return 0;
	else
		return (*src - *dst);
}
int main()
{
	int iRet = 0,cmp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("Enter the number of char do you want to concate with s1 from s2\n");
	scanf("%d",&cmp);

	printf("%d ",strncmpX(s1,s2,cmp));
	
	return 0;
=======
#include<stdio.h>
#define SIZE	10

int strncmpX(char *src,char *dst,int ncp)
{ 
	while(*src != '\0' && *dst != '\0' && ncp > 0)
	{
		if(*src != *dst)
			break;
		ncp--;
		src++;
		dst++;
	}
	if(*dst == '\0' || ncp == 0)
		return 0;
	else
		return (*src - *dst);
}
int main()
{
	int iRet = 0,cmp = 0;
	char s1[SIZE]={'\0'};
	char s2[SIZE]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("Enter the number of char do you want to concate with s1 from s2\n");
	scanf("%d",&cmp);

	printf("%d ",strncmpX(s1,s2,cmp));
	
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}