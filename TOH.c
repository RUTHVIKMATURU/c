#include<stdio.h>
int TOH(int n,char a,char b,char c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("Move a disc from %c to %c\n",a,c);
        TOH(n-1,b,a,c);
    }
}
int main()
{
     int n;
   scanf("%d",&n);
  char a='A',b='B',c='C';
  TOH(n,a,b,c);
}
