<<<<<<< HEAD
#include<stdio.h>

void qsort(int a[],int l,int r);
void r_qsort(int a[],int l,int r);

int main(int argc ,char **argv)
{
	int arr[20],n = 0;

	printf("Enter number of elements (<=20)\n");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Input array\n");
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");

	if(argc == 1)
	{
		qsort(arr,0,n-1);
	}
	
	else if(argc == 2 && argv[1][0] == '-')
	{
		if('r' == argv[1][1])
		{
			r_qsort(arr,0,n-1);
		}	
		else
		{
			printf("Usage :-r or nohting\n");
		}
	}
	
	printf("Sorted Array\n");
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
}
void r_qsort(int a[],int l,int r)
{
	printf("Inside Reverse sort\n");
	int i,j,temp,pivot;
	if(l < r)
	{
		pivot = a[l];
		i = l;
		j = r;
		while(i < j)
		{
			while(a[i] >= pivot && i<r)
				i++;
			while(a[j] < pivot)
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
		r_qsort(a,l,j-1);
		r_qsort(a,j+1,r);
	}	
=======
#include<stdio.h>

void qsort(int a[],int l,int r);
void r_qsort(int a[],int l,int r);

int main(int argc ,char **argv)
{
	int arr[20],n = 0;

	printf("Enter number of elements (<=20)\n");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Input array\n");
	printf("arr[%d] ={",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		if(i < n-1)
			printf(",");
	}
	printf("}\n");

	if(argc == 1)
	{
		qsort(arr,0,n-1);
	}
	
	else if(argc == 2 && argv[1][0] == '-')
	{
		if('r' == argv[1][1])
		{
			r_qsort(arr,0,n-1);
		}	
		else
		{
			printf("Usage :-r or nohting\n");
		}
	}
	
	printf("Sorted Array\n");
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
}
void r_qsort(int a[],int l,int r)
{
	printf("Inside Reverse sort\n");
	int i,j,temp,pivot;
	if(l < r)
	{
		pivot = a[l];
		i = l;
		j = r;
		while(i < j)
		{
			while(a[i] >= pivot && i<r)
				i++;
			while(a[j] < pivot)
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
		r_qsort(a,l,j-1);
		r_qsort(a,j+1,r);
	}	
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}