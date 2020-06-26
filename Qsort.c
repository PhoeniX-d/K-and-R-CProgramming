<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>
#define print(str) printf(#str)

void qsort(int a[],int l,int r);
int main()
{
	int arr[20],n = 0;
	print(Enter number of elements (<=20)\n);
	scanf("%d",&n);

	print(Enter elements\n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	print(Input array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");

	qsort(arr,0,n-1);

	print(Sorted Array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");
	return 0;
}

void qsort(int a[],int l,int r)
{
	int i,j,temp,pivot;
	if(l < r)
	{
		pivot = a[l];
		i = l;
		j = r;
		while(i < j)
		{
			while(a[i] <= pivot && i<r)
				i++;
			while(a[j] > pivot)
				j--;

			if(i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}


		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		qsort(a,l,j-1);
		qsort(a,j+1,r);
	}	
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>
#define print(str) printf(#str)

void qsort(int a[],int l,int r);
int main()
{
	int arr[20],n = 0;
	print(Enter number of elements (<=20)\n);
	scanf("%d",&n);

	print(Enter elements\n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	print(Input array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");

	qsort(arr,0,n-1);

	print(Sorted Array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");
	return 0;
}

void qsort(int a[],int l,int r)
{
	int i,j,temp,pivot;
	if(l < r)
	{
		pivot = a[l];
		i = l;
		j = r;
		while(i < j)
		{
			while(a[i] <= pivot && i<r)
				i++;
			while(a[j] > pivot)
				j--;

			if(i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}


		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		qsort(a,l,j-1);
		qsort(a,j+1,r);
	}	
<<<<<<< HEAD
=======
#include<stdio.h>
#define print(str) printf(#str)

void qsort(int a[],int l,int r);
int main()
{
	int arr[20],n = 0;
	print(Enter number of elements (<=20)\n);
	scanf("%d",&n);

	print(Enter elements\n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	print(Input array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");

	qsort(arr,0,n-1);

	print(Sorted Array\n);
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");
	return 0;
}

void qsort(int a[],int l,int r)
{
	int i,j,temp,pivot;
	if(l < r)
	{
		pivot = a[l];
		i = l;
		j = r;
		while(i < j)
		{
			while(a[i] <= pivot && i<r)
				i++;
			while(a[j] > pivot)
				j--;

			if(i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}


		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		qsort(a,l,j-1);
		qsort(a,j+1,r);
	}	
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}