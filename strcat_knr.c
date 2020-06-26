<<<<<<< HEAD
#include<stdio.h>
void strcatX(char *sc,char *dt)
{
	while(*sc != '\0')
	{
		sc++;
	}
	while(*dt !='\0')
	{
		*sc++ = *dt++;
	}
	*sc = *dt;
}
int main()
{
	char s1[20]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);

	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);

	strcatX(s1,s2);
	printf("%s\n",s1);

	return 0;
=======
#include<stdio.h>
void strcatX(char *sc,char *dt)
{
	while(*sc != '\0')
	{
		sc++;
	}
	while(*dt !='\0')
	{
		*sc++ = *dt++;
	}
	*sc = *dt;
}
int main()
{
	char s1[20]={'\0'};
	char s2[10]={'\0'};
	printf("Enter the string 1\n");
	scanf("%[^'\n']s",s1);

	printf("Enter the string 2\n");
	scanf(" ");
	scanf("%[^'\n']s",s2);

	strcatX(s1,s2);
	printf("%s\n",s1);

	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}