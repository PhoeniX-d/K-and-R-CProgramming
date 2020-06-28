#include<stdio.h>
#include<string.h>

/* tolowerX: converts input character to lower case */
char tolowerX(char c)
{
	return c >= 'A' && c <= 'Z' ? c + 32 :  c;
}

/* tolowerX: converts input character to upper case */
char toupperX(char c)
{
	return c >= 'a' && c <= 'z' ? c - 32 :  c;
}

int main(int argc,char** argv)
{
	int c = 0;
	if(strcmp(argv[0],"lower") == 0)
	{
		while((c = getchar()) != EOF)
		{
			putchar(tolowerX(c));
		}
	}
	else if(strcmp(argv[0],"upper") == 0)
	{
		while((c = getchar()) != EOF)
		{
			putchar(toupperX(c));
		}
	}
	return 0;
}