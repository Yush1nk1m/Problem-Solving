#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int num_vertex, num_edge, start_vertex;
    cin >> num_vertex >> num_edge;
    cin >> start_vertex;

    vector<vector<pair<int, int>>> graph(num_vertex + 1);   // graph[begin] = { distance, end }
    vector<int> distance_table(num_vertex + 1, INF);

    for (int _ = 0; _ < num_edge; _++) {
        int begin, end, distance;
        cin >> begin >> end >> distance;

        graph[begin].push_back({distance, end});
    }

    // { distance, end }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance_table[start_vertex] = 0;
    pq.push({0, start_vertex});
    
    while (!pq.empty()) {
        int distance = pq.top().first;
        int curr_vertex = pq.top().second;
        pq.pop();

        if (distance_table[curr_vertex] < distance)
            continue;
        
        for (int i = 0; i < graph[curr_vertex].size(); i++) {
            int neighbor_distance = distance + graph[curr_vertex][i].first;
            int neighbor_vertex = graph[curr_vertex][i].second;
            
            if (neighbor_distance < distance_table[neighbor_vertex]) {
                distance_table[neighbor_vertex] = neighbor_distance;
                pq.push({neighbor_distance, neighbor_vertex});
            }
        }
    }

    for (int i = 1; i <= num_vertex; i++) {
        if (distance_table[i] != INF) cout << distance_table[i] << '\n';
        else cout << "INF\n";
    }

    return 0;
}