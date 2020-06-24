#include<stdio.h>
int main()
{
    float fahr=0.0,celcius=0.0;
    int lower=0,upper=300,step=20;

    celcius=lower;
    while(celcius<=upper)
    {
        fahr=(9/5)*(celcius+32);
        printf("%5.0f\t%13.2f\n",celcius,fahr);
        celcius=celcius+step;
    }
    return 0;
}
