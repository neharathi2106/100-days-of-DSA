#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    size++;
    heap[size] = x;

    int i = size;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && heap[left] < heap[smallest])
        smallest = left;

    if (right <= size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin() {
    if (size == 0)
        return -1;

    int min = heap[1];
    heap[1] = heap[size];
    size--;

    heapify(1);
    return min;
}

int peek() {
    if (size == 0)
        return -1;
    return heap[1];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'p') {
            printf("%d\n", peek());
        } else {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}