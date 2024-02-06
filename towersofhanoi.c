#include <stdio.h>

int count= 0;

void tower(int n, char source, char destination, char temp)
{
    if(n==1)
    {
        printf("Move %d disk from %c to %c\n",n,source,destination);
        count++;
        return;
    }
    tower(n-1,source,temp,destination);
    printf("Move %d disk from %c to %c\n",n,source,destination);
    count++;
    tower(n-1,temp,destination,source);
}

int main()
{
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    tower(n,'a','c','b');
    printf("The total number of moves = %d",count);
    return 0;
}