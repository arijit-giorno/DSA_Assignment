#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int top = -1;
int arr[MAX];
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return 0;
}
void push(int val)
{
    if (isfull())
    {
        printf("stack is full");
    }
    else
    {
        top++;
        arr[top] = val;
    }
}
int pop()
{
    int val;
    if (isempty())
    {
        printf("stack is empty\n ");
        return -1;
    }

    val = arr[top];
    top--;
    return val;
}
void display()
{
    int i, n;
    if (isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("\nArray element ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
int main()
{
    int val, choice, num, n;
    while (1)
    {
        printf("\nType 1 for push\nType 2 for pop\nType 3 for display\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            n = pop();
            if (n != -1)
            {
                printf("Poped element is %d\n", n);
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
