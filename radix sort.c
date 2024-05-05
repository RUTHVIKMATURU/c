#include<stdio.h>
int find_max(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max)
           max=a[i];
    return max;
}
void countingsort(int a[],int n,int pos)
{
    int b[n],count[10]={0};
    for(int i=0;i<n;i++)
        count[(a[i]/pos)%10]++;
    for(int i=1;i<=10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        b[count[(a[i]/pos)%10]-1]=a[i];
        count[(a[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=b[i];
}
void radixsort(int a[],int n)
{
    int max=find_max(a,n);
    for(int pos=1;max/pos>0;pos*=10)
        countingsort(a,n,pos);
}
void printarray(int a[],int n)
{
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int i,n;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter array elements:");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    radixsort(a,n);
    printarray(a,n);
    return 0;
}
