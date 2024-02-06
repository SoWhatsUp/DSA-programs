#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a[50],key;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter the search element:\n");
    scanf("%d",&key);
    for(i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            printf("Element found at position %d\n",i+1);
            exit(0);
        }
    }
    printf("Element not found\n");
    return 0;
}