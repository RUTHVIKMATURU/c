#include<stdio.h>
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int l1,l2,i,b[high+1];
    for(l1=low,l2=mid+1,i=low;l1<=mid&&l2<=high;i++)
    {
        if(a[l1]<=a[l2])
            b[i]=a[l1++];
        else
            b[i]=a[l2++];
    }
    while(l1<=mid)
        b[i++]=a[l1++];
    while(l2<=high)
        b[i++]=a[l2++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
}
void printarray(int a[],int n)
{
    printf("the sorted array is :");
    for(int i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
}
int main()
{
    int n,i;
    printf("enter size of array");
    scanf("%d",&n);
    int a[n];
    printf("enter array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printarray(a,n);
}

