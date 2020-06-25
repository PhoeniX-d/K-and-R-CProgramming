#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD			100
#define BUFFSIZE		 20

typedef struct tnode
{
	char			*word;
	int				count;
	struct tnode	*left;
	struct tnode	*right;
}TNODE;

int 	bufp = 0;
int 	buf[BUFFSIZE];
int 	getchX();
void 	ungetchX(int c);
TNODE 	*addtree(TNODE*,char*);
char	*strdupX(char*);
TNODE 	*t_alloc();
int		getword(char*,int);
void 	treeprint(TNODE*);

int main()
{
	TNODE *root = NULL;
	char word[MAXWORD];

	while((getword(word,MAXWORD)) != EOF)
	{
		if(isalpha(word[0]))
		{
			root = addtree(root,word);
		}
	}
	treeprint(root);
	return 0;
}

int getword(char *word,int limit)
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

	while(--limit > 0)
	{
		if(!isalnum(*w = getchX()) && *w != '_')
		{
			ungetchX(*w);
			break;
		}
		w++;
	}
	*w = '\0';
	return word[0];
}

TNODE *addtree(TNODE *p,char *w)
{
	int condition;

	if(p == NULL)
	{
		p = t_alloc();
		p->word = strdupX(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if((condition = strcmp(p->word,w)) == 0)
	{
		p->count++;
	}
	else if(condition > 0)
	{
		p->left = addtree(p->left,w);
	}
	else
	{
		p->right = addtree(p->right,w);
	}
	return p;
}

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

void treeprint(TNODE *p)
{
	if(p != NULL)
	{
		treeprint(p->left);
		printf("%4d%15s\n",p->count, p->word);
		treeprint(p->right);
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