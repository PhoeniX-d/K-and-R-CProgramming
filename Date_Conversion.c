#include<stdio.h>

char daytab[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}	
};
/*
int day_of_year(int year,int month,int day)
{
	int i = 0, leap ;

	leap = (year % 4) == 0 && (year % 100) !=0 || (year % 400) == 0;
	
	if(month < 1 || month > 12)
		return -1;
	if(day < 1 || day > daytab[leap][month])
		return -1;
	
	for(i = 1;i < month;i++)
	{
		day = day + daytab[leap][i];
	}
	return day;
}
*/

int day_of_year(int year,int month,int day)
{
	int i = 0, leap ;
	char *p = NULL;
	leap = (year % 4) == 0 && (year % 100) !=0 || (year % 400) == 0;
	
	if(month < 1 || month > 12)
		return -1;
	if(day < 1 || day > daytab[leap][month])
		return -1;

	p = daytab[leap];

	while(--month)
	{
		day = day + *++p;
	}	
	return day;
}
void day_month(int year,int yearday,int* m,int* d)
{
	int i = 1,leap;
	char* p = NULL;
	leap = (year % 4) == 0 && (year % 100) !=0 || (year % 400) == 0;

	if(year < 0 || yearday < 1 || yearday > 366)
	{
		*m = -1;
		*d = -1;
		return;
	}	
	p = daytab[leap];

	while(yearday > *p)
	{
		yearday = yearday - *++p;
		++i;
	}
	if(i > 12 && yearday > *p)
	{
		*m = -1;
		*d = -1;
	}
	else
	{
		*m = i;
		*d = yearday;
	}
}
int main()
{
	int day,year,month,yearday,iRet;
	
	printf("Enter Day of the month\n");scanf("%d",&day);
	printf("Enter month\n");scanf("%d",&month);
	printf("Enter year\n");scanf("%d",&year);

	iRet = day_of_year(year,month,day);
	if(iRet == -1){
		printf("Wrong Input try again!!\n");
	}
	else
	{
		printf("Day %d is %d day of year %d\n",day,iRet,year);
	}	
	printf("Enter year\n");scanf("%d",&year);
	printf("Enter day of year\n");scanf("%d",&yearday);

	day_month(year,yearday,&month,&day);
	
	printf("Day %d of Year is %d Month's %d  day\n",yearday,month,day);

	
	return 0;
}