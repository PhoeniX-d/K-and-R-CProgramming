<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD			100 /*max word length*/
#define BUFFSIZE		 20 /*buffer size for unwanted characters*/
#define NDISTINCT	   1000	/*mx distinct count*/ 

/*structure of tree note*/
typedef struct tnode
{
	char			*word;	/*pointer to text*/
	int				 count;	/*counts number of occurances of word*/
	struct tnode	*left;	/*ptr to left child*/
	struct tnode	*right;	/*ptr to right child*/
}TNODE;						/*typedef to struct tnode*/

TNODE *list[NDISTINCT];
int noftn = 0;
int 	bufp = 0;
int 	buf[BUFFSIZE];

/* declaration of required functions */
int 	getchX();
void 	ungetchX(int);
TNODE 	*addtree(TNODE*, char*);
TNODE 	*t_alloc();
int		getword(char*,int);
void 	treestore(TNODE*);
char*	strdupX(char*);
void 	sort_dec();

/* get (probably pushed back) character */
int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* put unwanted char back to buffer */
void ungetchX(int c)
{
	if(bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}

/* cross referencer entry point */
int main()
{
	TNODE*	root = NULL;
	char 	word[MAXWORD];
	
	while(getword(word,MAXWORD) != EOF )
	{
			root = addtree(root, word);
	}
	treestore(root);
	sort_dec();
	for(int i = 0; i < noftn; i++)
	{
		printf("%2d:%20s\n",list[i]->count,list[i]->word);
	}
	return 0;
}

/* adds a new node to tree */
TNODE *addtree(TNODE *p, char *w)
{
	int condition;

	if( p == NULL )
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
	else if(condition < 0)
	{
		p->right = addtree(p->right,w);
	}
	else
	{
		p->left = addtree(p->left,w);
	}
	return p;
}

/*gets word from input and filters it*/
int getword(char *word,int limit)
{
	int c;
	char *w = word;

	while(isspace(c = getchX()));
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

/* allocates memory for tree node*/
TNODE *t_alloc()
{
	return (TNODE*)malloc(sizeof(TNODE));
}

/*duplicates string*/
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
/* prints tree in-order */
void treestore(TNODE *p)
{
	if(p != NULL)
	{
		treestore(p->left);
		if(noftn < NDISTINCT)
		{
			list[noftn++] = p;
		}
		treestore(p->right);
	}
}

void sort_dec()
{
	int gap, i, j;
	TNODE *temp;

	for(gap = noftn/2; gap > 0; gap = gap/2)
	{
		for(i = gap; i < noftn ;i++)
		{
			for(j = i - gap; j >= 0 ;j = j-gap)
			{
				if(list[j]->count >= list[j + gap]->count)
				{
					break;
				}
				temp = list[j];
				list[j] = list[j + gap];
				list[j + gap] = temp;
			}
		}
	}
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD			100 /*max word length*/
#define BUFFSIZE		 20 /*buffer size for unwanted characters*/
#define NDISTINCT	   1000	/*mx distinct count*/ 

/*structure of tree note*/
typedef struct tnode
{
	char			*word;	/*pointer to text*/
	int				 count;	/*counts number of occurances of word*/
	struct tnode	*left;	/*ptr to left child*/
	struct tnode	*right;	/*ptr to right child*/
}TNODE;						/*typedef to struct tnode*/

TNODE *list[NDISTINCT];
int noftn = 0;
int 	bufp = 0;
int 	buf[BUFFSIZE];

/* declaration of required functions */
int 	getchX();
void 	ungetchX(int);
TNODE 	*addtree(TNODE*, char*);
TNODE 	*t_alloc();
int		getword(char*,int);
void 	treestore(TNODE*);
char*	strdupX(char*);
void 	sort_dec();

/* get (probably pushed back) character */
int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* put unwanted char back to buffer */
void ungetchX(int c)
{
	if(bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}

/* cross referencer entry point */
int main()
{
	TNODE*	root = NULL;
	char 	word[MAXWORD];
	
	while(getword(word,MAXWORD) != EOF )
	{
			root = addtree(root, word);
	}
	treestore(root);
	sort_dec();
	for(int i = 0; i < noftn; i++)
	{
		printf("%2d:%20s\n",list[i]->count,list[i]->word);
	}
	return 0;
}

/* adds a new node to tree */
TNODE *addtree(TNODE *p, char *w)
{
	int condition;

	if( p == NULL )
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
	else if(condition < 0)
	{
		p->right = addtree(p->right,w);
	}
	else
	{
		p->left = addtree(p->left,w);
	}
	return p;
}

/*gets word from input and filters it*/
int getword(char *word,int limit)
{
	int c;
	char *w = word;

	while(isspace(c = getchX()));
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

/* allocates memory for tree node*/
TNODE *t_alloc()
{
	return (TNODE*)malloc(sizeof(TNODE));
}

/*duplicates string*/
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
/* prints tree in-order */
void treestore(TNODE *p)
{
	if(p != NULL)
	{
		treestore(p->left);
		if(noftn < NDISTINCT)
		{
			list[noftn++] = p;
		}
		treestore(p->right);
	}
}

void sort_dec()
{
	int gap, i, j;
	TNODE *temp;

	for(gap = noftn/2; gap > 0; gap = gap/2)
	{
		for(i = gap; i < noftn ;i++)
		{
			for(j = i - gap; j >= 0 ;j = j-gap)
			{
				if(list[j]->count >= list[j + gap]->count)
				{
					break;
				}
				temp = list[j];
				list[j] = list[j + gap];
				list[j + gap] = temp;
			}
		}
	}
>>>>>>> 52812cb4c72ad7ae5a3cca207fc12f57dd412b2a
}