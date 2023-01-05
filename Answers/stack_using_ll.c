#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} snode;
void travel(snode *ptr) // travel all element all variable
{
    printf("------element is :");
    while (ptr != NULL)
    {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
}

snode *push(snode *ptr, int val)
{
    snode *new = (snode *)malloc(sizeof(snode));
    if (new == NULL)
    {
        printf("stack is full");
        return NULL;
    }
    new->val = val;
    new->next = ptr;
    return new;
}
snode *pop(snode *ptr)
{
    if (ptr != NULL)
    {
        snode *p = ptr;
        printf("%d is poped out",ptr->val);
        ptr = ptr->next;
        free(p);
        return ptr;
    }
    printf("stack is empty");
}
int main()
{
    int val, choice;
    snode *node = NULL;
    while (1)
    {
        printf("\nType 1 for push\nType 2 for pop\nType 3 for display\nFor exit type 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &val);
            node=push(node, val);
            break;
        case 2:
            node=pop(node);
            break;
        case 3:
            travel(node);
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