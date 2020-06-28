#include<stdio.h>
#include<stdarg.h>

/*minprintf : minimal printf with vaiable argument list */
void minprintf(char *fmt,...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap,fmt);/* make ap point to 1st unnamed arg */
	for(p = fmt; *p; p++)
	{
		if(*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for(sval = va_arg(ap, char*); *sval;sval++)
					putchar(*sval);
				break;
		}
	}
	va_end(ap);
}

int main()
{
	int i = 100;
	float f = 100.45446;
	char *s1 = "hello, world";
	minprintf(s1);
	return 0;
}