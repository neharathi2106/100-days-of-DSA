#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Deque Overflow\n");
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else if(front==0)
        {
            front=MAX-1;
        }
        else
        {
            front--;
        }
        deque[front]=x;
    }
}

void push_back(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Deque Overflow\n");
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==MAX-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        deque[rear]=x;
    }
}

void pop_front()
{
    if(front==-1)
        printf("Deque Underflow\n");
    else
    {
        printf("Deleted from front: %d\n", deque[front]);

        if(front==rear)
            front=rear=-1;
        else if(front==MAX-1)
            front=0;
        else
            front++;
    }
}

void pop_back()
{
    if(front==-1)
        printf("Deque Underflow\n");
    else
    {
        printf("Deleted from rear: %d\n", deque[rear]);

        if(front==rear)
            front=rear=-1;
        else if(rear==0)
            rear=MAX-1;
        else
            rear--;
    }
}

void display()
{
    int i=front;

    if(front==-1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    while(i!=rear)
    {
        printf("%d ", deque[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n", deque[rear]);
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_back();
    display();

    pop_front();
    display();

    return 0;
}