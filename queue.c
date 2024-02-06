#include <stdio.h>
#include <stdlib.h>
#define q_size 5

void insert_rear(int item, int *r, int q[])
{
    if(*r==q_size-1)
    {
        printf("Queue is full. Insertion not possible\n");
        return;
    }

    *r = *r+1;
    q[*r] = item;
}

void delete_front(int *f, int *r, int q[])
{
    int item;
    if(*f>*r)
    {
        printf("Queue is empty. Deletion not possible\n");
        return;
    }
    item = q[*f];
    *f = *f+1;
    printf("The deleted item is %d\n",item);
    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int f, int r, int q[])
{
    int i;
    if(f>r)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=f; i<=r; i++)
    {
        printf("%d\t",q[i]);
    }
    printf("\n");
}

int main()
{
    int q[q_size],f=0,r=-1;
    int item,choice;
    for(;;)
    {
        printf("1.Insert rear\n2.Delete front\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be inserted:\n");
                    scanf("%d",&item);
                    insert_rear(item,&r,q);
                    break;

            case 2: delete_front(&f,&r,q);
                    break;

            case 3: printf("The contents of the queue are:\n");
                    display(f,r,q);
                    break;
            default: exit(0);
        }
    }
}