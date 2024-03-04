#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[100];
int push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
        return '1';
    else
        return stack[top--];
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
}
int main()
{
    char str[100],*e;
    printf("Enter an expression: ");
    scanf("%s",str);
    e=str;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
                    push(*e);
        else if(*e==')')
        {
            while(stack[top]!='(')
            {
                if(top!=-1)
                    printf("%c",pop());
            }
            pop();
        }
        else
        {
            if(priority(stack[top])>=priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}

