/**
 * @file 16562_DisjointSet.cpp
 * @brief 00:47:37
 * @date 2024-11-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int N, M, k, result;
vector<int> A, disjointSet;
set<int> S;

inline void unionSet(int v1, int v2);
inline int findRoot(int v);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> k;
   
    A.resize(N + 1);
    disjointSet.resize(N + 1);
    
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    for (int i = 0; i <= N; i++)
        disjointSet[i] = i;

    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        unionSet(v, w);
    }

    for (int i = 1; i <= N; i++) {
        int root = findRoot(i);
        if (S.find(root) == S.end()) {
            k -= A[root];
            result += A[root];
            if (k < 0) {
                cout << "Oh no";
                return 0;
            }
            S.insert(root);
        }
    }
    
    cout << result;
    return 0;
}

inline void unionSet(int v1, int v2) {
    while (v1 != disjointSet[v1])
        v1 = disjointSet[v1];

    while (v2 != disjointSet[v2])
        v2 = disjointSet[v2];

    if (A[v1] < A[v2])
        disjointSet[v2] = v1;
    else
        disjointSet[v1] = v2;
}

inline int findRoot(int v) {
    while (v != disjointSet[v])
        v = disjointSet[v];

    return v;
}