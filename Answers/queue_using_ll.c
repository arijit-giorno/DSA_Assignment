#include <stdio.h>
#include <stdlib.h>
typedef struct queue_using_ll
{
    int val;
    struct queue_using_ll *next;
} qnode;
qnode *front = NULL;
qnode *rear = NULL;
void travel()
{
    qnode *ptr = front;
    printf("------element is :");
    while (ptr != NULL)
    {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
}
void enque(int val)
{
    qnode *new = (qnode *)malloc(sizeof(qnode));
    if (new == NULL)
    {
        printf("queue is full");
    }
    new->val = val;
    new->next = NULL;
    if (front == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}
void deque()
{
    if (front == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        qnode *p = front;
        front = front->next ;
        printf("%d is dequed", p->val);
        free(p);
    }
}
int main()
{
    int val, choice; 
    while (1)
    {
        printf("\nType 1 for equeue\nType 2 for dequeue\nType 3 for display\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &val);
            enque(val);
            break;
        case 2:
            deque();
            break;
        case 3:
            travel();
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