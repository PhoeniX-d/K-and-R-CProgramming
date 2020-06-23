#include "dcl_dirdcl.c"

int main()
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
	return 0;
}
