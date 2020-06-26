<<<<<<< HEAD
<<<<<<< HEAD
=======
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
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
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
<<<<<<< HEAD
=======
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
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
