#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int find_minDist(int dist[], int check[]) {
    int MIN = 1000, MIN_index;
    for (int i=0; i<SIZE; i++) {
        if (check[i]==0 && dist[i] <= MIN) {
            MIN = dist[i];
            MIN_index = i;
        }
    }
    return MIN_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[SIZE][SIZE], int start) {
    int dist[SIZE];
    int check[SIZE];

    for (int i=0; i<SIZE; i++) {
        dist[i] = 1000;
        check[i] = 0;
    }

    dist[start] = 0;

    for (int i=0; i<SIZE; i++) {
        int index = find_minDist(dist, check);

        check[index] = 1;

        for (int j=0; j<SIZE; j++) {
            if (check[j]==0 && graph[index][j] && dist[index] + graph[index][j] < dist[j]) {
                dist[j] = dist[index] + graph[index][j];
            }
        }
    }
    printSolution(dist);
}

int main(void) {
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
    return 0;
}
