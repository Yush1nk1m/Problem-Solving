/**
 * @file 14595_Sweeping.cpp
 * @brief 00:38:32
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, prevX, prevY;
vector<pair<int, int>> behavior;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    behavior.resize(M);
    for (int i = 0; i < M; i++)
        cin >> behavior[i].first >> behavior[i].second;
    sort(behavior.begin(), behavior.end());

    for (pair<int, int>& p : behavior) {
        int x = p.first, y = p.second;

        if (prevY < x) {
            N -= (prevY - prevX);
            prevX = x;
            prevY = y;
        } else {
            prevY = max(prevY, y);
        }
    }
    N -= (prevY - prevX);

    cout << N;

    return 0;
}
