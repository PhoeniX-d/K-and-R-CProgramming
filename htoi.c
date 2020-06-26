<<<<<<< HEAD
/* converts given hex string to integer */
#include<stdio.h>

#define YES          1
#define NO           0
#define MAXSTR      20
#define NULL_STR    -1
#define NOT_HEX_STR -2
int htoi(char src[]);
int main()
{
    
    char str[MAXSTR];
    printf("Enter string with hex numbers\n");
    scanf("%s",str);
    printf("Input given\t%s\n",str);
    int iRet = htoi(str);
    if(iRet== NULL_STR)
    {
        printf("String entered is null!!\n");
    }
    else if(iRet == NOT_HEX_STR)
    {
        printf("Entered string doesn't contain hex numbers\n");
    }
    else if(iRet>-1)
        printf("Converted int\t%d",iRet);
    return 0;
}
int htoi(char src[])
{
    int hexdigit = 0,i=0,n,ishex;
    if(src == NULL)
    {
        return -1;
    }
    if(src[i] == '0')
    {
        i++;       
        if(src[i] == 'x' || src[i] == 'X')
        {
            i++;           
            ishex = YES;
            n=0;
        }     
    }
    while(ishex == YES)
    {
        if(src[i] >= '0' && src[i] <= '9')
        {
            hexdigit = src[i] - '0';           
        }
        else if(src[i] >= 'a' && src[i] <= 'f')
        {
            hexdigit = src[i] - 'a' + 10;
        }
        else if(src[i] >= 'A' && src[i] <= 'F')
        {
            hexdigit = src[i] - 'A' + 10;
        }
        else
        {
            ishex = NO;
        }
        if(ishex == YES)
        {
            n = 16 * n + hexdigit;
        }
        i++;
    }
    if(n > -1 && flag == 1)    
        return n;
    else
        return -2;
=======
/* converts given hex string to integer */
#include<stdio.h>

#define YES          1
#define NO           0
#define MAXSTR      20
#define NULL_STR    -1
#define NOT_HEX_STR -2
int htoi(char src[]);
int main()
{
    
    char str[MAXSTR];
    printf("Enter string with hex numbers\n");
    scanf("%s",str);
    printf("Input given\t%s\n",str);
    int iRet = htoi(str);
    if(iRet== NULL_STR)
    {
        printf("String entered is null!!\n");
    }
    else if(iRet == NOT_HEX_STR)
    {
        printf("Entered string doesn't contain hex numbers\n");
    }
    else if(iRet>-1)
        printf("Converted int\t%d",iRet);
    return 0;
}
int htoi(char src[])
{
    int hexdigit = 0,i=0,n,ishex;
    if(src == NULL)
    {
        return -1;
    }
    if(src[i] == '0')
    {
        i++;       
        if(src[i] == 'x' || src[i] == 'X')
        {
            i++;           
            ishex = YES;
            n=0;
        }     
    }
    while(ishex == YES)
    {
        if(src[i] >= '0' && src[i] <= '9')
        {
            hexdigit = src[i] - '0';           
        }
        else if(src[i] >= 'a' && src[i] <= 'f')
        {
            hexdigit = src[i] - 'a' + 10;
        }
        else if(src[i] >= 'A' && src[i] <= 'F')
        {
            hexdigit = src[i] - 'A' + 10;
        }
        else
        {
            ishex = NO;
        }
        if(ishex == YES)
        {
            n = 16 * n + hexdigit;
        }
        i++;
    }
    if(n > -1 && flag == 1)    
        return n;
    else
        return -2;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}