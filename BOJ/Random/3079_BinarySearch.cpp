/**
 * @file 3079_BinarySearch.cpp
 * @brief 00:26:42
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, low = 1, high, minTime = numeric_limits<ll>::max();
vector<ll> immigration;

inline bool isAvailable(ll time);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    immigration.resize(N);
    for (int i = 0; i < N; i++)
        cin >> immigration[i];

    high = *max_element(immigration.begin(), immigration.end()) * M + 1LL;
    while (low <= high) {
        ll mid = (low + high) / 2LL;
        if (isAvailable((mid))) {
            minTime = min(minTime, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << minTime;

    return 0;
}

inline bool isAvailable(ll time) {
    ll capacity = 0;
    for (int i = 0; i < N && capacity < M; i++)
        capacity += time / immigration[i];
    return capacity >= M;
}