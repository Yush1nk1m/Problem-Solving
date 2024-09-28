/**
 * @file 17182_FloydWarshall.cpp
 * @brief 00:09:55
 * @date 2024-09-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, K, result = INF;
vector<vector<int>> graph;
vector<int> sequence;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    graph.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> graph[r][c];

    for (int k = 0; k < N; k++)
        for (int s = 0; s < N; s++)
            for (int e = 0; e < N; e++)
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);

    for (int i = 0; i < N; i++)
        if (i != K)
            sequence.push_back(i);
    
    do {
        int curr = K, dist = 0;
        for (int nxt : sequence) {
            dist += graph[curr][nxt];
            curr = nxt;
        }
        result = min(result, dist);
    } while (next_permutation(sequence.begin(), sequence.end()));

    cout << result;

    return 0;
}