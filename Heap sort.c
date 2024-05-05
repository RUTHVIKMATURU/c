#include <stdio.h>
int n=0;
void heapify(int arr[], int n, int i) {
    if(n==1)
    {
        printf("Single element is present");
        return;
    }
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
    }
}
void insert(int a[],int newnum)
{
    if(n==0)
    {
        a[0]=newnum;
        n++;
    }
    else{
        a[n]=newnum;
        n++;
        for(int i=n/2-1;i>=0;i--)
            heapify(a,n,i);
    }
}
void deleteroot(int a[],int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(num==a[i])
            break;
    }
    int temp=a[i];
    a[i]=a[n-1];
    a[n-1]=temp;
    n--;
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
}
int main() {
    int i,size,num,x;
    printf("Enter array size:");
    scanf("%d",&size);
    int a[size];
    printf("Enter array elements:");
    for(i=1;i<=size;i++){
        scanf("%d",&num);
        insert(a,num);
    }
    printf("The sorted elements using heap sort(max heap) is:\n");
    for(i=1;i<=size;i++)
    {
        x=a[0];
        printf("%d ",x);
        deleteroot(a,x);
    }
}

