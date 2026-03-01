#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

struct Node* rotateRight(struct Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    int length = 1;
    struct Node* tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if(k == 0)
        return head;

    tail->next = head;

    int steps = length - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}