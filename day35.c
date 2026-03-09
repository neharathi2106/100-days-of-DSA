#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if(rear == MAX-1)
        return;

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = val;
}

void display()
{
    int i;
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main()
{
    int n,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    display();

    return 0;
}