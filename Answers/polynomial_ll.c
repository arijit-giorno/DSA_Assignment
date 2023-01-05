#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int exp;
    int coff;
    struct poly *next;
} spoly;
void display(spoly *ptr)
{
    if (ptr == NULL)
    {
        printf("no equation ");
    }
    else
    {
        spoly *temp = ptr;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coff, temp->exp);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}
// spoly *add(spoly *ptr, int coff, int exp)
// {
//     spoly *p = ptr;
//     if (ptr == NULL)
//     {
//         spoly *ptr = (spoly *)malloc(sizeof(spoly));
//         ptr->exp = exp;
//         ptr->coff = coff;
//         ptr->next = NULL;
//         return ptr;
//     }
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     spoly *new = (spoly *)malloc(sizeof(spoly));
//     new->exp = exp;
//     new->coff = coff;
//     new->next = NULL;
//     p->next = new;
//     return ptr;
// }
spoly *insert(spoly *ptr, int coff, int exp)
{
    spoly *temp;
    spoly *new = (spoly *)malloc(sizeof(spoly));
    new->coff = coff;
    new->exp = exp;
    new->next = NULL;
    if (ptr == NULL || exp > ptr->exp)
    {
        new->next = ptr;
        ptr = new;
    }
    else
    {
        temp = ptr;
        while (temp->next != NULL && temp->next->exp > exp)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return ptr;
}
spoly *create(spoly *ptr)
{
    int i, n, exp, coff;
    printf("enter the size of polynomial ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter cofficient of %dth term ", i + 1);
        scanf("%d", &coff);
        printf("enter exponent of %dth term ", i + 1);
        scanf("%d", &exp);
        ptr = insert(ptr, coff, exp);
    }
    return ptr;
}
spoly *addpoly(spoly *p1, spoly *p2, spoly *p3)
{
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            p3 = insert(p3, p1->coff + p2->coff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            p3 = insert(p3, p1->coff, p1->exp);
            p1 = p1->next;
        }
        else
        {
            p3 = insert(p3, p2->coff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p2 != NULL)
    {
        p3 = insert(p3, p2->coff, p2->exp);
        p2 = p2->next;
    }

    while (p1 != NULL)
    {
        p3 = insert(p3, p1->coff, p1->exp);
        p1 = p1->next;
    }

    return p3;
}
int main()
{
    spoly *p1 = NULL;
    spoly *p2 = NULL;
    spoly *p3 = NULL;
    printf("Enter first polynomial :------\n");
    p1 = create(p1);
    printf("Enter second polynomial :------\n");
    p2 = create(p2);
    p3 = addpoly(p1, p2, p3);
    display(p1);
    display(p2);
    display(p3);
    return 0;
}
