#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if((rear + 1) % MAX == front)
        return;

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

void dequeue()
{
    if(front == -1)
        return;

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main()
{
    int n,m,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
        dequeue();

    display();

    return 0;
}