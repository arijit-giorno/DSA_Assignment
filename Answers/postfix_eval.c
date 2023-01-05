#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50
int stack[MAX];
char post[MAX];
int top = -1;
void push(int temp)
{
    stack[++top] = temp - 48;
}
int pop()
{
    return stack[top--];
}
void calculate(char ch)
{
    int a, b, ans;
    a = pop();
    b = pop();
    switch (ch)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    case '^':
        ans = pow(a, b);
        break;
    default:
        printf("invalid operator ");
        break;
    }
    stack[++top]=ans;
}
int main()
{
    int i = 0;
    printf("enter your postfix equation : ");
    scanf("%[^\n]s", post);
    while (post[i] != '\0')
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            push(post[i]);
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
        {
            calculate(post[i]);
        }
        i++;
    }
    printf(" the solution is %d", stack[top--]);
}