/**
 * @file 2268_SegmentTree.cpp
 * @brief 00:35:00
 * @date 2024-11-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SUM     0
#define MODIFY  1

int N, M, sIdx;
vector<ll> tree;

inline ll sum(int i, int j);
inline void modify(int i, ll k);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    tree.resize(pow(2, ceil(log2(N)) + 1), 0);
    sIdx = pow(2, ceil(log2(N)));

    while (M--) {
        int op, n1, n2;
        cin >> op >> n1 >> n2;
        
        if (op == SUM)
            cout << sum(n1, n2) << '\n';
        else if (op == MODIFY)
            modify(n1, n2);
    }

    return 0;
}

inline ll sum(int i, int j) {
    if (i > j) {
        int temp = i;
        i = j;
        j = temp;
    }

    int l = sIdx + i - 1, r = sIdx + j - 1;
    ll sum = 0;
    while (l <= r) {
        if (l % 2 != 0)
            sum += tree[l];
        if (r % 2 == 0)
            sum += tree[r];
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    
    return sum;
}

inline void modify(int i, ll k) {
    i += sIdx - 1;
    ll diff = k - tree[i];
    while (i >= 1) {
        tree[i] += diff;
        i /= 2;
    }
}