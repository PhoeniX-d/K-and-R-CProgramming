#include<stdio.h>
#include<ctype.h>

#define MAXLINE		100	/*max number of chars per line */
#define OCTLEN		  6 /* length of an octal value */
int inc(int pos,int n);

/* print arbitary input in sensible way */
int main(int argc, char const *argv[])
{
	int c, pos;
	pos = 0;/* for position in line */
	while((c = getchar()) != EOF)
	{
		if(iscntrl(c) || c == ' ')
		{
			/* non graphic or blank */
			pos = inc(pos, OCTLEN);
			printf(" \\%03o(O) ", c);
			printf(" \\%05x(H) ", c);
			/* new line character */
			if(c == '\n')
			{
				pos = 0;
				putchar('\n');
			}
		}
		else
		{
			/* graphic character */
			pos = inc(pos, 1);
			putchar(c);
		}
	}
	return 0;
}

/* inc : increments position counter for output */
 int inc(int pos, int n)
 {
 	if(pos + n < MAXLINE)
 		return pos + n;
 	else
 	{
 		putchar('\n');
 		return n;
 	}
 }