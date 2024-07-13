/**
 * @file 11053_BinarySearch_DP.cpp
 * @brief 00:04:55
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> seq;
vector<int> len;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i].first;
    
    len.push_back(0);
    for (pair<int, int>& p : seq) {
        auto it = lower_bound(len.begin(), len.end(), p.first);
        int l = it - len.begin();

        if (l == len.size())
            len.push_back(p.first);
        else
            len[l] = min(len[l], p.first);

        p.second = l;
    }

    cout << len.size() - 1;

    return 0;
}