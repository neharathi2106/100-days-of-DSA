#include <stdio.h>

int main()
{
    int n, m;
    int stack[100];
    int top = -1;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++)
    {
        if(top >= 0)
            top--;
    }
    
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    
    return 0;
}