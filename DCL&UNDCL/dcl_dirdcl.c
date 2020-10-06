#include "paramdcl.c"

int nexttoken()
{
	int type;
	int prevtoken;
	type = gettoken();
	prevtoken = YES;
	return type;
}

/*
*errmsg() 	:print error msg and indicate available token
*input 		:char*
*output		:void
*/
void errmsg(char *msg)
{
	printf("%s\n", msg);
	prevtoken = YES;
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

/*
*dcl() 		:parses a declarator
*input 		:void
*output		:void
*/
void dcl()
{
	int ns;
	for (ns = 0; gettoken() == '*';) /* count *'s*/
		ns++;
	dirdcl();
	while (ns > 0)
	{
		strcat(out, " pointer to");
		ns--;
	}
}

/*
*dirdcl() 	:parses a direct declaration
*input 		:void
*output		:void
*/
void dirdcl()
{
	int type;
	if (tokentype == '(') /*(dcl)*/
	{
		dcl();
		if (tokentype != ')')
			errmsg("Error : missing )\n");
	}
	else if (tokentype == NAME) /*variab;e name*/
	{
		if (name[0] == '\0')
			strcpy(name, token);
	}
	else
	{
		prevtoken = YES;
	}

	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
	{
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == '(')
		{
			strcat(out, " function expecting");
			paramdcl();
			strcat(out, " and returning");
		}
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}

int gettoken()
{
	int c;
	char *p = token;
	if (prevtoken == YES)
	{
		prevtoken = NO;
		return tokentype;
	}
	while ((c = getchX()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getchX()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetchX(c);
			return tokentype = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getchX()) != ']';)
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)) /* is alphabet or not*/
	{
		for (*p++ = c; isalnum(c = getchX());) /* is alphanumeric or not*/
		{
			*p++ = c;
		}
		*p = '\0';
		ungetchX(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}