#include<stdio.h>
#include<ctype.h>

int main()
{
	char a = 'A';
	char b = 'a';
	char c = '9';
	char d = '?';
	char e = '@';
	char f = '\t';
	char g = '\n';

	printf("%d\n",iscntrl(a));
	printf("%d\n",iscntrl(b));
	printf("%d\n",iscntrl(c));
	printf("%d\n",iscntrl(d));
	printf("%d\n",iscntrl(e));
	printf("%d\n",iscntrl(f));
	printf("%d\n",iscntrl(g));

	return 0;
}