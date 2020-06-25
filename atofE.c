#include<stdio.h>

int isdigitX(char c)
{
	return c >= '0' && c <= '9';
}

double atofe(char s[])
{
	double val = 0.0,power = 0.0;
	int sign = 0 ,i = 0,exp = 0;

	while(s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		;
	sign = (s[i] == '-')? -1 : 1 ;
	if(s[i] == '+' || s[i] == '-')
		i++;
	
	for(val = 0.0;isdigitX(s[i]);i++)
	{
		val = val * 10.0 + (s[i] - '0');
	}	

	if(s[i] == '.')
		i++;

	for(power = 1.0 ;isdigitX(s[i]);i++)
	{
		val = val * 10.0 + (s[i] - '0');
		power = power *10;
	}
	val = (val/power)*sign;

	if(s[i] == 'e' || s[i] == 'E')
	{
		sign = s[++i] == '-'? -1 : 1;
		if(s[i] == '-' || s[i] == '+')
			i++;
		for(exp = 0;isdigitX(s[i]); i++)
			exp = exp * 10 + (s[i] - '0');
		if(sign == -1)
		{
			while(exp-- > 0)
			{
				val = val / 10;
			}
		}
		else
		{
			while(exp-- > 0)
			{
				val = val * 10;
			}
		}
	}
	return val;
}

int main()
{
	char str[10];
	printf("Enter the string\n");
	scanf("%s",str);
	double d = atofe(str);
	printf("%lf",d);
	return 0;
}