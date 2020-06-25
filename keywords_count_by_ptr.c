#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define NKEY		(sizeof keytab / sizeof(keytab[0]))
#define MAXWORD 	100
#define BUFFSIZE 	 10

typedef struct key
{
	char*	word;
	int		count;	
}KEY;

KEY keytab[] = { {"auto",0},{"break",0},{"case",0},{"char",0},{"const",0},{"continue",0},
			  {"default",0},{"define",0},{"do",0},{"double", 0},{"enum",0},{"float",0},{"for",0},
			  {"int",0},{"long",0},{"main",0},{"signed",0},{"struct",0},{"unsigned",0},
			  {"void",0},{"volatile",0},{"while",0}
			};

int  bufp = 0;
int  buf[BUFFSIZE];
int  getchX();
void ungetchX(int c);
int  getword(char*,int);
KEY* bsearchX(char*,KEY*,int);

int main()
{
	int i = 0;
	char word[MAXWORD];
	KEY* p;

	while(getword(word,MAXWORD) != EOF)
	{
		if(isalpha(word[0]))
		{
			if((i = strlen(word)) >=2 && i <= 8)
			if((p = bsearchX(word, keytab, NKEY)) != NULL)
			{
				p->count++;
			}
		}
	}
	printf("Current file %s\n",__FILE__ );
	printf("Current date %s\n",__DATE__ );
	printf("Current time %s\n",__TIME__ );
	printf("Current line %d\n",__LINE__ );
	for(p = keytab ; p < keytab + NKEY; p++)
	{
		if(p->count > 0)
		{
			printf("%4d %s\n",p->count ,p->word);
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
KEY* bsearchX(char *word,KEY* tab,int n)
{
	KEY *beg = &tab[0] , *end = &tab[n] ,*mid = NULL;
	int condition;
	
	while(beg < end)
	{
		mid = beg + (end - beg)/2;
		if((condition = strcmp(word,mid->word)) < 0)
		{
			end = mid;
		}
		else if(condition > 0)
		{
			beg = mid + 1;
		}
		else
			return mid;
	}
	return NULL;
}
/*
* getword()		:get next word or character from input format it properly 
* input			:char*,int
* output		:int
*/
int getword(char *word,int lim)
{
	int c;
	char *w = word;
	
	while(isspace(c = getchX()))
		;
	if(c != EOF)
	{
		*w++ = c;
	}
	if(!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for(;--lim > 0 ;w++)
	{
		if(!isalnum(*w = getchX()))
		{
			ungetchX(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
