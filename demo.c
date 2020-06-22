#include<stdio.h>
int main(int argc,char* argv[])
{
   printf("%c\n",(*++argv)[0]);
   printf("%s\n",argv[0] + 1);  
   return 0;
}