#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[],int n)
{
    int i,j,min_idx;
    for(i=0; i<n-1; i++)
    {
        min_idx = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[min_idx])
                min_idx = j;
        }
        swap(&a[min_idx], &a[i]);
    }
}

void read(int a[], int n)
{
    int i;
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
}

void print(int a[], int n)
{
    int i;
    printf("\nThe elements of the array are:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    printf("\n");
}

int main()
{
    int n,a[50];
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    read(a,n);
    printf("\nSorting");
    sort(a,n);
    printf("\nDone");
    print(a,n);
    return 0;
}

