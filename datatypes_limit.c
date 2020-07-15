#include<stdio.h>
#include<limits.h>

int main()
{

    printf("signed char min = %10d\t%d\n",SCHAR_MIN, sizeof(signed char));
    printf("signed char max = %10d\t%d\n",SCHAR_MAX, sizeof(signed char));
    printf("signed short min = %10d\t%d\n",SHRT_MIN, sizeof(signed short));
    printf("signed short max = %10d\t%d\n",SHRT_MAX, sizeof(signed short));
    printf("signed int min = %10d\t%d\n",INT_MIN, sizeof(signed int));
    printf("signed int max = %10d\t%d\n",INT_MAX, sizeof(signed int));
    printf("signed long min = %10ld\t%d\n",LONG_MIN, sizeof(signed long));
    printf("signed long max = %10ld\t%d\n",LONG_MAX,sizeof(signed long));
    printf("unsigned char max = %10u\t%d\n",UCHAR_MAX, sizeof(unsigned char));
    printf("unsigned short max = %10u\t%d\n",USHRT_MAX, sizeof(unsigned short));
    printf("unsigned int max = %10u\t%d\n",UINT_MAX, sizeof(unsigned int));
    printf("unsigned long max = %10u\t%d\n",ULONG_MAX, sizeof(unsigned long));

    return 0;
}
