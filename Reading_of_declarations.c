<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN	100
#define BUFFSIZE 	100

enum {NAME,PARENS,BRACKETS};
enum {NO,YES};

char buf[BUFFSIZE];
int  bufp = 0;
void dirdcl();
void dcl();
int  gettoken();
int  tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
void ungetchX(int c);
int  getchX();
int  prevtoken = NO;
int  nexttoken()
{
	int type;
	extern int prevtoken;
	type = gettoken();
	prevtoken = YES;
	return  type;
}

void dcl()
{
	int ns;
	for(ns = 0;gettoken() == '*';)
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out," pointer to");
}

int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetchX(int c)
{
	if(bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}
void dirdcl()
{
	int type;
	if(tokentype == '(')
	{
		dcl();
		if(tokentype != ')')
			printf("Error : missing )\n");
	}
	else if(tokentype == NAME)
	{
		strcpy(name,token);
	}
	else
	{
		printf("Error:Expected name or (dcl)\n");
	}

	while((type = gettoken()) == PARENS || type == BRACKETS)
	{
		if(type == PARENS)
			strcat(out," function returning");
		else
		{
			strcat(out," array");
			strcat(out,token);
			strcat(out," of");
		}
	}
}

void declaration_to_word()
{
	while(gettoken() != EOF)
	{
		strcpy(datatype,token);
		out[0] = '\0';
		dcl();
		if(tokentype != '\n')
			printf("Syntax Error\n");
		printf("%s : %s %s\n",name,out,datatype);
	}	
}

int gettoken()
{
	int c;
	char *p = token;
	if(prevtoken == YES)
	{
		prevtoken = NO;
		return tokentype;
	}
	while((c = getchX()) == ' ' || c == '\t')
		;
	if(c == '(')
	{
		if((c = getchX()) == ')')
		{
	 		strcpy(token,"()");
			return tokentype = PARENS;
		}
		else
		{
			ungetchX(c);
			return tokentype = '(';
		}
	}
	else if(c == '[')
	{
		for(*p++ = c; (*p++ = getchX()) != ']';)
	 		;
	 	*p = '\0';
	 	return tokentype = BRACKETS;
	} 
	else if(isalpha(c)) /* is alphabet or not*/
	{ 
	 	for(*p++ = c; isalnum(c = getchX());)/* is alphanumeric or not*/
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

int main()
{
	int type;
	char temp[MAXTOKEN];

	while(gettoken() != EOF)
	{
		strcpy(out,token);
		while((type = gettoken()) !='\n')
		{
			if(type == PARENS || type == BRACKETS)
				strcat(out,token);
			else if(type == '*')
			{
				if((type = nexttoken()) == PARENS || type == BRACKETS)
					sprintf(temp,"*(%s)",out);
				else
					sprintf(temp,"*%s",out);
				strcpy(out,temp);
			}
			else if(type == NAME)
			{
				sprintf(temp,"%s %s",token,out);
				strcpy(out,temp);
			}
			else
			{
				printf("Invalid input at %s\n",token);
			}
		}
		printf("%s\n", out);
	}
	return 0;
}
=======
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN	100
#define BUFFSIZE 	100

enum {NAME,PARENS,BRACKETS};
enum {NO,YES};

char buf[BUFFSIZE];
int  bufp = 0;
void dirdcl();
void dcl();
int  gettoken();
int  tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
void ungetchX(int c);
int  getchX();
int  prevtoken = NO;
int  nexttoken()
{
	int type;
	extern int prevtoken;
	type = gettoken();
	prevtoken = YES;
	return  type;
}

void dcl()
{
	int ns;
	for(ns = 0;gettoken() == '*';)
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out," pointer to");
}

int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetchX(int c)
{
	if(bufp >= BUFFSIZE)
	{
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}
void dirdcl()
{
	int type;
	if(tokentype == '(')
	{
		dcl();
		if(tokentype != ')')
			printf("Error : missing )\n");
	}
	else if(tokentype == NAME)
	{
		strcpy(name,token);
	}
	else
	{
		printf("Error:Expected name or (dcl)\n");
	}

	while((type = gettoken()) == PARENS || type == BRACKETS)
	{
		if(type == PARENS)
			strcat(out," function returning");
		else
		{
			strcat(out," array");
			strcat(out,token);
			strcat(out," of");
		}
	}
}

void declaration_to_word()
{
	while(gettoken() != EOF)
	{
		strcpy(datatype,token);
		out[0] = '\0';
		dcl();
		if(tokentype != '\n')
			printf("Syntax Error\n");
		printf("%s : %s %s\n",name,out,datatype);
	}	
}

int gettoken()
{
	int c;
	char *p = token;
	if(prevtoken == YES)
	{
		prevtoken = NO;
		return tokentype;
	}
	while((c = getchX()) == ' ' || c == '\t')
		;
	if(c == '(')
	{
		if((c = getchX()) == ')')
		{
	 		strcpy(token,"()");
			return tokentype = PARENS;
		}
		else
		{
			ungetchX(c);
			return tokentype = '(';
		}
	}
	else if(c == '[')
	{
		for(*p++ = c; (*p++ = getchX()) != ']';)
	 		;
	 	*p = '\0';
	 	return tokentype = BRACKETS;
	} 
	else if(isalpha(c)) /* is alphabet or not*/
	{ 
	 	for(*p++ = c; isalnum(c = getchX());)/* is alphanumeric or not*/
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

int main()
{
	int type;
	char temp[MAXTOKEN];

	while(gettoken() != EOF)
	{
		strcpy(out,token);
		while((type = gettoken()) !='\n')
		{
			if(type == PARENS || type == BRACKETS)
				strcat(out,token);
			else if(type == '*')
			{
				if((type = nexttoken()) == PARENS || type == BRACKETS)
					sprintf(temp,"*(%s)",out);
				else
					sprintf(temp,"*%s",out);
				strcpy(out,temp);
			}
			else if(type == NAME)
			{
				sprintf(temp,"%s %s",token,out);
				strcpy(out,temp);
			}
			else
			{
				printf("Invalid input at %s\n",token);
			}
		}
		printf("%s\n", out);
	}
	return 0;
}
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
