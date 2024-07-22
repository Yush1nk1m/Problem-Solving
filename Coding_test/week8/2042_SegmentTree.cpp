/**
 * @file 2042_SegmentTree.cpp
 * @brief 00:27:50
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INDEX(x)    (x + idx - 1)
#define UPDATE  1
#define SUM     2

int N, M, K, height, idx;
vector<ll> tree;

inline void Update(int i, ll value);
inline ll PrefixSum(int from, int to);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    height = ceil(log2(N)) + 1;
    idx = pow(2, height - 1);
    tree.resize(pow(2, height), 0);

    for (int i = idx; i < idx + N; i++)
        cin >> tree[i];
    for (int i = idx - 1; i > 0; i--)
        tree[i] = tree[i*2] + tree[i*2+1];

    for (int _ = 0; _ < M + K; _++) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        if (a == UPDATE)
            Update(b, c);
        else if (a == SUM)
            cout << PrefixSum(b, c) << '\n';
    }

    return 0;
}

inline void Update(int i, ll value) {
    ll diff = value - tree[INDEX(i)];
    for (i = INDEX(i); i > 0; i /= 2)
        tree[i] += diff;
}

inline ll PrefixSum(int from, int to) {
    ll sum = 0;

    from = INDEX(from);
    to = INDEX(to);
    while (from <= to) {
        if (from % 2 == 1)
            sum += tree[from];
        if (to % 2 == 0)
            sum += tree[to];

        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    
    return sum;
}