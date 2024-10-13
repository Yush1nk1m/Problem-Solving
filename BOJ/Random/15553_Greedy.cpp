/**
 * @file 15553_Greedy.cpp
 * @brief 00:22:29
 * @date 2024-10-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, cnt;
ll total;
vector<ll> T;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    T.resize(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];
    
    for (int i = 0; i < N - 1; i++)
        pq.push(T[i + 1] - T[i] + 1);

    while (N > K) {
        ll curr = pq.top();
        pq.pop();

        total += curr;
        cnt++;
        N--;
    }
    total += (N - cnt);

    cout << total;

    return 0;
}