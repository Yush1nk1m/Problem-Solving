/**
 * @file 1758_Greedy.cpp
 * @brief 00:08:38
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll sum;
vector<ll> money;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    money.resize(N);
    for (int i = 0; i < N; i++)
        cin >> money[i];

    sort(money.rbegin(), money.rend());
    for (ll i = 0; i < N; i++) {
        money[i] = max(money[i] - i, 0LL);
        sum += money[i];
    }

    cout << sum;

    return 0;
}