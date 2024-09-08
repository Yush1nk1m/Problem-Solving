/**
 * @file 15961_TwoPointer.cpp
 * @brief 00:21:26
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, d, k, c, l, r, result, cnt;
vector<int> sushi;
vector<int> visited;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;
    visited.resize(d + 1, 0);
    sushi.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sushi[i];

    visited[c]++;
    cnt++;
    while (r < k) {
        if (visited[sushi[r]] == 0)
            cnt++;
        visited[sushi[r]]++;

        r++;
    }

    result = cnt;
    while (l < N) {
        visited[sushi[l]]--;
        if (visited[sushi[l]] == 0)
            cnt--;
        
        if (visited[sushi[r]] == 0)
            cnt++;
        visited[sushi[r]]++;

        result = max(result, cnt);

        l++;
        r = (r + 1) % N;
    }

    cout << result;

    return 0;
}