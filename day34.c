#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evalRPN(char** tokens, int tokensSize) {

    struct Node* top = NULL;

    for(int i = 0; i < tokensSize; i++) {

        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0) {

            int b = pop(&top);
            int a = pop(&top);

            if(strcmp(tokens[i], "+") == 0) push(&top, a + b);
            else if(strcmp(tokens[i], "-") == 0) push(&top, a - b);
            else if(strcmp(tokens[i], "*") == 0) push(&top, a * b);
            else if(strcmp(tokens[i], "/") == 0) push(&top, a / b);

        } 
        else {
            push(&top, atoi(tokens[i]));
        }
    }

    return pop(&top);
}

int main() {

    char* tokens[] = {"2","3","1","*","+","9","-"};
    int size = 7;

    int result = evalRPN(tokens, size);

    printf("Result = %d\n", result);

    return 0;
}