#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int f = -1;
int r = -1;
int arr[MAX];
int isempty()
{
    if (f == -1)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if ((r + 1) % MAX == f)
    {
        return 1;
    }
    return 0;
}
void cenque(char val)
{
    if (isfull())
    {
        printf("stack is full");
    }
    else
    {
        r = (r + 1) % MAX;
        arr[r] = val;
    }
    if (f == -1)
    {
        f++;
    }
}
int cdelque()
{
    int val;
    if (isempty())
    {
        printf("stack is empty\n ");
        return -1;
    }

    val = arr[f];
    if (f == r)
    {
        f = r = -1;
    }
    else
    {
        f = (f + 1) % MAX;
    }
    return val;
}
void display()
{
    int i = f;
    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\nArray element ");
        while (i != r)
        {
            printf("%d ", arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", arr[i]);
    }
}
int main()
{
    int val, n;
    int choice, num;
    while (1)
    {
        printf("\nType 1 for cenqueue\nType 2 for cdelque\nType 3 for display\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be enqueued :");
            scanf("%d", &val);
            cenque(val);
            break;
        case 2:
            n = cdelque();
            if (n != -1)
            {
                printf("delqueued element is %d\n", n);
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
