#include<stdio.h>
#include<ctype.h>
#define MAXLEN	4

typedef int BOOL;

int atoi(char s[]);
BOOL isdigitx(char ch);
BOOL isspcex(char ch);

int main()
{
	char arr[MAXLEN];
	printf("Enter the string containing number\n");
	scanf("%[^'\n']s",arr);
	int iRet = atoi(arr);
	if(iRet== -1)
		printf("out of range of integer");
	else
		printf("%d\n",iRet);
	return 0;
}

BOOL isdigitx(char ch)
{
	return (ch>='0' && ch<='9');

}
BOOL isspacex(char ch)
{
	return (ch == ' ' || ch == '\t');
}
int atoi(char s[])
{
	int i,n,sign = 1;
	for(i = 0;isspacex(s[i]);i++);
	if(s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if(s[i] == '+')
	{
		i++;
	}
	for(n=0;isdigitx(s[i]);i++)
	{
		n=10*n+(s[i]-'0');
	}
	return sign*n < sizeof(int) ? sign*n : -1;
}