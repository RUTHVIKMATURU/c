#include<stdio.h>
int main()
{
    int n,l,mid,h,key,i,f=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[n]);
        l=0;
        h=n-1;
        scanf("%d",&key);
       binary(a,l,h,key);
    return 0;
}
int binary(int a[],int l,int h,int key)
{
    int f,mid=(l+h)/2;
    if(l<=h)
    {
    if(key==a[mid])
    {
    }
    else if(key>a[mid])
    {
        f=0;
        return binary(a,mid+1,h,key);
    }
    else
    {
        f=0;
        return binary(a,0,mid-1,key);
    }
    }
    if(f==0)
       printf("unsuccessful");
    else
        printf("succesful");

}
