#include <iostream>
#include <stack>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

void Union(vector<int>& set, int a, int b);
bool Find(vector<int>& set, int a, int b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<tuple<int, int, int>> graph;
    vector<int> set(N);
    for (int i = 0; i < N; i++)
        set[i] = i;

    int total_length = 0;
    for (int start = 0; start < N; start++) {
        string line;
        cin >> line;

        for (int end = 0; end < N; end++) {
            if ('a' <= line[end] && line[end] <= 'z') {
                total_length += line[end] - 'a' + 1;
                graph.push_back(make_tuple(line[end] - 'a' + 1, start, end));
            }
            else if ('A' <= line[end] && line[end] <= 'Z') {
                total_length += line[end] - 'A' + 27;
                graph.push_back(make_tuple(line[end] - 'A' + 27, start, end));
            }
        }
    }

    sort(graph.begin(), graph.end());

    int count = 0;
    int weight = 0;
    for (tuple<int, int, int>& edge : graph) {
        int w = get<0>(edge), cpt1 = get<1>(edge), cpt2 = get<2>(edge);
        if (!Find(set, cpt1, cpt2)) {
            count++;
            weight += w;
            Union(set, cpt1, cpt2);
        }
    }

    if (count >= N - 1)
        cout << (total_length - weight);
    else
        cout << -1;

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
    }
    else {
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