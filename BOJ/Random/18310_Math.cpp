/**
 * @file 18310_Math.cpp
 * @brief 00:20:45
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> v;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    if (N % 2 == 0)
        cout << v[N / 2 - 1];
    else
        cout << v[N / 2];

    return 0;
}