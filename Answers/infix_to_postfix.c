#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int top = -1;
char arr[MAX];
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
void push(char val)
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
char pop()
{
    char val;
    if (isempty())
    {
        printf("stack is empty\n ");
        return -1;
    }

    val = arr[top];
    top--;
    return val;
}
char stacktop()
{
    return arr[top];
}
int isoperator(char a)
{
    if (a == '-' || a == '*' || a == '+' || a == '/' || a == '^')
    {
        return 1;
    }
    return 0;
}
int precidence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void intopost(char infix[], int size)
{
    char postfix[size];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precidence(infix[i]) > precidence(stacktop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    while (!isempty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("%s", postfix);
    // return postfix;
}
int main()
{
    char infix[] = "a+b-c";
    int size = sizeof(infix) / sizeof(char);
    printf("%s\n", infix);
    intopost(infix,size);
    // char* postfix=intopost(infix,size);
    // printf("%s", intopost(infix, size));
    return 0;
}