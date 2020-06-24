#include<stdio.h>
int main()
{
    int* arr = NULL;
    int n=0,el = 0;
    printf("Enter th nu,ber of elements\n");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elemnts\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d",&el);
    int iRet = binarysearch(arr,el);
    if(iRet == NOT_FOUND)
    {
        printf("Element no found\n");
        
    }
    return 0;
}