/**
 * @file 1956_FloydWarshall.cpp
 * @brief 00:08:05
 * @date 2024-07-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int V, E, minv = INF;
vector<vector<int>> graph;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    graph.resize(V + 1, vector<int>(V + 1, INF));
    for (int _ = 0; _ < E; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
        for (int s = 1; s <= V; s++)
            for (int e = 1; e <= V; e++)
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);

    for (int v = 1; v <= V; v++)
        minv = min(minv, graph[v][v]);
    
    if (minv == INF)
        cout << -1;
    else
        cout << minv;

    return 0;
}