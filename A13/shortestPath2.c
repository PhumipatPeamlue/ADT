#include <stdio.h>
#include <stdlib.h>

int index_minDist(int dist[], int check[], int n) {
    int MIN = 1000, MIN_index;
    int i;
    for (i=0; i<n; i++) {
        if (check[i]==0 && dist[i] <= MIN) {
            MIN = dist[i];
            MIN_index = i;
        }
    }
    return MIN_index;
}

void dijkstra(int **graph, int n, int s, int t) {
    int dist[n];
    int check[n];

    int i;
    for (i=0; i<n; i++) {
        dist[i] = 1000;
        check[i] = 0;
    }

    dist[s] = 0;
    
    for (i=0; i<n; i++) {
        int index = index_minDist(dist, check, n);
        check[index] = 1;

        int j;
        for (j=0; j<n; j++) {
            if (check[j]==0 && *(*(graph+index)+j) && dist[index]+*(*(graph+index)+j)<dist[j]) {
               dist[j] = dist[index] + *(*(graph + index) + j);
            }
        }
    }
    
    if (dist[t] == 1000) printf("-1\n");
    else printf("%d\n", dist[t]);
}

int main(void) {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    
    int **graph = (int**)malloc(sizeof(int*) * n);
    int i;
    for (i=0; i<n; i++) {
        *(graph + i) = (int*)malloc(sizeof(int) * n);
    }

    int u, v, w;
    for (i=0; i<m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        *(*(graph + u) + v) = w;
        *(*(graph + v) + u) = w;
    }

    int s, t;
    for (i=0; i<p; i++) {
        scanf("%d %d", &s, &t);
        dijkstra(graph, n, s, t);
    }

    return 0;
}
