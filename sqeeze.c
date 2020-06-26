<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>

void squeeze(char *s1,char *s2)
{
    int i = 0,j = 0,k = 0;

    while(s1[i] != '\0')
    {
        j = 0;
        while(s2[j] != '\0' && s2[j] != s1[i])
        {
            j++;
        }
        if(s2[j] == '\0')
        {
            s1[k++] = s1[i];
        }
        i++;
    }
    s1[k] = '\0';
}
int main()
{
    char str1[30],str2[30];

    printf("Enter string 1\n");
    scanf("%[^'\n']",str1);

    printf("Enter string 2\n");
    scanf(" ");
    scanf("%[^'\n']",str2);

    squeeze(str1,str2);
    printf("%s",str1);
    return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>

void squeeze(char *s1,char *s2)
{
    int i = 0,j = 0,k = 0;

    while(s1[i] != '\0')
    {
        j = 0;
        while(s2[j] != '\0' && s2[j] != s1[i])
        {
            j++;
        }
        if(s2[j] == '\0')
        {
            s1[k++] = s1[i];
        }
        i++;
    }
    s1[k] = '\0';
}
int main()
{
    char str1[30],str2[30];

    printf("Enter string 1\n");
    scanf("%[^'\n']",str1);

    printf("Enter string 2\n");
    scanf(" ");
    scanf("%[^'\n']",str2);

    squeeze(str1,str2);
    printf("%s",str1);
    return 0;
<<<<<<< HEAD
=======
#include<stdio.h>

void squeeze(char *s1,char *s2)
{
    int i = 0,j = 0,k = 0;

    while(s1[i] != '\0')
    {
        j = 0;
        while(s2[j] != '\0' && s2[j] != s1[i])
        {
            j++;
        }
        if(s2[j] == '\0')
        {
            s1[k++] = s1[i];
        }
        i++;
    }
    s1[k] = '\0';
}
int main()
{
    char str1[30],str2[30];

    printf("Enter string 1\n");
    scanf("%[^'\n']",str1);

    printf("Enter string 2\n");
    scanf(" ");
    scanf("%[^'\n']",str2);

    squeeze(str1,str2);
    printf("%s",str1);
    return 0;
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}