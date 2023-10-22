#include <iostream>
#include <vector>

const int INF = INT_MAX;

void dijkstra(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, INF);
    std::vector<bool> visited(n, false);

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INF, minIndex;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INF && dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; i++) {
        std::cout << "Shortest distance from node " << start << " to node " << i << " is " << dist[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4
