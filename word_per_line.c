<<<<<<< HEAD
#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1
#define BLOCKSIZE 1024
int main()
{
	char ch,arr[BLOCKSIZE];
	int state = OUT;
	int fd = open("wc.c",O_RDONLY);
	int iRet = 0;
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		printf("%d",iRet);
		for(int i = 0;i < iRet; i++)
		{
			if(arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t')
			{
				if(state == IN)
				{
					printf("\n");
					state = OUT;
				}
			}
			else if(state == OUT)
			{
				state = IN;
				printf("%c",arr[i]);
			}
			else
			{
				printf("%c",arr[i]);
			}
		}
	}
	return 0;
=======
#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1
#define BLOCKSIZE 1024
int main()
{
	char ch,arr[BLOCKSIZE];
	int state = OUT;
	int fd = open("wc.c",O_RDONLY);
	int iRet = 0;
	while(iRet = read(fd,arr,BLOCKSIZE))
	{
		printf("%d",iRet);
		for(int i = 0;i < iRet; i++)
		{
			if(arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t')
			{
				if(state == IN)
				{
					printf("\n");
					state = OUT;
				}
			}
			else if(state == OUT)
			{
				state = IN;
				printf("%c",arr[i]);
			}
			else
			{
				printf("%c",arr[i]);
			}
		}
	}
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}