#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coef = c;
    node->exp = e;
    node->next = NULL;
    return node;
}

struct Node* insert(struct Node* head, int c, int e) {
    struct Node* node = createNode(c, e);

    if (head == NULL)
        return node;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = node;
    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp) {
        if (temp->exp == 0)
            printf("%d", temp->coef);
        else if (temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if (temp->next)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printPolynomial(head);

    return 0;
}