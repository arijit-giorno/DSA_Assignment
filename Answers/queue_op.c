#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int f,r = -1;
char arr[MAX];
int isempty()
{
    if (f==-1 && f>r)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if (r == MAX - 1)
    {
        return 1;
    }
    return 0;
}
void push(char val)
{
    if (isfull())
    {
        printf("stack is full");
    }
    else
    {
        r++;
        arr[r] = val;
    }
    if (f==-1)
    {
        f++;
    }
    
}
char pop()
{
   char val;
    if (isempty())
    {
        printf("stack is empty\n ");
        return -1;
    }

    val = arr[f];
    f++;
    return val;
}
void display()
{
    int i;
    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Array element ");
        for (i = f; i <= r; i++)
        {
            printf("%c ", arr[i]);
        }
    }
}
int main()
{
    char val, n;
    int choice, num;
    while (1)
    {
        printf("\nType 1 for push\nType 2 for pop\nType 3 for display\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed :");
            scanf(" %c", &val);
            push(val);
            break;
        case 2:
            n = pop();
            if (n != -1)
            {
                printf("Poped element is %c\n", n);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\ninvalid input");
            break;
        }
    }

    return 0;
}
