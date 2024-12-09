/**
 * @file 1504_FloydWarshall.cpp
 * @brief 00:08:26
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, E, v1, v2, d;
vector<vector<int>> graph;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    graph.resize(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++)
        graph[i][i] = 0;
    for (int _ = 0; _ < E; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }
    cin >> v1 >> v2;

    for (int k = 1; k <= N; k++)
        for (int s = 1; s <= N; s++)
            for (int e = 1; e <= N; e++)
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);

    d = min(graph[1][v1] + graph[v1][v2] + graph[v2][N], graph[1][v2] + graph[v2][v1] + graph[v1][N]);
    if (d >= INF)
        cout << -1;
    else
        cout << d;

    return 0;
}