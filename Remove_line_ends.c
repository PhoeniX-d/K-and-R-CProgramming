<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>

#define MAXLINE     100

int getlinex(char line[]);
int removex(char line[]);

int main()
{
    char line[MAXLINE];
    int len = 0;
    while(getlinex(line) >=0)
    {
        if(removex(line))
    }
    return 0;
}

int getlinex(char line[])
{
    int i = 0,c = 0;
    for(i = 0;i<MAXLINE -1 && (c =getchar()) != EOF && c !='\n';i++)
    {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int removex(char line[])
{
    int i = 0;
    while(line[i] != '\n')
        i++;
    --i;
    while((line[i] == ' ' || line[i] == '\t') && i >= 0)
        --i;
    if(i >= 0)
    {
        ++i;line[i] = '\n';
        ++i;
        line[i] = '\0'
    }
    return i;
}

=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>

#define MAXLINE     100

int getlinex(char line[]);
int removex(char line[]);

int main()
{
    char line[MAXLINE];
    int len = 0;
    while(getlinex(line) >=0)
    {
        if(removex(line))
    }
    return 0;
}

int getlinex(char line[])
{
    int i = 0,c = 0;
    for(i = 0;i<MAXLINE -1 && (c =getchar()) != EOF && c !='\n';i++)
    {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int removex(char line[])
{
    int i = 0;
    while(line[i] != '\n')
        i++;
    --i;
    while((line[i] == ' ' || line[i] == '\t') && i >= 0)
        --i;
    if(i >= 0)
    {
        ++i;line[i] = '\n';
        ++i;
        line[i] = '\0'
    }
    return i;
}

<<<<<<< HEAD
=======
#include<stdio.h>

#define MAXLINE     100

int getlinex(char line[]);
int removex(char line[]);

int main()
{
    char line[MAXLINE];
    int len = 0;
    while(getlinex(line) >=0)
    {
        if(removex(line))
    }
    return 0;
}

int getlinex(char line[])
{
    int i = 0,c = 0;
    for(i = 0;i<MAXLINE -1 && (c =getchar()) != EOF && c !='\n';i++)
    {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int removex(char line[])
{
    int i = 0;
    while(line[i] != '\n')
        i++;
    --i;
    while((line[i] == ' ' || line[i] == '\t') && i >= 0)
        --i;
    if(i >= 0)
    {
        ++i;line[i] = '\n';
        ++i;
        line[i] = '\0'
    }
    return i;
}

=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
