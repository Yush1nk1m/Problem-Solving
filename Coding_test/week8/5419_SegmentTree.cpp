/**
 * @file 5419.cpp
 * @brief 00:36:35
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INDEX(x)    (x + idx - 1)

class Island {
    public:
        int x;
        int y;
        bool operator<(const Island& i) {
            if (x == i.x)
                return (y > i.y);
            return (x < i.x);
        }
};

int t, n, ymax, i, height, idx;

inline ll Solve(int n);
inline void Update(vector<ll>& tree, int y, ll value);
inline ll Sum(vector<ll>& tree, int from, int to);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        cout << Solve(n) << '\n';
    }

    return 0;
}

inline ll Solve(int n) {
    ll res = 0;
    vector<Island> island(n);
    set<int> yval;
    unordered_map<int, int> yidx;

    for (int i = 0; i < n; i++) {
        cin >> island[i].x >> island[i].y;
        yval.insert(island[i].y);
    }
    ymax = yval.size();
    sort(island.begin(), island.end());

    i = 1;
    for (auto it = yval.begin(); it != yval.end(); it++)
        yidx[*it] = i++;

    height = ceil(log2(ymax)) + 1;
    idx = pow(2, height - 1);
    vector<ll> tree(pow(2, height), 0);
    
    for (Island& isl : island) {
        int y = yidx[isl.y];
        res += Sum(tree, y, ymax);
        Update(tree, y, tree[INDEX(y)] + 1);
    }

    return res;
}

inline void Update(vector<ll>& tree, int y, ll value) {
    y = INDEX(y);
    ll diff = value - tree[y];
    while (y > 0) {
        tree[y] += diff;
        y /= 2;
    }
}

inline ll Sum(vector<ll>& tree, int from, int to) {
    ll res = 0;
    from = INDEX(from);
    to = INDEX(to);
    while (from <= to) {
        if (from % 2 == 1)
            res += tree[from];
        if (to % 2 == 0)
            res += tree[to];
        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    return res;
}