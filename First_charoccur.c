#include<stdio.h>

int foccurance(char *s1,char *s2)
{
    int i = 0,j = 0,pos = -1;

    while(s1[i] != '\0')
    {
        j = 0;
        while(s2[j] != '\0')
        {
            if(s2[j] == s1[i])
            {
                pos = i;
                break;
            }
            j++;
        }

        if(pos != -1)
            break;

        i++;
    }
    return pos;
}
int main()
{
    char str1[30],str2[30];

    printf("Enter string 1\n");
    scanf("%[^'\n']",str1);

    printf("Enter string 2\n");
    scanf(" ");
    scanf("%[^'\n']",str2);

    int iRet = foccurance(str1,str2);
    if(iRet == -1)
    {
        printf("No char from str2\n");
    }
    else
       printf("First matched char pos%d\n",iRet+1);
    return 0;
}