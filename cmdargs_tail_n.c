#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN    100
#define MAXLINE   100
#define LINES     100
#define DEFLINES    2

void error(char *s)
{
	printf("%s\n",s);
	exit(1);
}
int getlinex(char *line)
{
	int i = 0,c = 0;

	while(i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n')
	{
		*(line+i) = c;
		i++;
	}
	if(c == '\n')
	{
		*(line+i) = c;
		i++;
	}
	*(line+i) = '\0';
	return i;
}
int main(int argc,char **argv)
{
	char *p = NULL, line[MAXLINE] ,*buf = NULL,*bufend = NULL, *lineptr[LINES];
	int len = 0 , nlines = 0 ,first = 0,i = 0,last = 0,n = 0;
	
	if(argc == 1)
		n = DEFLINES;
	else if(argc == 2 && (*++argv)[0] == '-')
		n = atoi(argv[0] + 1);
	else 
		error("usage : tail[-n]");
	if(n < 1 || n > LINES)
		n = LINES;
	for(i = 0;i < LINES; i++)
		lineptr[i] = NULL;
	if((p = buf = (char*)malloc(MAXLEN * LINES)) == NULL)
		error("tail:cannot allocate buf");

	bufend = buf + MAXLEN;

	while((len = getlinex(line)) > 0)
	{
		if(p + len +1 >= bufend)
			p = buf;
		lineptr[last] = p;
		strcpy(lineptr[last],line);
		if(++last >= LINES)
			last = 0;
		p = p + len + 1;
		nlines ++;
	}

	if(n > nlines)
		n = nlines;

	first = last - n;

	if(first < 0)
		first = first + LINES;

	for(i = first; n-- > 0;i = (i+1) % LINES)
		printf("%s", lineptr[i]);

	free(p);
	return 0;
}