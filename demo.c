#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<fcntl.h>

#define NKEY	(sizeof keytab / sizeof(keytab[0]))
#define MAXWORD 	100
#define BUFFSIZE 	 10
#define BLOCSIZE 	512

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
int  bufp = 0;
int  buf[BUFFSIZE];
int  getchX();
void ungetchX(int c);
int  getword(char*,char*,int);
int  bsearchX(char*,KEY*,int);


int main(int argc,char **argv)
{
	printf("Inside main\n");
	if(argc != 2)
	{
		printf("Its different I require a file\n");
		return 0;
	}
	int n ,fd = 0,iRet = 0,i = 0,lim = 0;

	char* fbuff = (char*)malloc(sizeof(char)*BLOCSIZE);
	char* word = (char*)malloc(sizeof(char)*MAXWORD);
	char* str = (char*)malloc(sizeof(char)*MAXWORD);

	fd = open(argv[1],O_RDONLY);
	printf("file opened with fd %d\n",fd);

	while((iRet = read(fd,fbuff,BLOCSIZE)) > 0)
	{
		printf("%d\n",iRet);
		while(iRet > 0)
		{
			sscanf(fbuff,"%s",word);
			i = strlen(word);
			/*if(i > 2)
			{
				if(isalpha(word[0]))
				{
					if((n = bsearchX(word,keytab,NKEY)) >= 0)
					{
						keytab[n].count++;
					}
				}			
			}*/
			fbuff = fbuff + i;
			iRet = iRet - i;		
		}
	}
	for(i = 0; i < NKEY ; i++)
	{
		if(keytab[i].count > 0)
		{
			printf("%4d %s\n",keytab[i].count , keytab[i].word);
		}
	}
	close(fd);
	return 0;
}

/*
* bsearch()		:binary search performed on keytab for finding word passed 
* input			:char*,struct key*,int
* output		:int
*/
int bsearchX(char *word,KEY* tab,int n)
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
