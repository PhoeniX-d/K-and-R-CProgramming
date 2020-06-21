#include<stdio.h>
#define MAXLEN      10
#define isspace(x)   x ==' ' || x =='\t' ? 1 : 0
#define isdigit(x)  x >='0' && x <='9' ? 1 : 0

double atof(char *s);
int main()
{
    char str[MAXLEN];
    printf("Enter the string containing float numbers\n");
    scanf("%s",str);
    double d = atof(str);
    printf("%lf",d);
    return 0;
}

double atof(char *s)
{
    double val,pow;
    int i,sign;

    for(i=0;isspace((*(s+i)));i++)
        ;
    sign = ((*(s+i)) == '-') ? -1 : 1;
    if((*(s+i)) == '-' || (*(s+i)) == '+')
        i++;
    for(val = 0.0;isdigit((*(s+i)));i++)
    {
        val = val * 10.0 + ((*(s+i)) - '0');
    }
    if((*(s+i)) == '.')
        i++;
    
    for(pow = 1.0;isdigit((*(s+i)));i++)
    {
         val = val * 10.0 + ((*(s+i)) - '0');
         pow = pow * 10.0; 
    }
    return (val / pow) * sign;
}