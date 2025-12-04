#include <iostream>
#include <climits>
using namespace std;

const int N = 4;
const int INF = INT_MAX;

void dijkstra(int src, int graph[N][N]) {
    int dist[N];
    bool used[N];

    for(int i = 0; i < N; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count < N - 1; count++) {
        int u = -1;
        int best = INF;
        for(int i = 0; i < N; i++) {
            if(!used[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if(u == -1) break;
        used[u] = true;

        for(int v = 0; v < N; v++) {
            if(graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from " << src << ":\n";
    for(int i = 0; i < N; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int graph[N][N] = {
        {0, 4, 1, 0},
        {0, 0, 0, 1},
        {0, 2, 0, 5},
        {0, 0, 0, 0}
    };

    dijkstra(0, graph);
    return 0;
}
