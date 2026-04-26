#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Edge {
    int to, weight;
    struct Edge* next;
};

struct Edge* adj[MAX];

// create edge
struct Edge* createEdge(int to, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->to = to;
    e->weight = w;
    e->next = NULL;
    return e;
}

// add edge
void addEdge(int u, int v, int w) {
    struct Edge* e = createEdge(v, w);
    e->next = adj[u];
    adj[u] = e;
}

// Min Heap Node
struct Node {
    int vertex, dist;
};

struct Node heap[MAX];
int size = 0;

// swap
void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i) {
    while (i && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size++);
}

// pop min
struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

// Dijkstra
void dijkstra(int V, int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct Node curr = pop();
        int u = curr.vertex;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    for (int i = 0; i < V; i++) {
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0,1,2);
    addEdge(0,2,4);
    addEdge(1,2,1);
    addEdge(1,3,7);
    addEdge(2,4,3);
    addEdge(3,4,1);

    dijkstra(V, 0);

    return 0;
}