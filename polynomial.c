#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cf;
    int px;
    struct node * link;
};

typedef struct node * NODE;

void display(NODE head)
{
    NODE cur;
    if(head->link==head)
    {
        printf("Polynomial doesn't exist\n");
        return ;
    }
    cur = head->link;
    while(cur!=head)
    {
        if(cur->cf>0)
            printf("+");
        printf("%dx^%d",cur->cf,cur->px);
        cur = cur->link;
    }
    printf("\n");
}

NODE insert_rear(int cf, int px, NODE head)
{
    NODE temp,cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px;
    temp->link = temp;
    cur = head->link;
    while(cur->link!=head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE readpoly(NODE head)
{
    int i,n,px,cf;
    printf("Enter no of terms in the polynomial:\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter coefficient and power of %d term\n",i);
        scanf("%d%d",&cf,&px);
        head = insert_rear(cf,px,head);
    }
    return head;
}



int compare(int x, int y)
{
    if(x==y)
        return 0;
    if(x>y)
        return 1;
    return -1;
}

NODE addpoly(NODE h1, NODE h2, NODE h3)
{
    NODE p1, p2;
    int sumcf;
    p1 = h1->link;
    p2 = h2->link;
    while(p1!=h1 && p2!=h2)
    {
        switch(compare(p1->px,p2->px))
        {
            case 0: sumcf = p1->cf = p2->cf;
                    if(sumcf!=0)
                        h3 = insert_rear(sumcf,p1->px,h3);
                    p1 = p1->link;
                    p2 = p2->link;
                    break;

            case 1: h3 = insert_rear(p1->cf,p1->px,h3);
                    p1 = p1->link;
                    break;
                
            case -1: h3 = insert_rear(p2->cf, p2->px, h3);
                     p2 = p2->link;
                     break;
        }
    }
    while(p1!=h1)
    {
        h3 = insert_rear(p1->cf, p1->px,h3);
        p1 = p1->link;
    }
    while(p2!=h2)
    {
        h3 = insert_rear(p2->cf, p2->px, h3);
        p2 = p2->link;
    }
    return h3;
}

int main()
{
    NODE h1,h2,h3;
    h1=(NODE)malloc(sizeof(struct node));
    h2=(NODE)malloc(sizeof(struct node));
    h3=(NODE)malloc(sizeof(struct node));
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    printf("Enter the first polynomial:\n");
    h1 = readpoly(h1);
    printf("\nEnter the second polynomial:\n");
    h2 = readpoly(h2);
    h3 = addpoly(h1,h2,h3);
    printf("\nThe first polynomial is:\n");
    display(h1);
    printf("\nThe second polynomial is:\n");
    display(h2);
    printf("\nThe resultant polynomial after addition is:\n");
    display(h3);
    return 0;
}