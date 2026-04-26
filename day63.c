#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int s;
    scanf("%d", &s);

    dfs(s, adj, visited);

    return 0;
}