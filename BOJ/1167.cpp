#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int V;
vector<vector<pair<int, int>>> adj_list_graph;
vector<int> sizes;
vector<bool> visited;

inline pair<int, int> DFS(int s) {
    stack<int> stk;
    map<int, int> distances;    // 어떤 정점 v를 방문했을 때 이동한 거리 d를 v -> d로 매핑
    int max_distance = 0, max_vertex;

    distances[s] = 0;
    stk.push(s);

    while (!stk.empty()) {
        int curr_vertex = stk.top();
        stk.pop();

        visited[curr_vertex] = true;

        for (int i = 0; i < sizes[curr_vertex]; i++) {
            int next_vertex = adj_list_graph[curr_vertex][i].first;
            int dist = adj_list_graph[curr_vertex][i].second;
            
            if (!visited[next_vertex]) {
                distances[next_vertex] = distances[curr_vertex] + dist;
                stk.push(next_vertex);

                if (distances[next_vertex] > max_distance) {
                    max_distance = distances[next_vertex];
                    max_vertex = next_vertex;
                }
            }
        }
    }

    return {max_vertex, max_distance};
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> V;

    visited.resize(V + 1, false);
    adj_list_graph.resize(V + 1);
    sizes.resize(V + 1);

    for (int _ = 0; _ < V; _++) {
        int s, e, dist;
        cin >> s;

        int size = 0;
        while (1) {
            cin >> e;
            if (e == -1) break;
            cin >> dist;
            size++;

            adj_list_graph[s].push_back({e, dist});
        }

        sizes[s] = size;
    }
    
    pair<int, int> result = DFS(1);
    visited.assign(V + 1, false);
    result = DFS(result.first);

    cout << result.second;

    return 0;
}