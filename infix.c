#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_size 50

void push(char item, int *top, char s[])
{
    if(*top==(stack_size-1))
    {
        printf("Stack is full. Insertion not possible\n");
        return;
    }
    *top = *top+1;
    s[*top] = item;
}

int input_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}

int stack_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default:  return 8;
    }
}

char pop(int *top, char s[])
{
    char item;
    if(*top==-1)
    {
        return '@';
    }
    item = s[*top];
    *top = *top-1;
    return item;
}

void infix_conversion(char infix[], char postfix[])
{
    char symbol;
    char s[50];
    int top;
    int n,i;
    n = strlen(infix);
    int j=0;
    top=-1;
    push('#',&top,s);
    for(i=0; i<n; i++)
    {
        symbol = infix[i];
        while(stack_precedence(s[top])>input_precedence(symbol))
        {
            postfix[j]=pop(&top,s);
            j++;
        }
        if(stack_precedence(s[top])!=input_precedence(symbol))
            push(symbol,&top,s);
        else
            pop(&top,s);
    }
    while(s[top]!='#')
    {
        postfix[j] = pop(&top,s);
        j++;
    }
    postfix[j] = NULL;
}

int main()
{
    char postfix[50],infix[50];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    infix_conversion(infix,postfix);
    printf("The postfix expression is %s\n",postfix);
    return 0;
}