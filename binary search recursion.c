#include<stdio.h>
int binary(int a[],int l,int h,int key)
{
    int mid,f;
       mid=(l+h)/2;
    if(a[mid]==key)
    {
        return 1;
    }
    else if(a[mid]>key&&l<=h)
    {
         return binary(a,l,mid-1,key);
    }
    else if(a[mid]<key&&l<=h)
    {
        return binary(a,mid+1,h,key);
    }
        return 0;
}
int main()
{
    int n,i,key,f;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&key);
    int l=0,h=n-1;
        f=binary(a,l,h,key);
        if(f==1)
            printf("element found");
        else
            printf("element not found");
return 0;
}
