#include<stdio.h>
#include<stdlib.h>
char queue[100];
int rear=-1,front=-1;
void insert(char x)
{
    if(rear==99)
        return;
    queue[++rear]=x;
    if(front==-1)
        front=0;
}
char delete_rear()
{
    if(rear==-1)
    {
        return 0;
    }
    return queue[rear--];
}
int main()
{
    int f=1,i,j;
    char str[100];
    printf("Enter a string:");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        insert(str[i]);
    }
    for(i=0;rear!=-1;i++)
    {
        if(str[i]!=delete_rear())
        {
            printf("%s is not a palindrome\n",str);
            f=0;
            break;
        }
    }
    if(f==1)
    {
        printf("%s is palindrome\n",str);
    }
}
