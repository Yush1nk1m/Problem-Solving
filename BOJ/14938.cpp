#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

static int n, m, r;
static vector<int> items;
static vector<vector<int>> graph;

static inline void FloydWarshall();
static inline int GetMaximumValue();
static inline int TotalValueFromSource(int src);

static inline void PrintGraph() {
    cout << "PRINT GRAPH" << endl;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++)
            cout << graph[r][c] << ' ';
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    
    graph.resize(n + 1, vector<int>(n + 1, INF));
    items.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
        graph[i][i] = 0;
    }
    
    for (int _ = 0; _ < r; _++) {
        int a, b, l;
        cin >> a >> b >> l;

        graph[a][b] = graph[b][a] = l;
    }

    FloydWarshall();

    cout << GetMaximumValue();
    
    return 0;
}

static inline void FloydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int src = 1; src <= n; src++) {
            for (int dest = 1; dest <= n; dest++) {
                if (graph[src][dest] > graph[src][k] + graph[k][dest])
                    graph[src][dest] = graph[src][k] + graph[k][dest];
            }
        }
    }
}

static inline int GetMaximumValue() {
    int maximum = 0;
    for (int src = 1; src <= n; src++)
        maximum = max(maximum, TotalValueFromSource(src));
    return maximum;
}

static inline int TotalValueFromSource(int src) {
    int sum = 0;
    for (int dest = 1; dest <= n; dest++)
        if (graph[src][dest] <= m)
            sum += items[dest];
    return sum;
}