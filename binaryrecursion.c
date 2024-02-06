#include <stdio.h>
#include <stdlib.h>

int binarysearch(int a[],int low,int high,int key)
{
    int mid;
    if(low>high)
        return -1;
    mid = (low+high)/2;
    if(a[mid]==key)
        return (mid+1);
    if(a[mid]>key)
        return binarysearch(a,low,mid-1,key);
    return binarysearch(a,mid+1,high,key);
}

int main()
{
    int n,i,a[50],key,res;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0; i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the search element:\n");
    scanf("%d",&key);
    res = binarysearch(a,0,n-1,key);
    if(res>0)
    {
        printf("Element found at position %d\n",res);
    }
    else
        printf("Element not found\n");
    return 0;
}