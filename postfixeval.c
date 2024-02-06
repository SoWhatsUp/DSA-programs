#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define stack_size 50

void push(int item, int *top, int s[])
{
    if(*top==stack_size-1)
    {
        printf("Stack overflow\n");
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

int evaluate(char postfix[])
{
    int top,n,i,op1,op2,res,s[100];
    char symbol;
    top=-1;
    n = strlen(postfix);
    for(i=0; i<n; i++)
    {
        symbol = postfix[i];
        switch(symbol)
        {
            case '+': op1 = pop(&top, s);
                      op2 = pop(&top, s);
                      res = op2+op1;
                      push(res,&top,s);
                      break;
                    
            case '-': op1 = pop(&top, s);
                      op2 = pop(&top, s);
                      res = op2-op1;
                      push(res,&top,s);
                      break;
            
            case '*':
                      op1 = pop(&top, s);
                      op2 = pop(&top,s);
                      res = op2*op1;
                      push(res,&top,s);
                      break;
            
            case '/':
                      op1 = pop(&top,s);
                      op2 = pop(&top,s);
                      res = op2/op1;
                      push(res,&top,s);
                      break;

            case '^':
            case '$': op1 = pop(&top,s);
                      op2 = pop(&top,s);
                      res = (int)pow((double)op2,(double)op1);
                      push(res,&top,s);
                      break;

            default:  push(symbol-'0',&top,s);
                      break;
        }
    }
    return(pop(&top,s));
}

int main()
{
    char postfix[100];
    int res;
    printf("Enter the postfix expression:\n");
    scanf("%s",&postfix);
    res = evaluate(postfix);
    printf("The postfix evaulation is %d\n",res);
    return 0;
}