<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES		1000
#define MAXLEN 			 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
int getlinex(char *);
void qsortX(char *a[],int left,int right);
void r_qsortX(char *a[],int left,int right);

int main(int argc ,char **argv)
{
	printf("Inside main()\n");
	int nlines;
	
	
	if((nlines = readlines(lineptr,MAXLINES)) >=0)
	{
		qsortX(lineptr,0,nlines - 1);
		writelines(lineptr,nlines);
		return 0;
	}
	else
	{
		printf("input too big\n");
		return 1;
	}
}

int getlinex(char *s)
{
	printf("Inside getlinex()\n");
	int c = 0,i = 0;
	 while(i < MAXLEN -1 && (c = getchar()) != EOF && c !='\n')
	 {
	 	*(s + i) = c;
	 	i++;
	 }
	 if(c == '\n')
	 {
	 	*(s + i) = c;
	 	i++;
	 }
	 *(s + i) = '\0';
	 return i;
}
int readlines(char *lineptr[],int maxlines)
{
	printf("Inside readlines()\n");
	int len,nlines;
	char *p = NULL;
	char line[MAXLEN];

	nlines = 0;
	while((len = getlinex(line)) > 0)
	{
		if(nlines >= maxlines || (p = (char*)malloc(len * sizeof(char))) == NULL)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *lineptr[],int maxlines)
{
	printf("Inside writelines()\n");
	for(int i = 0;i<maxlines;i++)
	{
		printf("%s\n",lineptr[i]);
	}
}

void qsortX(char *a[],int l,int r)
{
	printf("Inside qsortX()\n");

	int i,j;
	char *temp = NULL,*pivot = NULL;
	if(l < r)
	{
		pivot = a[l];

		i = l;
		j = r;
		while(i < j)
		{
			while(strcmp(a[i],pivot) < 0 && i<r)
				i++;
			while(strcmp(a[j],pivot) >= 0)
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

		qsortX(a,l,j-1);
		qsortX(a,j+1,r);
	}	
}

void r_qsortX(char *a[],int l,int r)
{
	printf("Inside r_qsortX()\n");

	int i,j;
	char *temp = NULL,*pivot = NULL;
	if(l < r)
	{
		pivot = a[l];

		i = l;
		j = r;
		while(i < j)
		{
			while(strcmp(a[i],pivot) < 0 && i<r)
				i++;
			while(strcmp(a[j],pivot) >= 0)
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

		r_qsortX(a,l,j-1);
		r_qsortX(a,j+1,r);
	}	
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES		1000
#define MAXLEN 			 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
int getlinex(char *);
void qsortX(char *a[],int left,int right);
void r_qsortX(char *a[],int left,int right);

int main(int argc ,char **argv)
{
	printf("Inside main()\n");
	int nlines;
	
	
	if((nlines = readlines(lineptr,MAXLINES)) >=0)
	{
		qsortX(lineptr,0,nlines - 1);
		writelines(lineptr,nlines);
		return 0;
	}
	else
	{
		printf("input too big\n");
		return 1;
	}
}

int getlinex(char *s)
{
	printf("Inside getlinex()\n");
	int c = 0,i = 0;
	 while(i < MAXLEN -1 && (c = getchar()) != EOF && c !='\n')
	 {
	 	*(s + i) = c;
	 	i++;
	 }
	 if(c == '\n')
	 {
	 	*(s + i) = c;
	 	i++;
	 }
	 *(s + i) = '\0';
	 return i;
}
int readlines(char *lineptr[],int maxlines)
{
	printf("Inside readlines()\n");
	int len,nlines;
	char *p = NULL;
	char line[MAXLEN];

	nlines = 0;
	while((len = getlinex(line)) > 0)
	{
		if(nlines >= maxlines || (p = (char*)malloc(len * sizeof(char))) == NULL)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *lineptr[],int maxlines)
{
	printf("Inside writelines()\n");
	for(int i = 0;i<maxlines;i++)
	{
		printf("%s\n",lineptr[i]);
	}
}

void qsortX(char *a[],int l,int r)
{
	printf("Inside qsortX()\n");

	int i,j;
	char *temp = NULL,*pivot = NULL;
	if(l < r)
	{
		pivot = a[l];

		i = l;
		j = r;
		while(i < j)
		{
			while(strcmp(a[i],pivot) < 0 && i<r)
				i++;
			while(strcmp(a[j],pivot) >= 0)
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

		qsortX(a,l,j-1);
		qsortX(a,j+1,r);
	}	
}

void r_qsortX(char *a[],int l,int r)
{
	printf("Inside r_qsortX()\n");

	int i,j;
	char *temp = NULL,*pivot = NULL;
	if(l < r)
	{
		pivot = a[l];

		i = l;
		j = r;
		while(i < j)
		{
			while(strcmp(a[i],pivot) < 0 && i<r)
				i++;
			while(strcmp(a[j],pivot) >= 0)
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

		r_qsortX(a,l,j-1);
		r_qsortX(a,j+1,r);
	}	
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}