/**
 * @file 2792_BinarySearch.cpp
 * @brief 01:03:32
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 2000000000

ll N, M, result = INF;
vector<ll> jewelries;

inline bool CheckDistribution(ll amount);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    jewelries.resize(M);
    for (ll i = 0; i < M; i++)
        cin >> jewelries[i];

    ll l = 1, r = *(max_element(jewelries.begin(), jewelries.end()));
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (CheckDistribution(mid)) {
            result = min(result, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << result;

    return 0;
}

inline bool CheckDistribution(ll amount) {
    ll cnt = 0;
    for (ll jewel : jewelries) {
        cnt += (jewel / amount);
        cnt += (jewel % amount != 0);
    }
    return (cnt <= N);
}