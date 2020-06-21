#include<stdio.h>
int main(int argc,char* argv[])
{
   printf("%d\n",argc);
   printf("%c\n",argv[0][0]);
   printf("%c\n",*(argv[0]));
   return 0;
}