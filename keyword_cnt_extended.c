#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define NKEY	(sizeof keytab / sizeof(keytab[0]))
#define MAXWORD 	100
#define BUFFSIZE 	 10

typedef struct key
{
	char*	word;
	int		count;	
}KEY;

KEY keytab[] = { {"auto",0},{"break",0},{"case",0},{"char",0},{"const",0},{"continue",0},
			  {"default",0},{"define",0},{"do",0},{"enum",0},{"float",0},{"for",0},
			  {"int",0},{"long",0},{"main",0},{"signed",0},{"struct",0},{"unsigned",0},
			  {"void",0},{"volatile",0},{"while",0}
			};
int bufp = 0;
int buf[BUFFSIZE];
int getchX();
void ungetchX(int c);
int getword(char*,int);
int bsearch(char*,KEY*,int);
int comment();

int main()
{
	printf("Inside main()\n");
	int n;
	char word[MAXWORD];
	while(getword(word,NKEY) != EOF)
	{
		if(isalpha(word[0]))
		{
			if((n = bsearch(word,keytab,NKEY)) >= 0)
			{
				keytab[n].count++;
			}
		}
	}
	for(n = 0; n < NKEY ; n++)
	{
		if(keytab[n].count > 0)
		{
			printf("%4d %s\n",keytab[n].count , keytab[n].word);
		}
	}
	return 0;
}

int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetchX(int c)
{
	if(bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}

/*
* bsearch()		:binary search performed on keytab for finding word passed 
* input			:char*,struct key*,int
* output		:int
*/
int bsearch(char *word,KEY* tab,int n)
{
	int beg = 0,end = n - 1,mid = 0,condition = 0;
	while(beg <= end)
	{
		mid = (beg + end)/2;
		if((condition = strcmp(word,tab[mid].word)) < 0)
		{
			end = mid - 1;
		}
		else if(condition > 0)
		{
			beg = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
/*
* getword()		:get next word or character from input format it properly 
* input			:char*,int
* output		:int
*/
int getword(char *word,int lim)
{
	int c,d;
	char *w = word;
	printf("%d\n",__LINE__);
	while(isspace(c = getchX()))
		;
	printf("%c\n",c);
	if(c != EOF)
	{
		*w++ = c;
		printf("here w++ %c\n",*w);
	}
	printf("%c\n",c);	
	if(isalpha(c) || c == '_' || c == '#')
	{
		printf("%d\n",__LINE__);
		for(;--lim > 0;w++)
		{
			if(!isalnum(*w = getchX()) && *w != '_')
			{
				printf("%d\n",__LINE__);
				ungetchX(*w);
				break;
			}
		}
	}
	else if(c == '\'' || c == '"')
	{
		printf("%d\n",__LINE__);
		for(;--lim > 0;w++)
		{
			if((*w = getchX()) == '\\')
			{
				printf("%d\n",__LINE__);
				*w++ = getchX();
			}
			else if(*w == c)
			{
				printf("%c\n",*w);
				printf("%c\n",c);
				printf("%d\n",__LINE__);
				w++;
				break;
			}
			else if(*w == EOF)
			{
				printf("%d\n",__LINE__);
				break;
			}
			printf("%d\n",__LINE__);
		}
	}
	else if (c == '/')
	{
		printf("%d\n",__LINE__);
		if((d = getchX()) == '*')
		{
			printf("%d\n",__LINE__);
			c = comment();
			printf("%c\n",c);
		}
		else
		{
			printf("%d\n",__LINE__);
			ungetchX(d);
		}
	}
	*w = '\0';
	return c;
}
int comment()
{
	printf("Inside comment())\n");
	int c;
	while((c = getchX()) != EOF)
	{
		if(c == '*')
		{
			if((c = getchX()) == '/')
				break;
			else
				ungetchX(c);
		}
	}
	return c;
}
