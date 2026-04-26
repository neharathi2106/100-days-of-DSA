#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

void dfs(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int V = 6;

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int stack[V], top = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // print topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}