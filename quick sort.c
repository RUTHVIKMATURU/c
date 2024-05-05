#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[], int low, int high)
{
    int loc;
    if(low<high)
    {
        loc=partition(a,low,high);
        quicksort(a,low,loc-1);
        quicksort(a,loc+1,high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, start, end;
    pivot=a[low];
    start=low;
    end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(&a[start],&a[end]);
        else
            swap(&a[low], &a[end]);

    }
    return end;
}

void swap(int*x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int a[100], i, n=6;
    printf("enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a,0,5);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }


};


merge sort


#include<stdio.h>
void mergesort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        mergersort(a,low,mid,high);
    }
}
void mergersort(int a[],int low,int mid,int high)
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
    {
        a[i]=b[i];
    }
}


int main()
{
    int a[100], i, n=6;
    printf("enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(a,0,5);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }


};


radix sort


#include<stdio.h>
int findmax(int a[], int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void countingsort(int a[],int n, int pos)
{
    int b[n];
    int count[10]={0};
    for(int i=0;i<n;i++)
        count[(a[i]/pos)%10]++;
    for(int i=1; i<=10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        b[count[a[i]/pos]%10-1]=a[i];
        count[(a[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=b[i];

}

void radixsort(int a[], int n)
{
    int max=findmax(a,n);
    for(int pos=1; max/pos>0;pos+=10)
        countingsort(a,n,pos);
}


int main()
{
    int a[10], i, n=6;
    printf("enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    radixsort(a,n);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }


}
