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

void topoSort(int V, struct Node* adj[]) {
    int indegree[V];

    for (int i = 0; i < V; i++)
        indegree[i] = 0;

    // calculate indegree
    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    // queue
    int queue[V];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;

            temp = temp->next;
        }
    }

    // check cycle
    if (count != V)
        printf("\nCycle exists (Topological sort not possible)");
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

    topoSort(V, adj);

    return 0;
}