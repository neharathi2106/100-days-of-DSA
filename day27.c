#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int length(struct Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int diff = abs(len1 - len2);

    if(len1 > len2)
    {
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    }
    else
    {
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    struct Node *head1 = createList(n);

    scanf("%d", &m);
    struct Node *head2 = createList(m);

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}