#include<stdio.h>

#define MAXLEN	  5
#define MAXCHAR	128

typedef int BOOL;
void expand(char s[],char d[]);

int main()
{
	char src[MAXLEN];
	char dest[MAXCHAR];
	printf("Enter the expression\n");
	scanf("%[^'\n']s",src);
	expand(src,dest);
	printf("%s\t%s",src,dest);

	return 0;
}

void expand(char s[],char d[])
{
	int i=0,j=0;
	char c;
	while((c=s[i++])!='\0')
	{
		if(s[i] == '-' && s[i+1] >= c)
		{
			i++;
			while(c < s[i])
			{
				d[j++] = c++;
			}
		}
		else
			d[j++]=c;/*last element will be copied here*/
	}
	d[j]='\0';
}