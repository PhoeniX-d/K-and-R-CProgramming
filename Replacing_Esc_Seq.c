#include<stdio.h>
int main()
{
	int ch;
	while((ch = getchar()) != EOF)
	{
		if(ch == '\t')
			ch = "\\t";
		else if(ch == '\b')
			ch = "\\";
		else if(ch == '\\')
			ch = "\\";
		putchar(ch);
	}
	return 0;
}
