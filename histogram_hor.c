<<<<<<< HEAD
<<<<<<< HEAD
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
	for(i = 1;i < MAXWORD; i++)
	{
		printf("%5d - %5d",i,wl[i]);
		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
			printf("%d",len);
		}
		else
			len = 0;
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}
	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
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
	for(i = 1;i < MAXWORD; i++)
	{
		printf("%5d - %5d",i,wl[i]);
		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
			printf("%d",len);
		}
		else
			len = 0;
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}
	return 0;
<<<<<<< HEAD
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
	for(i = 1;i < MAXWORD; i++)
	{
		printf("%5d - %5d",i,wl[i]);
		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
			printf("%d",len);
		}
		else
			len = 0;
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}
	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}