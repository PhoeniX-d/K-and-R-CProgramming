<<<<<<< HEAD
<<<<<<< HEAD
=======
#include"headers.h"
/*
*paramdcl() :parses parameter declarator
*input 		:void
*output		:void
*/
void paramdcl()
{
	do
	{
		dclspec();
	}while(tokentype == ',');
	if(tokentype != ')')
		errmsg("missing  ) i parameter declaration\n");
}

/*
*dclspec()  :declaration specification
*input 		:void
*output		:void
*/
void dclspec()
{
	char temp[MAXTOKEN];
	temp[0] = '\0';
	gettoken();
	do
	{
		if(tokentype != NAME)
		{
			prevtoken = YES;
			dcl();
		}
		else if(typespec() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else if(typequal() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else
		{
			errmsg("unknown type in parameter list\n");
		}
	}while(tokentype != ',' && tokentype != ')');
	strcat(out,temp);
	if(tokentype == ',')
		strcat(out,",");
}

/*
*typespec()  :return YES if token is a type specifier
*input 		 :void
*output		 :int
*/
int typespec()
{
	static char *types[]={"char","int","void"};
	char *pt = token;

	if(bsearch(&pt, types,sizeof(types)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*typequal()  :return YES if token is a type qualifier
*input 		 :void
*output		 :int
*/
int typequal()
{
	static char *typeq[]={"const","volatile"};
	char *pt = token;

	if(bsearch(&pt, typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*compare()   :compare two strings for bsearch
*input 		 :char **,char **
*output		 :int
*/
int compare(char **s,char **t)
{
	return strcmp(*s,*t);
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include"headers.h"
/*
*paramdcl() :parses parameter declarator
*input 		:void
*output		:void
*/
void paramdcl()
{
	do
	{
		dclspec();
	}while(tokentype == ',');
	if(tokentype != ')')
		errmsg("missing  ) i parameter declaration\n");
}

/*
*dclspec()  :declaration specification
*input 		:void
*output		:void
*/
void dclspec()
{
	char temp[MAXTOKEN];
	temp[0] = '\0';
	gettoken();
	do
	{
		if(tokentype != NAME)
		{
			prevtoken = YES;
			dcl();
		}
		else if(typespec() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else if(typequal() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else
		{
			errmsg("unknown type in parameter list\n");
		}
	}while(tokentype != ',' && tokentype != ')');
	strcat(out,temp);
	if(tokentype == ',')
		strcat(out,",");
}

/*
*typespec()  :return YES if token is a type specifier
*input 		 :void
*output		 :int
*/
int typespec()
{
	static char *types[]={"char","int","void"};
	char *pt = token;

	if(bsearch(&pt, types,sizeof(types)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*typequal()  :return YES if token is a type qualifier
*input 		 :void
*output		 :int
*/
int typequal()
{
	static char *typeq[]={"const","volatile"};
	char *pt = token;

	if(bsearch(&pt, typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*compare()   :compare two strings for bsearch
*input 		 :char **,char **
*output		 :int
*/
int compare(char **s,char **t)
{
	return strcmp(*s,*t);
<<<<<<< HEAD
=======
#include"headers.h"
/*
*paramdcl() :parses parameter declarator
*input 		:void
*output		:void
*/
void paramdcl()
{
	do
	{
		dclspec();
	}while(tokentype == ',');
	if(tokentype != ')')
		errmsg("missing  ) i parameter declaration\n");
}

/*
*dclspec()  :declaration specification
*input 		:void
*output		:void
*/
void dclspec()
{
	char temp[MAXTOKEN];
	temp[0] = '\0';
	gettoken();
	do
	{
		if(tokentype != NAME)
		{
			prevtoken = YES;
			dcl();
		}
		else if(typespec() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else if(typequal() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else
		{
			errmsg("unknown type in parameter list\n");
		}
	}while(tokentype != ',' && tokentype != ')');
	strcat(out,temp);
	if(tokentype == ',')
		strcat(out,",");
}

/*
*typespec()  :return YES if token is a type specifier
*input 		 :void
*output		 :int
*/
int typespec()
{
	static char *types[]={"char","int","void"};
	char *pt = token;

	if(bsearch(&pt, types,sizeof(types)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*typequal()  :return YES if token is a type qualifier
*input 		 :void
*output		 :int
*/
int typequal()
{
	static char *typeq[]={"const","volatile"};
	char *pt = token;

	if(bsearch(&pt, typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),compare) == NULL)
		return NO;
	else
		return YES;
}

/*
*compare()   :compare two strings for bsearch
*input 		 :char **,char **
*output		 :int
*/
int compare(char **s,char **t)
{
	return strcmp(*s,*t);
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}