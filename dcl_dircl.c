#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

enum
{
	NAME,
	PARENS,
	BRACKETS
};
void dirdcl();
void dcl();
int gettoken();
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
void ungetchX(int c);
int getchX();

void dcl()
{
	int ns;
	for (ns = 0; gettoken() == '*';)
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetchX(int c)
{
	if (bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else
		buf[bufp++] = c;
}
void dirdcl()
{
	int type;
	if (tokentype == '{')
	{
		dcl();
		if (tokentype != '}')
			printf("Error : missing }\n");
	}
	else if (tokentype == NAME)
		strcpy(name, token);
	else
		printf("Error:Expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS)
	{
		if (type == PARENS)
			strcat(out, " function returning");
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
int main()
{
	while (gettoken() != EOF)
	{
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("Syntax Error\n");
		printf("%s : %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken()
{
	int c;
	char *p = token;

	while ((c = getchX()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		printf("is (\n");
		if ((c = getchX()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetchX(c);
			return tokentype = '{';
		}
	}
	else if (c == '[')
	{
		printf("is [\n");

		for (*p++ = c; (*p++ = getchX()) != ']';)
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)) /* is alphabet or not*/
	{
		printf("Alphabetical\n");
		for (*p++ = c; isalnum(c = getchX());) /* is alphanumeric or not*/
		{
			printf("is alphanumeric\n");
			*p++ = c;
		}

		*p = '\0';
		ungetchX(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}
