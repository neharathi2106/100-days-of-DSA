#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    struct Node* ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);

    return 0;
}