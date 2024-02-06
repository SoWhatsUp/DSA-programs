#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node * link;
};

typedef struct node * NODE;

NODE insert_rear(int item, NODE first)
{
    NODE temp = (NODE)malloc(sizeof(struct node)),cur;
    temp->info = item;
    temp->link = NULL;
    if(first==NULL)
        return temp;
    cur = first;
    while(cur->link!=NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Queue is empty. Deletion not possible\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("The deleted item is %d\n",temp->info);
    free(temp);
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Queue is empty");
        return;
    }
    cur = first;
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur = cur->link;
    }
    printf("\n");
}

int main()
{
    NODE first=NULL;
    int choice,item;
    for(;;)
    {
        printf("1.Insert rear\n2.Delete front\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted:\n");
                    scanf("%d",&item);
                    first = insert_rear(item, first);
                    break;

            case 2: first = delete_front(first);
                    break;

            case 3: printf("The elements of the queue are:\n");
                    display(first);
                    break;

            default:exit(0);
        }
    }
}