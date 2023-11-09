#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 99999999

inline void dijkstra(int target, vector<int>& dist_table, vector<vector<pair<int, int>>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, target});

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_distance = pq.top().first;
        pq.pop();

        if (dist_table[curr_node] < curr_distance) continue;
        else {
            for (int i = 0; i < graph[curr_node].size(); i++) {
                int neighbor = graph[curr_node][i].second;
                int neighbor_dist = curr_distance + graph[curr_node][i].first;

                if (dist_table[neighbor] > neighbor_dist) {
                    dist_table[neighbor] = neighbor_dist;
                    pq.push({neighbor_dist, neighbor});
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int num_of_people, num_of_edges, party_village;
    cin >> num_of_people >> num_of_edges >> party_village;

    // first element of the pair means the distance, second element of the pair means the node
    vector<vector<pair<int, int>>> graph(num_of_people + 1);
    vector<vector<int>> distance_table(num_of_people + 1, vector<int>(num_of_people + 1, INF));
    for (int i = 1; i <= num_of_people; i++)
        distance_table[i][i] = 0;

    for (int _ = 0; _ < num_of_edges; _++) {
        int start, end, time;
        cin >> start >> end >> time;

        graph[start].push_back({time, end});
    }
    
    for (int node = 1; node <= num_of_people; node++)
        dijkstra(node, distance_table[node], graph);

    int max_dist = 0;
    for (int node = 1; node <= num_of_people; node++) {
        if (max_dist < distance_table[node][party_village] + distance_table[party_village][node])
            max_dist = distance_table[node][party_village] + distance_table[party_village][node];
    }

    cout << max_dist;

    return 0;
}