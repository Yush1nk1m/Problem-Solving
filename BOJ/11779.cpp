#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define INF 1000000000

static int n, m;
static int source, destination;

static vector<vector<pair<int, int>>> graph;
static vector<bool> visited;
static vector<int> distances;
static vector<int> parents;
static stack<int> stk;

static inline int isNewSelectionAvailable();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    parents.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parents[i] = i;
    visited.resize(n + 1, false);
    distances.resize(n + 1, INF);
    graph.resize(n + 1);

    for (int _ = 0; _ < m; _++) {
        int src, dest, dist;
        cin >> src >> dest >> dist;
        graph[src].push_back({dist, dest});
    }

    cin >> source >> destination;

    distances[source] = 0;
    int src;
    while (1) {
        if ((src = isNewSelectionAvailable()) == 0) break;
        visited[src] = true;

        for (pair<int, int>& nPair : graph[src]) {
            int dest = nPair.second, dist = nPair.first;
            if (distances[dest] > distances[src] + dist) {
                distances[dest] = distances[src] + dist;
                parents[dest] = src;
            }
        }
    }

    int node = destination;
    while (node != source) {
        stk.push(node);
        node = parents[node];
    }
    stk.push(node);

    cout << distances[destination] << '\n';
    cout << stk.size() << '\n';
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}

static inline int isNewSelectionAvailable() {
    int minIdx = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i] && distances[minIdx] > distances[i])
            minIdx = i;
    return minIdx;
}