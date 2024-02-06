#include <stdio.h>
#include <stdlib.h>

struct sparsematrix
{
    int row;
    int col;
    int value;
};

typedef struct sparsematrix MATRIX;

int main()
{
    MATRIX a[100];
    int m,n,i,j,k,item,key,count;
    printf("Enter the number of rows:\n");
    scanf("%d",&m);
    printf("Enter the number of columns:\n");
    scanf("%d",&n);
    a[0].row = m;
    a[0].col = n;
    count=0;
    k=1;
    printf("Enter the elements of the sparse matrix:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&item);
            if(item!=0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = item;
                count++;
                k++;
            }
        }
    }
    a[0].value = count;
    printf("Enter search element:\n");
    scanf("%d",&key);
    for(i=1; i<=a[0].value;i++)
    {
        if(a[i].value==key)
        {
            printf("Element found at row %d and column %d\n",a[i].row+1, a[i].col+1);
            exit(0);
        }
    }
    printf("Element not found\n");
    return 0;
}