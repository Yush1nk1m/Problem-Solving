#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<long long int>> graph(n + 1, vector<long long int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    for (int _ = 0; _ < m; _++) {
        int s, e; long long int w;
        cin >> s >> e >> w;
        graph[s][e] = min(graph[s][e], w);
    }

    for (int mid = 1; mid <= n; mid++)
        for (int start = 1; start <= n; start++)
            for (int end = 1; end <= n; end++)
                graph[start][end] = min(graph[start][end], graph[start][mid] + graph[mid][end]);

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (graph[r][c] == INF)
                cout << 0 << " ";
            else
                cout << graph[r][c] << " ";
        }
        cout << '\n';
    }

    return 0;
}