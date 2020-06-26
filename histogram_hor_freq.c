<<<<<<< HEAD
#include<stdio.h>
#include<fcntl.h>

#define	MAXHIST		 15
#define MAXCHAR	128
#define BLOCKSIZE   256

int main()
{
	int cc[MAXCHAR],i = 0,len = 0,iRet = 0,maxvalue = 0;
	char arr[BLOCKSIZE],ch;
	for(i = 0;i < MAXCHAR;i++)
		cc[i] = 0;
	int fd = open("blank_replace.c",O_RDONLY);
	
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		for(i = 0;i < iRet;i++)
		{
			ch = arr[i];
			if(arr[i] < MAXCHAR)
				++cc[ch];
		}		
	}
	for(i = 1;i < MAXCHAR;i++)
	{
		if(maxvalue < cc[i])
		{
			maxvalue = cc[i];
		}	
	}
	for(i = 1;i < MAXCHAR; i++)
	{
		if(isprint(i))
			printf("%5d - %c - %5d",i,i,cc[i]);
		else
			printf("%5d - %5d",i,cc[i]);
		if(cc[i] > 0)
		{
			if((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	return 0;
=======
#include<stdio.h>
#include<fcntl.h>

#define	MAXHIST		 15
#define MAXCHAR	128
#define BLOCKSIZE   256

int main()
{
	int cc[MAXCHAR],i = 0,len = 0,iRet = 0,maxvalue = 0;
	char arr[BLOCKSIZE],ch;
	for(i = 0;i < MAXCHAR;i++)
		cc[i] = 0;
	int fd = open("blank_replace.c",O_RDONLY);
	
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		for(i = 0;i < iRet;i++)
		{
			ch = arr[i];
			if(arr[i] < MAXCHAR)
				++cc[ch];
		}		
	}
	for(i = 1;i < MAXCHAR;i++)
	{
		if(maxvalue < cc[i])
		{
			maxvalue = cc[i];
		}	
	}
	for(i = 1;i < MAXCHAR; i++)
	{
		if(isprint(i))
			printf("%5d - %c - %5d",i,i,cc[i]);
		else
			printf("%5d - %5d",i,cc[i]);
		if(cc[i] > 0)
		{
			if((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}