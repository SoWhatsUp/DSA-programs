#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

void push(int item, int *top, int s[])
{
    if(*top==STACK_SIZE-1)
    {
        printf("Stack is full. Insertion not possible\n");
        return;
    }
    *top = *top+1;
    s[*top] = item;
}

int pop(int *top, int s[])
{
    int item;
    if(*top==-1)
    {
        return -1;
    }
    item = s[*top];
    *top = *top-1;
    return item;
}

void display(int top, int s[])
{
    int i;
    if(top==-1)
    {
        printf("No elements in stack\n");
        return;
    }
    for(i=0; i<=top; i++)
        printf("%d\t",s[i]);
    printf("\n");
}

int main()
{
    int s[50],top=-1,choice,item,res;
    for(;;)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d",&item);
                push(item,&top,s);
                break;
            case 2:
                res = pop(&top, s);
                if(res==-1)
                {
                    printf("Stack is empty\n");
                }
                else
                    printf("Deleted item is %d\n",res);
                break;

            case 3:
                printf("Elements of the stack are:\n");
                display(top,s);
                break;

            default: exit(0);
        }
    }
}