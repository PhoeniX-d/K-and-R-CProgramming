#include <stdio.h>

int is_prime(int);
int main()
{
    int arr[20], n;
    int i;
    printf("Enter size of array:");
    scanf("%d", &n);
    printf("\nEnter elements if array:");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\narr[%d]={", n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("}\n");
    int *ptr = arr;

    printf("Prime number are=");
    for (i = 0; i < n; i++)
    {
        if (!is_prime(ptr[i]))
            printf("%d ", ptr[i]);
    }
    printf("\n");
    return 0;
}
int is_prime(int n)
{
    int i, flag = 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}