#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD		100
#define BUFFSIZE	 20

struct tnode
{
	char	 		*word;
	int 			count;
	struct tnode*	left;
	struct tnode*	right;
}TNODE;