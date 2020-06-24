#include<stdio.h>
#define NOBLANK 'a'
int main()
{
	int c,lastc;
	lastc = NOBLANK;
	while( (c = getchar() ) != EOF)
	{
		if(c != ' ')
			putchar(c);
		if(c == ' ')
			if(lastc != ' ')
				putchar(c);	
		lastc = c;
	}
	return 0;	
}
