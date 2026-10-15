#include <stdio.h>

int main() {
    int n, m, i, j;
    int u, v;
    int adj[20][20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        for (j = 0; j < n; j++) {
            if (adj[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
