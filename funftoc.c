#include<stdio.h>


void FahrToCel(int low,int up,int step);
int main()
{
	float lower = 0,upper = 0, step = 0;
	printf("Enter lower limit\t");scanf("%f",&lower);
	printf("Enter upper limit\t");scanf("%f",&upper);
	printf("Enter step \t");scanf("%f",&step);

	FahrToCel(lower,upper,step);
	return 0;
}

void FahrToCel(int low,int up,int step)
{
	float fahr = low,cel = 0.0;
	for(fahr = low; fahr <= up; fahr = fahr + step)
	{
		cel = (5.0 / 9.0) * (fahr - 32);
		printf("%f\t%f\n",fahr,cel); 
	}
}