#include<stdio.h>
int fact(n)
{
    if(n>0)
        return n*fact(n-1);
    else
        return 1;
}
int main()
{
    int n;
    printf("Enter number you want to find factorial:");
    scanf("%d",&n);
printf("Factorial = %d",fact(n));
}
