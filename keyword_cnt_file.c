#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<fcntl.h>

#define NKEY	(sizeof keytab / sizeof(keytab[0]))
#define MAXWORD 	25
#define BLOCKSIZE   1024

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

void strcpy_sp(char*,char**,int*);

int  bsearchX(char*,KEY*,int);

int main(int argc , char **argv)
{	
	if(argc != 2)
	{
		printf("Enter File name ,it is must\n");
		return 1;
	}
	
	int fd = 0,iRet = 0,n = 0, i = 0;
	char *fbuff = (char*)malloc(sizeof(char)*BLOCKSIZE);
	char *word = (char*)malloc(sizeof(char)*MAXWORD);

	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
		printf("Unable to open a file %s\n",argv[1]);
	
	while((iRet = read(fd,fbuff,BLOCKSIZE)) > 0)
	{			
		while(iRet > 0)
		{
			strcpy_sp(word,&fbuff,&iRet);
			if((i = strlen(word)) >= 2 && i <= 8 )
			{
				if((n = bsearchX(word,keytab,NKEY)) >= 0)
				{
					keytab[n].count++;
				}
			}				
		}		
	}
	printf("Keywords Used In This File are\n\n");
	printf("   Keywords\t\t  count\n");
	for(n = 0; n < NKEY ; n++)
	{
		if(keytab[n].count > 0)
		{
			printf("%10s\t\t%5d\n", keytab[n].word,keytab[n].count);
		}
	}
	if(close(fd))
		return 0;
	else
		return 1;
}

void strcpy_sp(char w[],char **fb,int *n)
{	
	int j = 0;
	char c;
	memset(w,'\0',MAXWORD);
	
	while(*n > 0)
	{
		(*n)--;
		if(isalpha(c = (*((*fb)++))))
		{	
			w[j] = c;
			j++;
		}
		else
		{
			break;	
		}			
	}
	w[j] = '\0';
}
/*
* bsearch()		:binary search performed on keytab for finding word passed 
* input			:char*,struct key*,int
* output		:int
*/
int bsearchX(char *word, KEY* tab,int n)
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
