#include <bits/stdc++.h>
using namespace std;

#define NONE    -1
#define INF     1000000000

int N, M, K;
vector<vector<int>> graph;
vector<vector<int>> table;

int DFS(int passed, int curr);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    while (K--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a >= b) continue;
        graph[a][b] = max(graph[a][b], c);
    }

    table.resize(N + 1, vector<int>(N + 1, NONE));
    cout << DFS(1, 1);

    return 0;
}

int DFS(int passed, int curr) {
    if (passed > M)
        return -INF;
    else if (curr > N)
        return -INF;
    else if (curr == N)
        return 0;

    int& ret = table[passed][curr];
    if (ret != NONE)
        return ret;

    ret = -INF;
    for (int i = curr + 1; i <= N; i++)
        if (graph[curr][i])
            ret = max(ret, DFS(passed + 1, i) + graph[curr][i]);

    return ret;
}