#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];

    // initialize
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // print distances
    for (int i = 0; i < V; i++) {
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int V = 5, E = 8;

    struct Edge edges[] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}