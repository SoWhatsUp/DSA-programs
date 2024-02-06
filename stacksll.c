#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node * link;
};

typedef struct node * NODE;

NODE insert_front(int item, NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link = first;
    return temp;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Stack empty! Deletion not possible\n");
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
        printf("Stack empty.\n");
        return ;
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
    NODE first = NULL;
    int choice, item;
    for(;;)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be inserted:\n");
                    scanf("%d",&item);
                    first = insert_front(item,first);
                    break;

            case 2: first = delete_front(first);
                    break;

            case 3: printf("Elements of the stack are:\n");
                    display(first);
                    break;

            default:exit(0);
        }
    }
}