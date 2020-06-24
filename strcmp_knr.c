#include<stdio.h>

//with pointer
int strcmpX(char *s,char *t)
{
	while(*s != '\0' && *t != '\0')
	{
		if(*s != *t)
		{
			break;
		}
		s++;t++;
	}
	return *s - *t;
}
// With array
/*int strcmpX(char s1[],char s2[])
{
	int i;
	for(i=0;s1[i] == s2[i];i++)
		if(s1[i] == '\0')
			return 0;
	return s1[i]-s2[i];
}*/

int main()
{
	char s1[10]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);

	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);

	printf("%d\n",strcmpX(s1,s2));

	return 0;
}