/**
 * @file 1561_BinarySearch_Math.cpp
 * @brief 00:57:13
 * @date 2024-07-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, low = 1, high = 2e9 * 30 + 1, tot, acc;
vector<int> times;

inline bool Riden(ll time);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    times.resize(M);
    for (int i = 1; i <= M; i++)
        cin >> times[i];

    // if N <= M, Nth person will ride at time 0
    if (N <= M) {
        cout << N;
        return 0;
    }

    // this logic will find the minimum total time to hold Nth person
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (Riden(mid)) {
            tot = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // the number of people riden at time 0
    acc = M;

    // the number of people riden by time (tot - 1)
    for (int i = 1; i <= M; i++)
        acc += ((tot - 1) / times[i]);

    // get the people who rides exactly time (tot), and get the number of Nth person
    for (int i = 1; i <= M; i++) {
        acc += (tot % times[i] == 0);
        if (acc == N) {
            cout << i;
            break;
        }
    }

    return 0;
}

inline bool Riden(ll time) {
    ll cnt = 0;
    for (int i = 1; i <= M; i++)
        cnt += (time / times[i] + 1);
    return (cnt >= N);
}