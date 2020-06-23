#include"dcl_dirdcl.c"
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
