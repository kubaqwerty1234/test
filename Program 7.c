#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char author[21];
    char name[51];
    int year;
};
typedef struct book BOOK;
struct List
{
    BOOK book;
    struct List *pNext;
};
typedef struct List LIST;
void enterbook(BOOK *p);
void printbook(BOOK p);
LIST *enterlist(LIST *pFirst, BOOK book);


void printlist(LIST *pFirst);
int main()
{
    int n,i;
    BOOK book;
    LIST *pFirst,*p;
    pFirst = NULL;
    printf("How many books are you gonna enter:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        enterbook(&book);
        p=enterlist(pFirst,book);
        if(!p)
            break;
        pFirst=p;
    }
    printlist(pFirst);
    system("pause");
    return 0;
}
void enterbook(BOOK *p)
{
    fflush(stdin);
    printf("Enter the author name:");
    gets(p->author);
    printf("Enter the name of the book:");
    gets(p->name);
    printf("Enter the year of publishing of the book:");
    scanf("%d",&(p->year));
}
void printbook(BOOK p)
{
    printf("%s, %s, %d\n",p.author,p.name, p.year);
}
LIST *enterlist(LIST *pFirst, BOOK book)
{
    LIST *p;
    p=(LIST*)malloc(sizeof(LIST));
    if(p==NULL)
    {
        printf("There is not enough memory.");
        return NULL;
    }
    else
    {
        p->book=book;
        p->pNext=pFirst;
        //pFirst=p;
        return p;
    }


}
void printlist(LIST *pFirst)
{
    LIST *p;
    p=pFirst;
    if(p==NULL)
        printf("Empty list");
    else
    {
         while(p!=NULL)
    {
        printbook(p->book);
        p=p->pNext;
    }
    }
}
