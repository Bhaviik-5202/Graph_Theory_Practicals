#include <stdio.h>

int n, m;
int adj[20][20];
int visited[20];

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, u, v;
    int degree[20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\n1. Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\n2. Adjacency List:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        for (j = 0; j < n; j++) {
            if (adj[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\n3. Degree of each vertex:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            degree[i] += adj[i][j];
        }
        printf("Degree(%d) = %d\n", i, degree[i]);
    }

    int simple = 1;
    for (i = 0; i < n; i++) {
        if (adj[i][i]) {
            simple = 0;
            break;
        }
    }

    int complete = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && !adj[i][j]) {
                complete = 0;
                break;
            }
        }
    }

    dfs(0);
    int connected = 1;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    printf("\n4. Graph Properties:\n");
    printf("Simple Graph    : %s\n", simple ? "Yes" : "No");
    printf("Complete Graph  : %s\n", complete ? "Yes" : "No");
    printf("Connected Graph : %s\n", connected ? "Yes" : "No");

    printf("\n5. Total Vertices and Edges:\n");
    printf("Total Vertices = %d\n", n);
    printf("Total Edges    = %d\n", m);

    return 0;
}
