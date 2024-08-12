#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> disjointSet;

inline void Union(int v1, int v2) {
    stack<int> s1, s2;

    while (disjointSet[v1] != v1) {
        s1.push(v1);
        v1 = disjointSet[v1];
    }

    while (disjointSet[v2] != v2) {
        s2.push(v2);
        v2 = disjointSet[v2];
    }

    while (!s1.empty()) {
        disjointSet[s1.top()] = v1;
        s1.pop();
    }
    while (!s2.empty()) {
        disjointSet[s2.top()] = v1;
        s2.pop();
    }

    disjointSet[v2] = v1;
}

inline bool Find(int v1, int v2) {
    while (v1 != disjointSet[v1])
        v1 = disjointSet[v1];
    while (v2 != disjointSet[v2])
        v2 = disjointSet[v2];

    return (v1 == v2);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    disjointSet.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        disjointSet[i] = i;

    while (M--) {
        int x, y;
        cin >> x >> y;
        for (int i = x + 1; i <= y; i++)
            if (!Find(x, i)) {
                N--;
                Union(x, i);
            }
    }

    cout << N;

    return 0;
}