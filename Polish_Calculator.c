#include<stdio.h>

#define BUFFSIZE 100
#define MAXOP 100
#define NUMBER  '0'
#define MAXVAL	100

char buf[BUFFSIZE];
int bufp = 0;
int sp = 0;
double stack[MAXVAL];

int getchX();
void ungetchX(int c);
int getopX(char *s);
void pushX(double);
double popX();
double atofX(char *s);
int isspaceX(char c);
int isdigitX(char c);
int main()
{
    int type;
    double op2;
    char s[MAXOP];
  
    while((type = getopX(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:pushX(atofX(s));
                        break;
            case '+':pushX(popX() + popX());
                     break;
            case '*':pushX(popX() * popX());
                     break;
            case '-':op2 = popX();
                    pushX(popX( - op2));
                    break;
            case '/':
            		op2 = popX();
                    if(op2 == 0.0)
                        printf("Err divide by zero\n");
                    else
                        pushX(popX() / op2);
                    break;
            case '\n':
            		 printf("%g\n",popX());
                     break;
            default:printf("Error:unknown command %s \n",s);
                    break;
        }
    }
    return 0;
}

void pushX(double d)
{
	
	if(sp  < MAXVAL)
	{
		stack[sp++] = d;
	}
	else
	{
		printf("Error Stack is full!!!\n");
	}
}

double popX()
{
	
	if(sp > 0)
	{
		return stack[--sp];
	}	
	else
	{
		printf("Cant pop No elements\n");
		return 0.0;
	}
}

double atofX(char *s)
{
	
    double val,pow;
    int i,sign;

    for(i=0;isspaceX(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '-' || s[i] == '+')
        i++;
    for(val = 0.0;isdigitX(s[i]);i++)
    {
        val = val * 10.0 + (s[i] - '0');
    }
    if(s[i] == '.')
        i++;
    
    for(pow = 1.0;isdigitX(s[i]);i++)
    {
         val = val * 10.0 + (s[i] - '0');
         pow = pow * 10.0; 
    }
    return (val / pow) * sign;
}

int isdigitX(char c)
{
    return c >= '0' && c <= '9';
}

int isspaceX(char c)
{
    return c == ' ' || c == '\t';
}
int getopX(char s[])
{
    
    int i = 0,c = 0 ;
    //printf("%c Inside case isdigit while 1\n",getchX());

    while((s[0] = c = getchX()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
   // printf("Hello\n");
    if(!isdigitX(c) && c != '.')
        return c;
    if(isdigitX(c))
    {
        while(isdigitX(s[++i] = c = getchX()));
    }
    if(c == '.')
        while(isdigitX(s[++i] = c = getchX()));

    s[i] = '\0';
    //printf("%s\n",s);
    if(c != EOF)
        ungetchX(c);
    return NUMBER;
}
int getchX()
{
   
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetchX(int c)
{
   
    if(bufp >= BUFFSIZE)
        printf("too many char\n");
    else
        buf[bufp++] = c;
}