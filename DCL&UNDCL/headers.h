#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXTOKEN	100
#define BUFFSIZE 	100

enum {NAME,PARENS,BRACKETS};
enum {NO,YES};

void dcl();
void errmsg(char*);
void dclspec();
int  typespec();
int  typequal();
int  compare(char **,char **);
int  gettoken();
void dirdcl();
void dcl();
int  nexttoken();
void ungetchX(int c);
int  getchX();
void paramdcl();

char buf[BUFFSIZE];
int  bufp = 0;
int  prevtoken;
int  tokentype;   		/*type of last token*/
char token[MAXTOKEN];			/*last token string*/
char name[MAXTOKEN];				/*identifier name*/
char datatype[MAXTOKEN];			/*data type = char,int etc.*/
char out[1000];