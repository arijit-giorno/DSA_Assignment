#include <stdio.h>
#include <stdlib.h>
void interpolison(int arr[], int n, int x)
{
    int f, l, mid, i = 0;
    f = 0;
    l = n - 1;
    while (f <= l )
    {
        mid = f + (double)(l - f) * (x - arr[f]) / (arr[l] - arr[f]);

        if (arr[mid] == x)
        {
            printf("--Element %d is found in index %d", x, mid);
            break;
        }
        else if (arr[mid] > x)
        {
            l = mid - 1;
        }
        else
        {
            f = mid + 1;
        }
        i++;
    }
    printf("\nnumber of iteration requierd %d ", i);
    if (f > l)
    {
        printf("Element is not found in array");
    }
}
void binarysearch(int arr[], int n, int x)
{
    int f, l, mid, i = 0;
    f = 0;
    l = n - 1;
    mid = (f + l) / 2;
    while (f <= l)
    {

        if (arr[mid] == x)
        {
            printf("--Element %d is found in index %d", x, mid);
            break;
        }
        else if (arr[mid] > x)
        {
            l = mid - 1;
        }
        else
        {
            f = mid + 1;
        }
        mid = (f + l) / 2;
        i++;
    }
    printf("\nnumber of iteration requierd %d ", i);
    if (f > l)
    {
        printf("Element is not found in array");
    }
}
int main()
{
    int arr[20];
    int choice, n, x;
    printf("enter size of array ");
    scanf("%d", &n);
    printf("Enter array element ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Which element you want to find : ");
    scanf("%d", &x);
    while (1)
    {
        printf("\nType 1 for binary\nType 2 for interpolition\nFor exit type 3 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            binarysearch(arr, n, x);
            break;
        case 2:
            interpolison(arr, n, x);
            break;
        case 3:
            exit(0);
        default:
            printf("\ninvalid input");
            break;
        }
    }

    return 0;
}