/**
 * @file 1004_Math.cpp
 * @brief 00:12:22
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int T;

inline void solve();
inline ld euclideanDistance(pair<ld, ld>& p1, pair<ld, ld>& p2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

inline void solve() {
    int n, cnt = 0;
    ld r;
    pair<ld, ld> begin, end, center;
    
    cin >> begin.first >> begin.second >> end.first >> end.second;
    cin >> n;

    for (int _ = 0; _ < n; _++) {
        cin >> center.first >> center.second >> r;
        
        int indegree = 0;
        if (euclideanDistance(center, begin) <= r)
            indegree++;
        if (euclideanDistance(center, end) <= r)
            indegree++;
        
        if (indegree == 1)
            cnt++;
    }

    cout << cnt << '\n';
}

inline ld euclideanDistance(pair<ld, ld>& p1, pair<ld, ld>& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}