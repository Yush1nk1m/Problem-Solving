/**
 * @file 2565.cpp
 * @brief 00:35:53
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> cable;
vector<int> len(1, 0);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cable.resize(N);
    for (int i = 0; i < N; i++)
        cin >> cable[i].first >> cable[i].second;
    sort(cable.begin(), cable.end());

    for (pair<int, int>& p : cable) {
        auto it = lower_bound(len.begin(), len.end(), p.second);
        int l = it - len.begin();

        if (l == len.size())
            len.push_back(p.second);
        else
            len[l] = min(len[l], p.second);
    }

    cout << (N - (len.size() - 1));

    return 0;
}