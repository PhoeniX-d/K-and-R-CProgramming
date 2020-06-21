#include<stdio.h>
#include<stdlib.h>
#define YES		1
#define NO 		0

typedef int BOOL;

void shellsort(int a[],int n)
{
	printf("Inside Shell Sort\n");
	int i=0,j=0,k=0,temp=0,gap=0;

	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0;j=j-gap)
			{
				if(a[j]>a[j+gap])
				{
					temp=a[j];
					a[j]=a[j+gap];
					a[j+gap]=temp;
				}
			}
		}
	}
}
int binarysearch(int a[],int item,int n)
{
	printf("Inside binry search\n");
	int beg=0,end=0,mid=0;
	beg=0;
	end = n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(item>a[mid])
			beg=mid+1;
		else if(item<a[mid])
			end=mid-1;
		else 
			return mid;
		
	}
	return -1;
}

int main()
{
	int *arr = NULL;
	int iRet=0,n=0,element=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&element);
	shellsort(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	iRet= binarysearch(arr,element,n);
	if(iRet==-1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element found at position %d\n",iRet+1);
	}
	return 0;
}
