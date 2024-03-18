#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

void Union(vector<int>& set, int a, int b);
bool Find(vector<int>& set, int a, int b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<tuple<int, int, int>> graph;
    vector<int> set(V + 1);
    for (int i = 1; i <= V; i++)
        set[i] = i;

    for (int _ = 0; _ < E; _++) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;

        graph.push_back(make_tuple(weight, vertex1, vertex2));
    }

    sort(graph.begin(), graph.end());

    int count = 0;
    int weight = 0;
    int i = 0;
    while (count < V - 1) {
        tuple<int, int, int> edge = graph[i++];
        int w = get<0>(edge), v1 = get<1>(edge), v2 = get<2>(edge);

        if (!Find(set, v1, v2)) {
            count++;
            weight += w;
            Union(set, v1, v2);
        }
    }

    cout << weight;

    return 0;
}

void Union(vector<int>& set, int a, int b) {
    while (a != set[a])
        a = set[a];
    
    while (b != set[b])
        b = set[b];

    set[b] = a;
}

bool Find(vector<int>& set, int a, int b) {
    stack<int> nonRootA, nonRootB;

    while (a != set[a]) {
        nonRootA.push(a);
        a = set[a];
    }

    while (b != set[b]) {
        nonRootB.push(b);
        b = set[b];
    }

    if (a != b) {
        while (!nonRootA.empty()) {
            set[nonRootA.top()] = a;
            nonRootA.pop();
        }

        while (!nonRootB.empty()) {
            set[nonRootB.top()] = b;
            nonRootB.pop();
        }

        return false;
    } else {
        while (!nonRootA.empty()) {
            set[nonRootA.top()] = a;
            nonRootA.pop();
        }

        while (!nonRootB.empty()) {
            set[nonRootB.top()] = a;
            nonRootB.pop();
        }

        set[b] = a;

        return true;
    }
}