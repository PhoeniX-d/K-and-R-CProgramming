#include<stdio.h>
#include<string.h>

/* toggle: toggles case of input character if alphabet */
char toggle(char c)
{
	if( c >= 'A' && c <= 'Z' )
		return c + 32;
	else if( c >= 'a' && c <= 'z' )
		return c - 32;
	return c;
}

int main(int argc,char** argv)
{
	int c = 0;
	if(strcmp(argv[0],"toggle") == 0)
	{
		while((c = getchar()) != EOF)
		{
			putchar(toggle(c));
		}
	}
	return 0;
}