/**
 * @file 2629_DP.cpp
 * @brief 00:27:37
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE        -1
#define MAX_WEIGHT  150000
#define MAX_INDEX   30
#define INDEX(x)    ((MAX_WEIGHT / 2) - x)

int N, T, weight;
vector<int> v;

inline void solve();
bool DFS(int weight, int idx, vector<vector<int>>& table);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cin >> T;
    while (T--) {
        cin >> weight;
        solve();
    }

    return 0;
}

inline void solve() {
    if (*lower_bound(v.begin(), v.end(), weight) == weight) {
        cout << "Y ";
        return;
    }

    vector<vector<int>> table(MAX_WEIGHT, vector<int>(MAX_INDEX, NONE));

    if (DFS(weight, 0, table)) {
        cout << "Y ";
    } else {
        cout << "N ";
    }
}

bool DFS(int weight, int idx, vector<vector<int>>& table) {
    if (weight == 0) {
        return true;
    } else if (idx == N) {
        return false;
    }

    int& ret = table[INDEX(weight)][idx];
    if (ret != NONE) {
        return ret;
    }

    ret = DFS(weight, idx + 1, table)
        | DFS(weight + v[idx], idx + 1, table)
        | DFS(weight - v[idx], idx + 1, table);
    return ret;
}