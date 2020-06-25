#include<stdio.h>
#define MAXLEN	100
void unescape(char* src,char* dest)
{
	int i=0,j=0;
	for(i=0,j=0;src[i]!='\0';i++)
	{
		if(src[i]!='\t' && src[i]!='\n')
		{
			dest[j] = src[i];
			j++;
		}
		else
		{
			switch(src[i])
			{
				case '\n':dest[j++]='\\';
						  dest[j++]='n';
						  break;
				case '\t':dest[j++]='\\';
						  dest[j++]='t';
						  break;
				default: dest[j++]=src[i];
						break;
			}
		}
	}
	dest[j]='\0';
}
int main()
{
	char src[MAXLEN];
	char dest[MAXLEN];
	printf("Enter the string\n");
	scanf("%[^'\n']s",src);
	printf("%s\n",src);
	unescape(src,dest);
	printf("%s",dest);
	return 0;
}
