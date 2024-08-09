/**
 * @file 23829_BinarySearch.cpp
 * @brief 00:43:33
 * @date 2024-08-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Q, photo;
vector<ll> tree;
vector<ll> sum;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    tree.resize(N + 1, 0);
    sum.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> tree[i];
    sort(tree.begin(), tree.end());
    for (int i = 1; i <= N; i++)
        sum[i] = tree[i] + sum[i-1];

    while (Q--) {
        cin >> photo;
        ll low = lower_bound(tree.begin(), tree.end(), photo) - tree.begin() - 1;
        low = max(low, 0LL);
        ll high = N - low;
        ll result = 0;

        if (low)
            result += (photo * low) - sum[low];
        if (high)
            result += (sum[N] - sum[low]) - (photo * high);
        cout << result << '\n';
    }
}