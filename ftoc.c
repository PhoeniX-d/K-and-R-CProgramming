#include<stdio.h>
int main()
{
float fahr,celcius;
int lower=0,upper=300,step=20;
fahr=lower;
printf("Fahrenheit\tCelcius\n");
while(fahr<=upper)
{
  celcius=5*(fahr-32)/9;
  printf("%5.0f\t%13.2f\n",fahr,celcius);
  fahr=fahr+step;
}
}
