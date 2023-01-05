#include <stdio.h>
#include <stdlib.h>

// array travel
void travel(int arr[], int n)
{
    printf("array elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// insert element in a index
void insert(int arr[], int size, int val, int index)
{

    int i;
    for (i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = val;
}

// delete element with their index
void delete (int arr[], int size, int index)
{
    int i;
    for (i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
            break;
        }
    }
    return -1;
}

void replace(int arr[], int index, int val)
{
    arr[index] = val;
}

// main function
int main()
{
    int choise, choise2, index, val, n, arr[50];
    int i, choise3, e, element;
    printf("enter your array size ");
    scanf("%d", &n);
    printf("enter your array elements ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("-------------\nFor insertion type 1\nFor deletation type 2\nFor search type 3\nFor replacing type 4\nFor traverse type 5: ");
    scanf("%d", &choise);
    switch (choise)
    {
    case 1:
        printf("---------------------\n");
        printf("For insertion at first enter 1\nFor insertion at an index enter 2\nFor insertion at last enter 3 :");
        scanf("%d", &choise2);
        switch (choise2)
        {
        case 1:
            printf("enter  value ");
            scanf("%d", &val);
            travel(arr, n);
            insert(arr, n, val, 0);
            travel(arr, n + 1);
            break;
        case 2:
            printf("enter index and value ");
            scanf("%d%d", &index, &val);
            travel(arr, n);
            insert(arr, n, val, index);
            travel(arr, n + 1);
            break;
        case 3:
            printf("enter value ");
            scanf("%d", &val);
            insert(arr, n, val, n);
            travel(arr, n + 1);
            break;
        default:
            printf("invalid choise");
            break;
        }

        break;
    case 2:

        printf("----------------\nEnter 1 for delete from beginning\nEnter 2 for delete at a position\nEnter 3 for delete from end: ");
        scanf("%d", &choise3);
        switch (choise3)
        {
        case 1:
            delete (arr, n, 0);
            break;
        case 2:
            printf("enter position which you want to delete :");
            scanf("%d", &index);
            delete (arr, n, index - 1);
            break;
        case 3:
            delete (arr, n, n - 1);
            break;
        default:
            printf("invalid choise ");
            break;
        }
        travel(arr, n - 1);

        break;
    case 3:

        printf("which element u want to search: ");
        scanf("%d", &element);
        e = search(arr, n, element);
        if (e == -1)
        {
            printf("Element is not found in array");
        }
        else
        {
            printf("Element %d is found in index %d", element, e);
        }
        break;
    case 4:

        printf("Enter the position and element you want to replace ");
        scanf("%d%d", &index, &val);
        replace(arr, index - 1, val);
        travel(arr, n);
        break;
    case 5:
        travel(arr, n);
        break;
    default:
        printf("invalid input");
        break;
    }
    return 0;
}