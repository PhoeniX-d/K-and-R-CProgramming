<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1

int main()
{
	char ch;
	int c = 0,nc = 0,nl = 0,nw = 0;
	int state = OUT;
	int fd = open("blank_replace.c",O_RDONLY);
	printf("%d",fd);
	while((c = read(fd,&ch,1) != 0))
	{
		nc++;
		if(ch == '\n')
			nl++;
		if(ch == ' ' || ch == '\n' || ch == '\t')
			state = OUT;
		else if(state == OUT)
		{	
			state = IN;
			nw++;
		}
	}
	printf("%d %d %d",nc,nw,nl);
	return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1

int main()
{
	char ch;
	int c = 0,nc = 0,nl = 0,nw = 0;
	int state = OUT;
	int fd = open("blank_replace.c",O_RDONLY);
	printf("%d",fd);
	while((c = read(fd,&ch,1) != 0))
	{
		nc++;
		if(ch == '\n')
			nl++;
		if(ch == ' ' || ch == '\n' || ch == '\t')
			state = OUT;
		else if(state == OUT)
		{	
			state = IN;
			nw++;
		}
	}
	printf("%d %d %d",nc,nw,nl);
	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}