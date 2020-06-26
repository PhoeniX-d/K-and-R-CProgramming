<<<<<<< HEAD
#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int main()
{
    float fahr=0;
    for(fahr=UPPER;fahr>=LOWER;fahr=fahr-STEP)
        printf("%5.2f\t%5.2f\n",fahr,5.0/9.0*(fahr-32));
    return 0;
}
=======
#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int main()
{
    float fahr=0;
    for(fahr=UPPER;fahr>=LOWER;fahr=fahr-STEP)
        printf("%5.2f\t%5.2f\n",fahr,5.0/9.0*(fahr-32));
    return 0;
}
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
