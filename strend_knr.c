<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
int strendX(char *src,char *dst)
{
	char *bsrc = src;
	char *bdst = dst;

	while(*src)
		src++;
	while(*dst)
		dst++;
	while(*src == *dst)
	{
		if(src == bsrc || dst == bdst)
			break;
		src--;dst--;
	}
	if(*src == *dst && dst == bdst && *src != '\0')
		return 1;
	else
		return 0;
}
int main()
{
	char s1[20]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("%d\n",strendX(s1,s2));

	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
int strendX(char *src,char *dst)
{
	char *bsrc = src;
	char *bdst = dst;

	while(*src)
		src++;
	while(*dst)
		dst++;
	while(*src == *dst)
	{
		if(src == bsrc || dst == bdst)
			break;
		src--;dst--;
	}
	if(*src == *dst && dst == bdst && *src != '\0')
		return 1;
	else
		return 0;
}
int main()
{
	char s1[20]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("%d\n",strendX(s1,s2));

	return 0;
<<<<<<< HEAD
=======
#include<stdio.h>
int strendX(char *src,char *dst)
{
	char *bsrc = src;
	char *bdst = dst;

	while(*src)
		src++;
	while(*dst)
		dst++;
	while(*src == *dst)
	{
		if(src == bsrc || dst == bdst)
			break;
		src--;dst--;
	}
	if(*src == *dst && dst == bdst && *src != '\0')
		return 1;
	else
		return 0;
}
int main()
{
	char s1[20]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);
	
	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);
	
	printf("%d\n",strendX(s1,s2));

	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}