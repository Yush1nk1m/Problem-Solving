/**
 * @file 11404_FloydWarshall.cpp
 * @brief 00:06:38
 * @date 2024-07-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int n, m;
vector<vector<int>> graph;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1, INF));
    for (int _ = 0; _ < m; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    for (int v = 1; v <= n; v++)
        graph[v][v] = 0;
    for (int k = 1; k <= n; k++)
        for (int s = 1; s <= n; s++)
            for (int e = 1; e <= n; e++)
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF)
                cout << "0 ";
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}