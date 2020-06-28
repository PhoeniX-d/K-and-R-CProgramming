#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h>
#include<string.h>

#define MAXWORD         100
#define HASHSIZE		101
#define BUFFSIZE         20

typedef char*           String;
typedef struct nlist    *Nlistptr;
typedef struct nlist						/* table entrys */
{
    Nlistptr        next;			/*next entry in chain*/
    String			name;			/* defined name*/
    String 			defn;			/* replacement text*/
}Nlist;

int buf[BUFFSIZE];
int bufp = 0;
static Nlistptr hashtab[HASHSIZE];			/*pointer table*/

void     error(int,String);
int      getchX();
void     getdef();
int      getword(String,int);
Nlistptr install(String,String);
Nlistptr lookup(String);
void     skipblanks();
void     undef(String);
void     ungetchX(int);
void     ungets(String);

/* simple version of #define prcessor */
int main()
{
    char w[MAXWORD];
    Nlistptr p;

    while((getword(w,MAXWORD)) != EOF)
    {
        if(strcmp(w,"#") == 0)/*beginning od directve*/
        {
            getdef();
        }
        else if(!isalpha(w[0]))
        {
            printf("%s",w);   /*cannot be defined*/
        }
        else if((p = lookup(w)) == NULL)
        {
            printf("%s",w); /* not defined */
        }
        else
        {
            ungets(p->defn);/*push defination*/
        }
    }
    return 0;
}

void getdef()
{
    int c, i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];
    skipblanks();
    if(!isalpha(getword(dir,MAXWORD)))
    {
        error(dir[0],"getdef : expected a directive after #");
    }
    else if(strcmp(dir, "define") == 0)
    {
        skipblanks();
        if(!isalpha(getword(name,MAXWORD)))
        {
            error(name[0],"getdef : non-alpha - name expected");
        }
        else
        {
            skipblanks();
            for(i = 0; i<MAXWORD; i++)
            {
                if(((def[i] = getchX()) == EOF) || def[i] == '\n')
                    break;  /* end of definition */ 
            }
            def[i] = '\0';
            if(i <= 0)
                error('\n',"getdef : incomplete define");
            else
                install(name,def);
        }
    }
    else if(strcmp(dir, "undef") == 0)
    {
        skipblanks();
        if(!isalpha(getword(name,MAXWORD)))
        {
            error(name[0],"getdef : non-alpha - in undef");
        }
        else
        {
            undef(name);
        }
    }
    else
    {
        error(dir[0],"getdef : expected a directive after #");

    }
}

/*gets word from input and filters it*/
int getword(String word,int limit)
{
    int c;
    char *w = word;
    while(isspace(c = getchX()) && c != '\n')
        ;

    if(c != EOF)
    {
        *w++ = c;
    }

    if(!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    while(--limit > 0)
    {
        if(!isalnum(*w = getchX()))
        {
            ungetchX(*w);
            break;
        }
        w++;
    }
    *w = '\0';
    return word[0];
}

/* prints error msgs and prints rest of the lines */
void error(int c,String s)
{
    printf("%c error: %s\n",c,s);
    while(c != EOF && c != '\n')
        c = getchX();
}

/* skipblanks skips blank and tab characters */
void skipblanks()
{
    int c;
    while((c = getchX()) == ' ' || c == '\t')
        ;
    ungetchX(c);
}
/* get (probably pushed back) character */
int getchX()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* put unwanted char back to buffer */
void ungetchX(int c)
{
    if(bufp >= BUFFSIZE)
    {
        printf("Ungetch :too many arg\n");
    }
    else 
        buf[bufp++] = c;
}


/* hash : from hash value for string */
unsigned hash(String s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
    {   
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/*lookup : look for s in hashtab */
Nlistptr lookup(String s)
{
    Nlistptr np = NULL;
    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if(strcmp(s,np->name) == 0)
            return np;  /*found*/
    }
    return NULL;    /*not found*/
}

Nlistptr install(String name,String defn)
{
    Nlistptr np;
    unsigned hashval;
    
    if((np = lookup(name)) == NULL) /*not found*/ 
    {
        np = (struct nlist*)malloc(sizeof(struct nlist));
        if(np == NULL)
        {
            return NULL;
        }
        
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;       
    }
    else /*already there*/
    {
        free((void *)np->defn); /*free previous defn*/
    }
    if((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}


/* undef remove a name and definition from table */ 
void undef(String s)
{
    int h;
    Nlistptr prev,np;

    prev = NULL;
    h = hash(s);        /* hash value of string */
    for(np = hashtab[h]; np != NULL; np = np->next)
    {
        if(strcmp(s,np->name) == 0)
            break;
        prev = np;      /* remember previous entry */
    }

    if(np != NULL)      /* found one */
    {
        if(prev == NULL)    /* first in hash list ? */
        {
            hashtab[h] = np->next;
        }
        else
        {
            prev->next = np->next;
        }
        /* free allocated structures */
        free((void *)np->next);
        free((void *)np->defn);
        free((void *)np);
    }
}

/* ungets : push string back to input */
void ungets(String s)
{
    int len = strlen(s);
    while(len > 0)
        ungetchX(s[--len]);
}