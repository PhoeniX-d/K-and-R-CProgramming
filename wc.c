<<<<<<< HEAD

#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1

=======
#include<stdio.h>
#include<fcntl.h>
#define OUT 0
#define IN  1

>>>>>>> 6ba779bdab0cb49232fdcf6a89ee6ace7189fa7a
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 6ba779bdab0cb49232fdcf6a89ee6ace7189fa7a
