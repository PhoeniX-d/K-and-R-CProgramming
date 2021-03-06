#include <stdio.h>
#define MAXLINE 100
#define LONGLINE 10

int getlinex(char line[]);
int main()
{

	int len = 0;
	char line[MAXLINE];

	while ((len = getlinex(line)) > 0)
	{
		if (len >= LONGLINE)
		{
			printf("%d ,%s", len, line);
		}
	}
	return 0;
}

int getlinex(char line[])
{
	int i = 0, c = 0;
	for (i = 0; (i < MAXLINE - 1) && (c = getchar()) != EOF && (c != '\n'); i++)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	printf("%d\n", i);
	return i;
}