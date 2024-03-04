#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
int push(char x)
{
    stack[++top]=x;
}
int pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}
int isoperator(char x)
{
    return (x=='+'||x=='-'||x=='*'||x=='/');
}
int main()
{
    int a,b,c,num,sum=0;
    char str[100];
    printf("Enter a postfix expression with separated by a space: ");
    gets(str);
    char *e;
    e=str;
    while(*e!='\0')
    {
        if(*e==' ')
        {
            e++;
            continue;
        }
        else if(isdigit(*e))
        {
            sum=0;
        while(*e!=' ')
        {
            num=*e-48;
            sum=sum*10+num;
            if(!isdigit(*(e+1)))
            {
                push(sum);
                break;
            }
            e++;
        }

        }
        else if(isoperator(*e))
        {
            a=pop();
            b=pop();
            switch(*e)
            {
                case '+':c=a+b;
                break;
                case '-':c=b-a;
                break;
                case '*':c=a*b;
                break;
                case '/':c=b/a;
                break;
            }
            push(c);
        }
        e++;
    }
    printf("Result of evaluated expression %s = %d",str,c);
}
