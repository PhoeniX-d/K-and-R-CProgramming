#include<stdio.h>

int main()
{
	float fahr,celsius;
	int lower,upper,step;
	
	lower = 0;
	upper = 300;
	step = 20;
	celsius = 0;
	
	printf("Celsius\t\tFahrenheit\n");
	while(celsius <= upper )
	{	
		fahr = (celsius * (9.0/5.0)) +32;
		printf("%7.0f %18.1f\n",celsius,fahr);
		celsius = celsius + step;
	}
	return 0;
}
