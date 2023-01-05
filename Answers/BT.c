#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
} stree;
stree *create(int val)
{
    stree *new = (stree *)malloc(sizeof(stree));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}
stree *insert(stree *tree, int val)
{
    if (tree == NULL)
    {
        return create(val);
    }
    if (tree->val == val)
    {
        printf("element already exist ");
        return 0;
    }
    else if (val > tree->val)
    {
        tree->right = insert(tree->right, val);
    }
    else
    {
        tree->left = insert(tree->left, val);
    }
    return tree;
}

void inorder(stree *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
}
void postorder(stree *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->val);
    }
}
void preorder(stree *node)
{
    if (node != NULL)
    {
        printf("%d ", node->val);
        preorder(node->left);
        preorder(node->right);
    }
}
int main()
{
    int choice, val, choice1;
    stree *tree = NULL;
    while (1)
    {
        printf("\nType 1 for insert\nType 2 for traverse\nFor exit type 3 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value : ");
            scanf("%d", &val);
            tree = insert(tree, val);
            break;
        case 2:
            printf("\n  Type 1 for inorder\n  Type 2 for postorder\n  Type 3 for preorder : ");
            scanf("%d", &choice1);
            printf("Tree elements are :> ");
            switch (choice1)
            {
            case 1:
                inorder(tree);
                break;
            case 2:
                postorder(tree);
                break;
            case 3:
                preorder(tree);
                break;
            default:
                printf("\ninvalid input");
            }
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