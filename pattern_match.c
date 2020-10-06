#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getlinex(char *line)
{
	int i = 0, c = 0;
	while (i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n')
	{
		*(line + i) = c;
		i++;
	}
	if (c == '\n')
	{
		*(line + i) = c;
		i++;
	}

	*(line + i) = '\0';
	return i;
}

int main(int argc, char **argv)
{
	char line[MAXLINE];

	if (argc != 2)
		printf("Usage Find Pattern\n");
	else
	{
		while ((getlinex(line)) > 0)
		{
			if ((strstr(line, argv[1])) != NULL)
			{
				printf("%s", line);
			}
		}
	}
	return 0;
}