#include<stdio.h>
#include<stdlib.h>
struct node{
int pow,coff;
struct node *link;
}*p1,*p2,*p3;
typedef struct node NODE;
NODE *insert()
{
    NODE *first=NULL,*last,*newnode;
    int ch;
    do{
        newnode=(NODE*)malloc(sizeof(NODE));
        printf("\nenter coff and pow:");
        scanf("%d%d",&newnode->coff,&newnode->pow);
        newnode->link=NULL;
        if(first==NULL)
        {
            first=last=newnode;
        }
        else
        {
            last->link=newnode;
            last=newnode;
        }
        printf("enter 1 for continue else 0:");
        scanf("%d",&ch);
    }while(ch==1);
    return (first);
}
void add(NODE *t1,NODE *t2)
{
    NODE *newnode,*t;
    while(t1!=NULL&&t2!=NULL)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->link=NULL;
        if(t1->pow>t2->pow)
        {
            newnode->coff=t1->coff;
            newnode->pow=t1->pow;
            t1=t1->link;
        }
        else if(t2->pow>t1->pow)
        {
            newnode->coff=t2->coff;
            newnode->pow=t2->pow;
            t2=t2->link;
        }
        else
        {
            newnode->pow=t1->pow;
            newnode->coff=t1->coff+t2->coff;
            t1=t1->link;
            t2=t2->link;
        }
        if(p3==NULL)
        {
            p3=newnode;
            t=newnode;
        }
        else
        {
            t->link=newnode;
            t=t->link;
        }
    }
    while(t1!=NULL)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->coff=t1->coff;
        newnode->pow=t1->pow;
        t->link=newnode;
        t=newnode;
        t1=t1->link;
        newnode->link=NULL;

    }
    while(t2!=NULL)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->coff=t2->coff;
        newnode->pow=t2->pow;
        t->link=newnode;
        t=newnode;
        t2=t2->link;
        newnode->link=NULL;
    }
}
void display(NODE *temp)
{
    while(temp!=NULL)
    {
        if(temp->coff<0)
            printf("-");
        else
            printf("+");
        printf("%dx^%d",abs(temp->coff),temp->pow);
        temp=temp->link;
    }
}
int main()
{
    printf("Enter polynomial Eq-1:");
    p1=insert();
    printf("Enter polynomial Eq-2:");
    p2=insert();
    printf("EQ-1:");
    display(p1);
    printf("\n");
    printf("EQ-2:");
    display(p2);
    printf("\n");
    add(p1,p2);
    printf("\nSum of two polynomial Eq:\n");
    display(p3);
    return 0;
}
