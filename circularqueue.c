#include <stdio.h>
#include <stdlib.h>

#define q_size 5

void insert_rear(int item, int *count, int *r, int q[])
{
    if(*count==q_size)
    {
        printf("Queue is full. Insertion is not possible\n");
        return;
    }

    *r = (*r+1)%q_size;
    q[*r] = item;
    *count = *count+1;
}

void delete_front(int *count, int *f,int q[])
{
    int item;
    if(*count==0)
    {
        printf("Queue is empty. Deletion not possible");
        return;
    }
    item = q[*f];
    *f = (*f+1)%q_size;
    *count=*count-1;
    printf("The deleted element is %d\n",item);
}

void display(int count, int f, int q[])
{
    int i;
    if(count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=0; i<count; i++)
    {
        printf("%d\t",q[f]);
        f = (f+1)%q_size;
    }
    printf("\n");
}

int main()
{
    int f=0, r = -1, count=0;
    int q[q_size], choice, item;
    for(;;)
    {
        printf("1.Insert rear\n2.Delete front\n3.Display\n4.Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be inserted:\n");
                    scanf("%d",&item);
                    insert_rear(item,&count,&r,q);
                    break;

            case 2: delete_front(&count,&f,q);
                    break;

            case 3: printf("The contents of the queue are:\n");
                    display(count,f,q);
                    break;

            default: exit(0);
        }
    }
}