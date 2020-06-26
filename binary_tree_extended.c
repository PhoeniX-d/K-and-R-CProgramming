#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
<<<<<<< HEAD
=======

>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
#define MAXWORD			100
#define BUFFSIZE		 20
#define YES				  1
#define NO				  0
typedef struct tnode
{
	char			*word;
	int				match;
	struct tnode	*left;
	struct tnode	*right;
}TNODE;

int 	bufp = 0;
int 	buf[BUFFSIZE];
int 	getchX();
void 	ungetchX(int);
int		compares(char*, TNODE*, int, int*);
TNODE 	*addtreex(TNODE*, char*, int, int*);
TNODE 	*t_alloc();
int		getword(char*,int);
int 	comment();
void 	treeprintx(TNODE*);
char*	strdupX(char*);

int main(int argc, char const *argv[])
{
	TNODE*	root = NULL;
	char 	word[MAXWORD];
	int found = NO;
	int num;

	if(--argc && (*++argv)[0] == '-')
	{
		num = atoi(argv[0] + 1);
	}
	else
	{
		num = 2;
	}
	
	while(getword(word,MAXWORD) != EOF )
	{
		if(isalpha(word[0]) && strlen(word) >= num)
		{
			root = addtreex(root, word, num, &found);
		}
		found = NO;
	}

	treeprintx(root);
	return 0;
}

TNODE *addtreex(TNODE *p, char *w, int num, int *found)
{
	int condition;

	if( p == NULL )
	{
		p = t_alloc();
		p->word = strdupX(w);
		p->match = *found;
		p->left = p->right = NULL;
	}
	else if((condition = compares(w,p,num,found)) < 0)
	{
		p->left = addtreex(p->left,w,num,found);
	}
	else if(condition > 0)
	{
		p->right = addtreex(p->right,w,num,found);
	}
	return p;
}

int compares(char *s, TNODE *p, int num, int *found)
{
	int i = 0;
	char *t = p->word;

	while(*s == *t)
	{
		if(*s == '\0')
		{
			return 0;
		}
		t++;
		i++;
		s++;
	}
	if( i >= num)
	{
		*found = YES;
		p->match = YES;
	}
	return *s - *t;
}

int getword(char *word,int lim)
{
	int c,d;
	char *w = word;
	while(isspace(c = getchX()))
		;
	if(c != EOF)
	{
		*w++ = c;
	}
<<<<<<< HEAD
	if(isalpha(c) || c == '_' || c == '#')
	{
		for(;--lim > 0;w++)
		{
			if(!isalnum(*w = getchX()) && *w != '_')
			{
				ungetchX(*w);
				break;
			}
		}
	}
	else if(c == '\'' || c == '"')
	{
		for(;--lim > 0;w++)
		{
			if((*w = getchX()) == '\\')
			{
				*w++ = getchX();
			}
			else if(*w == c)
			{
				w++;
				break;
			}
			else if(*w == EOF)
			{
				break;
			}
		}
	}
	else if (c == '/')
	{
		if((d = getchX()) == '*')
		{
			c = comment();
		}
		else
		{
			ungetchX(d);
		}
	}
	*w = '\0';
	return c;
}


int comment()
{
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


=======
	if(!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	while(--lim > 0)
	{
		if(!isalnum(*w = getchX()))
		{
			ungetchX(*w);
			break;
		}
		w++;
	}
	*w = '\0';
	return word[0];
}

>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
TNODE *t_alloc()
{
	return (TNODE*)malloc(sizeof(TNODE));
}

char *strdupX(char *s)
{
	char *p = NULL;
	p = (char *)malloc(strlen(s) + 1);
	if(p != NULL)
	{
		strcpy(p,s);
	}
	return p;
}

void treeprintx(TNODE *p)
{
	if(p != NULL)
	{
		treeprintx(p->left);
		if(p->match == YES)
		{
			printf("%4d %15s\n",p->match, p->word);
		}
		treeprintx(p->right);
	}
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