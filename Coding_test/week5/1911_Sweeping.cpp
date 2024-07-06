/**
 * @file 1911_Sweeping.cpp
 * @brief 00:14:29
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, L, curr = -1, cnt;
vector<pair<ll, ll>> water;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    water.resize(N);
    for (int i = 0; i < N; i++)
        cin >> water[i].first >> water[i].second;
    sort(water.begin(), water.end());

    for (pair<ll, ll>& w : water) {
        ll start = w.first, end = w.second - 1;

        if (curr < start) {
            curr = start + (L - 1);
            cnt++;
        }

        while (curr < end) {
            curr += L;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}