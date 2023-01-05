#include <stdio.h>
#include <stdlib.h>
typedef struct linklist
{
    int val;
    struct linklist *next;
} snode;
//travel
void travel(snode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}
// insertation------------------
snode *insert_at_big(snode *ptr, int val)
{
    if (ptr == NULL)
    {
        snode *ptr = (snode *)malloc(sizeof(snode));
        ptr->val = val;
        ptr->next = NULL;
        return ptr;
    }
    snode *new = (snode *)malloc(sizeof(snode));
    new->val = val;
    new->next = ptr;
    return new;
}
snode *insert_at_end(snode *ptr, int val)
{
    snode *p = ptr;
    if (ptr == NULL)
    {
        snode *ptr = (snode *)malloc(sizeof(snode));
        ptr->val = val;
        ptr->next = NULL;
        return ptr;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    snode *new = (snode *)malloc(sizeof(snode));
    new->val = val;
    new->next = NULL;
    p->next = new;
    return ptr;
}
snode *insert_at_pos(snode *ptr, int index, int val)
{

    snode *new = (snode *)malloc(sizeof(snode));
    snode *p = ptr;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    new->next = p->next;
    new->val = val;
    p->next = new;

    return ptr;
}
//deletation----------------------
snode *delete_at_big(snode *ptr)
{
    snode *p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}
snode *delete_at_end(snode *ptr)
{
    snode *p = ptr;
    snode *q = ptr->next;
    while (q != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    return ptr;
}
snode *delete_at_pos(snode *ptr, int pos)
{
    int i = 0;
    snode *p = ptr;
    snode *q = ptr->next;
    while (i != pos - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return ptr;
}

//main func----------
int main()
{
    snode *node = NULL;
    int choice, choice2, choice3;
    int ele, index;
    while (1)
    {
        printf("\nFor insertion type 1\nFor deletation type 2\nFor traverse type 3\nFor exit type 4: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nFor insertion at first type 1\nFor insertion at end type 2\nFor insertion at position type 3: ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                printf("Emter your element :");
                scanf("%d", &ele);
                node = insert_at_big(node, ele);
                break;
            case 2:
                printf("Emter your element :");
                scanf("%d", &ele);
                node = insert_at_end(node, ele);
                break;
            case 3:
                printf("Emter your element :");
                scanf("%d", &ele);
                printf("Enter your position :");
                scanf("%d", &index);
                node = insert_at_pos(node, index, ele);
                break;
            default:
                printf("\nInvalid input");
                break;
            }
            break;
        case 2:
            printf("\nFor deletation at first type 1\nFor deletation at position type 2\nFor deletation at end type 3: ");
            scanf("%d", &choice3);
            switch (choice3)
            {
            case 1:
                node = delete_at_big(node);
                break;
            case 2:
                printf("Enter your position :");
                scanf("%d", &index);
                node = delete_at_pos(node, index);
                break;

            case 3:
                node = delete_at_end(node);
                break;
            default:
                printf("\nInvalid input");
                break;
            }
            break;
        case 3:
            printf("Elements are : ");
            travel(node);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid input");
            break;
        }
    }

    return 0;
}