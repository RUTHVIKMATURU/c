#include<stdio.h>
int gcd(int n,int m)
{
    if(m==0)
        return n;
    else
        return gcd(m,n%m);
}
int main()
{
    int n,m;
    printf("Enter two numbers:");
    scanf("%d%d",&n,&m);
    printf("GCD of %d and %d = %d",n,m,gcd(n,m));
}
