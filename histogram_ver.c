<<<<<<< HEAD
#include<stdio.h>
#include<fcntl.h>

#define	MAXHIST		15
#define MAXWORD		11
#define IN 			 1
#define OUT			 0
#define BLOCKSIZE  256
int main()
{
	int wl[MAXWORD],i = 0,len = 0,state = OUT,iRet = 0,maxvalue = 0,overflow = 0,nc = 0;
	char arr[BLOCKSIZE];
	for(i = 0;i < MAXWORD;i++)
		wl[i] = 0;
	int fd = open("blank_replace.c",O_RDONLY);
	
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		for(i = 0;i < iRet;i++)
		{
			if(arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t')
			{
				state = OUT;
				if(nc > 0)
				{
					if(nc < MAXWORD)
						++wl[nc];
					else
						overflow++;
				}
				nc = 0;
			}
			else if(state == OUT)
			{
				state = IN;
				nc = 1;
			}
			else
			{
				nc++;
			}
		}		
	}
	for(i = 1;i < MAXWORD;i++)
	{
		if(maxvalue < wl[i])
		{
			maxvalue = wl[i];
		}	
	}
	for(i = MAXHIST ; i > 0 ; --i)
	{
		for(int j = 1 ; j< MAXWORD ;j++)
		{
			if(wl[j] * MAXHIST /maxvalue >= i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(i = 0;i < MAXWORD ; i++)
		printf("%4d",i);
	printf("\n");
	for(i = 0;i < MAXWORD ; i++)
		printf("%4d",wl[i]);
	printf("\n");	
	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}
	return 0;
=======
#include<stdio.h>
#include<fcntl.h>

#define	MAXHIST		15
#define MAXWORD		11
#define IN 			 1
#define OUT			 0
#define BLOCKSIZE  256
int main()
{
	int wl[MAXWORD],i = 0,len = 0,state = OUT,iRet = 0,maxvalue = 0,overflow = 0,nc = 0;
	char arr[BLOCKSIZE];
	for(i = 0;i < MAXWORD;i++)
		wl[i] = 0;
	int fd = open("blank_replace.c",O_RDONLY);
	
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		for(i = 0;i < iRet;i++)
		{
			if(arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t')
			{
				state = OUT;
				if(nc > 0)
				{
					if(nc < MAXWORD)
						++wl[nc];
					else
						overflow++;
				}
				nc = 0;
			}
			else if(state == OUT)
			{
				state = IN;
				nc = 1;
			}
			else
			{
				nc++;
			}
		}		
	}
	for(i = 1;i < MAXWORD;i++)
	{
		if(maxvalue < wl[i])
		{
			maxvalue = wl[i];
		}	
	}
	for(i = MAXHIST ; i > 0 ; --i)
	{
		for(int j = 1 ; j< MAXWORD ;j++)
		{
			if(wl[j] * MAXHIST /maxvalue >= i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(i = 0;i < MAXWORD ; i++)
		printf("%4d",i);
	printf("\n");
	for(i = 0;i < MAXWORD ; i++)
		printf("%4d",wl[i]);
	printf("\n");	
	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}