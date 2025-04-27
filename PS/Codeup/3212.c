#include <stdio.h>
#include <stdlib.h>

int** graph;
int* visit;
int v, start;

void find_cycle(int node) {
    if (visit[node] == start) {
        if (node == start) {
            printf("-1\n");
            exit(EXIT_SUCCESS);
        }
        return;
    }
    visit[node] = start;
    for (int i = 1; i <= v; i++) if (graph[node][i]) find_cycle(i);
}

int main() {
    int n, from, to;
    scanf("%d %d", &v, &n);
    graph = (int**)malloc(sizeof(int*) * (v + 1));
    visit = (int*)malloc(sizeof(int) * (v + 1));
    int* count = (int*)malloc(sizeof(int) * (v + 1));
    for (int i = 1; i <= v; i++) {
        graph[i] = (int*)malloc(sizeof(int) * (v + 1));
        visit[i] = 0;
        count[i] = 0;
        for (int j = 1; j <= v; j++) graph[i][j] = 0;
    }

    for (int z = 0; z < n; z++) {
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
        count[to]++;
    }

    for (start = 1; start <= v; start++) {
        find_cycle(start);
    }

    int index;
    for (int z = 0; z < v; z++) {
        index = 0;
        while (count[++index]);
        printf("%d\n", index);
        count[index] = 999;
        for (int j = 1; j <= v; j++) if (graph[index][j]) count[j]--;
    }

    return 0;
}