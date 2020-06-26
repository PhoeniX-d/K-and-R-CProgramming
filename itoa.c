<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
#define MAXLEN 		10
void itoa(int n,char s[]);
int main()
{
	int n=0;
	char str[MAXLEN];
	printf("Enter th number\n");
	scanf("%d",&n);
	itoa(n,str);
	printf("%d\t%s",n,str);
	return 0;
}
void itoa(int n,char s[])
{
	int i=0,sign=n;
	if(n<0)
	{
		n=-n;
	}
	while(n!=0)
	{
		s[i++] = (n % 10) + '0';
		n = n/10;
	}
	if(sign<0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
#define MAXLEN 		10
void itoa(int n,char s[]);
int main()
{
	int n=0;
	char str[MAXLEN];
	printf("Enter th number\n");
	scanf("%d",&n);
	itoa(n,str);
	printf("%d\t%s",n,str);
	return 0;
}
void itoa(int n,char s[])
{
	int i=0,sign=n;
	if(n<0)
	{
		n=-n;
	}
	while(n!=0)
	{
		s[i++] = (n % 10) + '0';
		n = n/10;
	}
	if(sign<0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
<<<<<<< HEAD
=======
#include<stdio.h>
#define MAXLEN 		10
void itoa(int n,char s[]);
int main()
{
	int n=0;
	char str[MAXLEN];
	printf("Enter th number\n");
	scanf("%d",&n);
	itoa(n,str);
	printf("%d\t%s",n,str);
	return 0;
}
void itoa(int n,char s[])
{
	int i=0,sign=n;
	if(n<0)
	{
		n=-n;
	}
	while(n!=0)
	{
		s[i++] = (n % 10) + '0';
		n = n/10;
	}
	if(sign<0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}