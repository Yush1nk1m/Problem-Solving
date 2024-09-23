/**
 * @file 1774_Graph.cpp
 * @brief 00:28:14
 * @date 2024-09-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, M;
double totalDist;
vector<pair<double, double>> coords;
priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
vector<int> disjointSet;

inline double Distance(pair<double, double> l1, pair<double, double> l2);
inline void Union(int v1, int v2);
inline bool Find(int v1, int v2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    disjointSet.resize(N + 1);
    for (int i = 1; i <= N; i++)
        disjointSet[i] = i;

    coords.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> coords[i].first >> coords[i].second;

    while (M--) {
        int u, v;
        cin >> u >> v;
        pq.push(make_tuple(0.0, u, v));
    }

    for (int i = 1; i < N; i++)
        for (int j = i + 1; j <= N; j++)
            pq.push(make_tuple(Distance(coords[i], coords[j]), i, j));

    while (!pq.empty()) {
        tuple<double, int, int> curr = pq.top();
        pq.pop();

        double dist = get<0>(curr);
        int u = get<1>(curr), v = get<2>(curr);

        if (!Find(u, v)) {
            Union(u, v);
            totalDist += dist;
        }
    }

    cout << fixed << setprecision(2) << totalDist;

    return 0;
}

inline double Distance(pair<double, double> l1, pair<double, double> l2) {
    return (sqrt(pow(l1.first - l2.first, 2) + pow(l1.second - l2.second, 2)));
}

inline void Union(int v1, int v2) {
    stack<int> stk;

    while (v1 != disjointSet[v1]) {
        stk.push(v1);
        v1 = disjointSet[v1];
    }

    while (v2 != disjointSet[v2]) {
        stk.push(v2);
        v2 = disjointSet[v2];
    }

    disjointSet[v2] = v1;
    while (!stk.empty()) {
        disjointSet[stk.top()] = v1;
        stk.pop();
    }
}

inline bool Find(int v1, int v2) {
    while (v1 != disjointSet[v1])
        v1 = disjointSet[v1];

    while (v2 != disjointSet[v2])
        v2 = disjointSet[v2];

    return (v1 == v2);
}