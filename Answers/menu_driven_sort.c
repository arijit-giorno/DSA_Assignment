#include <stdio.h>
#include <stdlib.h>
void bubblesort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("sorted array > ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectionsort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("sorted array > ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertsort(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
    printf("sorted array > ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void merging(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, temp[30];
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
void marge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        marge_sort(arr, low, mid);
        marge_sort(arr, mid + 1, high);
        merging(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high)
{
    int i = low, j = high, k = low, temp;
    while (i < j)
    {
        while (arr[k] >= arr[i])
        {
            i++;
        }
        while (arr[k] < arr[j])
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[k];
    arr[k] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    int part;
    if (low < high)
    {
        part = partition(arr, low, high);
        quick_sort(arr, low, part - 1);
        quick_sort(arr, part + 1, high);
    }
}
int main()
{
    int arr[20];
    int choice, n;
    printf("enter size of array ");
    scanf("%d", &n);
    printf("Enter array element ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nType 1 for bubble sort\nType 2 for selection sort\nType 3 for insertion sort\nType 4 for merge sort\ntype 5 for quick sort\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            bubblesort(arr, n);
            break;
        case 2:
            selectionsort(arr, n);
            break;
        case 3:
            insertsort(arr, n);
            break;
        case 4:
            marge_sort(arr, 0, n - 1);
            printf("sorted array > ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            break;
        case 5:
            quick_sort(arr, 0, n - 1);
            printf("sorted array > ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            break;
        case 6:
            exit(0);
        default:
            printf("\ninvalid input");
            break;
        }
    }

    return 0;
}