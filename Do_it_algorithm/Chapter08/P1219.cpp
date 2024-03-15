#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits>
using namespace std;

#define MINUS_INF numeric_limits<long long int>::min()

bool IsReachable(vector<tuple<int, int, int>>& graph, int numNode, int start, int end);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCity, source, destination, numInfo;
    cin >> numCity >> source >> destination >> numInfo;

    vector<tuple<int, int, int>> graph;
    vector<long long int> budget(numCity, MINUS_INF);
    vector<int> benefits(numCity);

    for (int _ = 0; _ < numInfo; _++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        graph.push_back(make_tuple(src, dest, -cost));
    }
    
    for (int i = 0; i < numCity; i++)
        cin >> benefits[i];
    
    for (tuple<int, int, int>& edge : graph)
        get<2>(edge) += benefits[get<1>(edge)];

    if (benefits[source] > 0)
        budget[source] = benefits[source];
    else
        budget[source] = 0;
    
    for (int _ = 0; _ < numCity - 1; _++) {
        for (tuple<int, int, int> edge : graph) {
            int src = get<0>(edge), dest = get<1>(edge), earn = get<2>(edge);

            if (budget[src] != MINUS_INF && budget[src] + earn > budget[dest])
                budget[dest] = budget[src] + earn;
        }
    }
    
    bool isCycle = false;
    for (tuple<int, int, int> edge : graph) {
        int src = get<0>(edge), dest = get<1>(edge), earn = get<2>(edge);

        if (budget[src] != MINUS_INF && budget[src] + earn > budget[dest] && IsReachable(graph, numCity, dest, destination)) {
            isCycle = true;
            break;
        }
    }

    if (budget[destination] == MINUS_INF)
        cout << "gg";
    else if (isCycle)
        cout << "Gee";
    else
        cout << budget[destination];

    return 0;
}

bool IsReachable(vector<tuple<int, int, int>>& graph, int numNode, int start, int end) {
    vector<bool> visited(numNode, false);
    queue<int> q;
    
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (tuple<int, int, int> edge : graph) {
            int src = get<0>(edge), dest = get<1>(edge);
            if (src == curr && !visited[dest]) {
                if (dest == end) return true;
                
                visited[dest] = true;
                q.push(dest);
            }
        }
    }

    return false;
}