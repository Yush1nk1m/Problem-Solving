/**
 * @file 1174_DFS.cpp
 * @brief 00:13:26
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> v;

void DFS(ll number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 9; i++)
        DFS(i);

    cin >> N;

    if (v.size() < N)
        cout << -1;
    else {
        sort(v.begin(), v.end());
        cout << v[N-1];
    }

    return 0;
}

void DFS(ll number) {
    v.push_back(number);
    for (int i = 0; i < number % 10; i++)
        DFS(number * 10 + i);
}