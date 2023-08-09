#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int V;
long long curr_distance, max_distance;

inline int searchRelation(int begin, int end) {
    int result = 0;
    int left = 0, right = graph[begin].size();

    while (left <= right) {
        int mid = (left + right) / 2;

        if (graph[begin][mid].first > end) {
            right = mid - 1;
        }
        else if (graph[begin][mid].first < end) {
            left = mid + 1;
        }
        else {
            result = graph[begin][mid].second;
            break;
        }
    }

    return result;
}

inline int DFS(int vertex) {
    max_distance = 0;
    curr_distance = 0;
    
    int result_node;

    stack<int> Vstack;
    stack<int> recent_distances;

    Vstack.push(vertex);
    visited[vertex] = true;
    while (!Vstack.empty()) {
        int curr = Vstack.top();

        bool added = false;
        for (int neighbor = 1; neighbor <= V; neighbor++) {
            if (!visited[neighbor] && (dist = searchRelation(curr, neighbor)) > 0) {
                added = true;
                visited[neighbor] = true;
                Vstack.push(neighbor);

                curr_distance += dist;
                recent_distances.push(dist);

                if (curr_distance > max_distance) {
                    max_distance = curr_distance;
                    result_node = neighbor;
                }
                
                break;
            }
        }

        if (!added) Vstack.pop();
    }

    return result_node;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> V;
    graph.resize(V + 1);
    visited.resize(V + 1, false);

    for (int _ = 1; _ <= V; _++) {
        int begin_v, end_v, distance;
        
        cin >> begin_v;
        while (1) {
            cin >> end_v;
            if (end_v == -1) break;
            cin >> distance;

            graph[begin_v].push_back({end_v, distance});
        }

        sort(graph[begin_v].begin(), graph[begin_v].end());
    }

    long long result = 0;
    for (int vertex = 1; vertex <= V; vertex++) {
        if (!visited[vertex]) {
            long long temp = DFS(vertex);
            if (temp > result) result = temp;
        }
    }

    cout << result;
    
    return 0;
}