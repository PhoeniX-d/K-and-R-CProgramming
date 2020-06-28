<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD			100 /*max word length*/
#define BUFFSIZE		 20 /*buffer size for unwanted characters*/

/* structure of linked list node to store line numbers that are dynmaic*/
typedef struct node		
{
	int 			lnum;	/*stores line num*/
	struct node		*ptr;	/*pointer to next node in linked list*/
}LNODE;						/*typedef to struct node*/

/*structure of tree note*/
typedef struct tnode
{
	char			*word;	/*pointer to text*/
	LNODE			*lines;	/*pointer to linked list structure*/
	struct tnode	*left;	/*ptr to left child*/
	struct tnode	*right;	/*ptr to right child*/
}TNODE;						/*typedef to struct tnode*/

int 	bufp = 0;
int 	buf[BUFFSIZE];

/* declaration of required functions */
int 	getchX();
void 	ungetchX(int);
TNODE 	*addtreex(TNODE*, char*, int);
TNODE 	*t_alloc();
LNODE 	*l_alloc();
int		getword(char*,int);
int 	noisyword(char*);
void 	treeprintx(TNODE*);
char*	strdupX(char*);
void 	addin(TNODE*,int);

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
int main(int argc, char const *argv[])
{
	TNODE*	root = NULL;
	char 	word[MAXWORD];
	int 	linenum = 1;

	while(getword(word,MAXWORD) != EOF )
	{
		if(isalpha(word[0]) && noisyword(word) == -1)
		{
			root = addtreex(root, word,linenum);
		}
		else if(word[0] == '\n')
		{
			linenum++;
		}
	}
	printf("\n       Words Line numbers\n");
	treeprintx(root);
	return 0;
}

/* adds a new node to tree */
TNODE *addtreex(TNODE *p, char *w, int linenum)
{
	int condition;

	if( p == NULL )
	{
		p = t_alloc();
		p->word = strdupX(w);
		p->lines = l_alloc();
		p->lines->lnum = linenum;
		p->lines->ptr = NULL;
		p->left = NULL;
		p->right = NULL;
	}
	else if((condition = strcmp(p->word,w)) == 0)
	{
		addin(p,linenum);
	}
	else if(condition < 0)
	{
		p->right = addtreex(p->right,w,linenum);
	}
	else
	{
		p->left = addtreex(p->left,w,linenum);
	}
	return p;
}

/*gets word from input and filters it*/
int getword(char *word,int limit)
{
	int c;
	char *w = word;

	while(isspace(c = getchX()) && c != '\n')
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

/* if word is already present then 
* adds line lumber to that words linked list */
void addin(TNODE *p,int linenum)
{
	LNODE *temp = p->lines;

	while((temp->ptr != NULL) && (temp->lnum != linenum))
	{
		temp = temp->ptr;
	}
	if(temp->lnum != linenum)
	{
		temp->ptr = l_alloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr = NULL;
	}
}

/* allocates memory for linked list node*/
LNODE *l_alloc()
{
	return (LNODE*)malloc(sizeof(LNODE));
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
void treeprintx(TNODE *p)
{
	LNODE *temp;
	if(p != NULL)
	{
		treeprintx(p->left);
		printf("%10s: ",p->word);

		for(temp = p->lines; temp != NULL; temp = temp->ptr)
		{
			printf("%4d ",temp->lnum);
		}
		printf("\n");
		treeprintx(p->right);
	}
}

/* to igonre my noisy words,if its among them then just ignore them */
int noisyword(char *w)
{
	static char *nw[] = {"a","an","and","are","in","is","of","or","that","the","this","to"};
	int condition, mid;
	int low = 0;
	int high = (sizeof(nw)) / sizeof(char*) - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if((condition = strcmp(w,nw[mid])) < 0)
			high = mid - 1;
		else if(condition > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD			100 /*max word length*/
#define BUFFSIZE		 20 /*buffer size for unwanted characters*/

/* structure of linked list node to store line numbers that are dynmaic*/
typedef struct node		
{
	int 			lnum;	/*stores line num*/
	struct node		*ptr;	/*pointer to next node in linked list*/
}LNODE;						/*typedef to struct node*/

/*structure of tree note*/
typedef struct tnode
{
	char			*word;	/*pointer to text*/
	LNODE			*lines;	/*pointer to linked list structure*/
	struct tnode	*left;	/*ptr to left child*/
	struct tnode	*right;	/*ptr to right child*/
}TNODE;						/*typedef to struct tnode*/

int 	bufp = 0;
int 	buf[BUFFSIZE];

/* declaration of required functions */
int 	getchX();
void 	ungetchX(int);
TNODE 	*addtreex(TNODE*, char*, int);
TNODE 	*t_alloc();
LNODE 	*l_alloc();
int		getword(char*,int);
int 	noisyword(char*);
void 	treeprintx(TNODE*);
char*	strdupX(char*);
void 	addin(TNODE*,int);

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
int main(int argc, char const *argv[])
{
	TNODE*	root = NULL;
	char 	word[MAXWORD];
	int 	linenum = 1;

	while(getword(word,MAXWORD) != EOF )
	{
		if(isalpha(word[0]) && noisyword(word) == -1)
		{
			root = addtreex(root, word,linenum);
		}
		else if(word[0] == '\n')
		{
			linenum++;
		}
	}
	printf("\n       Words Line numbers\n");
	treeprintx(root);
	return 0;
}

/* adds a new node to tree */
TNODE *addtreex(TNODE *p, char *w, int linenum)
{
	int condition;

	if( p == NULL )
	{
		p = t_alloc();
		p->word = strdupX(w);
		p->lines = l_alloc();
		p->lines->lnum = linenum;
		p->lines->ptr = NULL;
		p->left = NULL;
		p->right = NULL;
	}
	else if((condition = strcmp(p->word,w)) == 0)
	{
		addin(p,linenum);
	}
	else if(condition < 0)
	{
		p->right = addtreex(p->right,w,linenum);
	}
	else
	{
		p->left = addtreex(p->left,w,linenum);
	}
	return p;
}

/*gets word from input and filters it*/
int getword(char *word,int limit)
{
	int c;
	char *w = word;

	while(isspace(c = getchX()) && c != '\n')
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

/* if word is already present then 
* adds line lumber to that words linked list */
void addin(TNODE *p,int linenum)
{
	LNODE *temp = p->lines;

	while((temp->ptr != NULL) && (temp->lnum != linenum))
	{
		temp = temp->ptr;
	}
	if(temp->lnum != linenum)
	{
		temp->ptr = l_alloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr = NULL;
	}
}

/* allocates memory for linked list node*/
LNODE *l_alloc()
{
	return (LNODE*)malloc(sizeof(LNODE));
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
void treeprintx(TNODE *p)
{
	LNODE *temp;
	if(p != NULL)
	{
		treeprintx(p->left);
		printf("%10s: ",p->word);

		for(temp = p->lines; temp != NULL; temp = temp->ptr)
		{
			printf("%4d ",temp->lnum);
		}
		printf("\n");
		treeprintx(p->right);
	}
}

/* to igonre my noisy words,if its among them then just ignore them */
int noisyword(char *w)
{
	static char *nw[] = {"a","an","and","are","in","is","of","or","that","the","this","to"};
	int condition, mid;
	int low = 0;
	int high = (sizeof(nw)) / sizeof(char*) - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if((condition = strcmp(w,nw[mid])) < 0)
			high = mid - 1;
		else if(condition > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
>>>>>>> 52812cb4c72ad7ae5a3cca207fc12f57dd412b2a
}