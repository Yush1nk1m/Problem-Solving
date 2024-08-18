/**
 * @file 17087_Math.cpp
 * @brief 00:18:37
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, S;
vector<ll> locs;

inline ll LCM(ll a, ll b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    locs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> locs[i];
        locs[i] = abs(S - locs[i]);
    }
    sort(locs.rbegin(), locs.rend());

    for (int i = 1; i < N; i++)
        locs[i] = LCM(locs[i-1], locs[i]);

    cout << locs[N-1];

    return 0;
}

inline ll LCM(ll a, ll b) {
    while (a % b != 0) {
        ll temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}