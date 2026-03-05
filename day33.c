#include <stdio.h>
#include <ctype.h>

int precedence(char op)
{
    if(op == '*')
        return 2;
    if(op == '+')
        return 1;
    return 0;
}

int main()
{
    char infix[100], stack[100];
    int top = -1;

    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            printf("%c", ch);
        }
        else
        {
            while(top >= 0 && precedence(stack[top]) >= precedence(ch))
            {
                printf("%c", stack[top]);
                top--;
            }

            top++;
            stack[top] = ch;
        }
    }

    while(top >= 0)
    {
        printf("%c", stack[top]);
        top--;
    }

    return 0;
}