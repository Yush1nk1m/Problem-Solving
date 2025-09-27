/**
 * @file 14003_BinarySearch_DP.cpp
 * @brief 00:31:35
 * @date 2024-07-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001

int N, mlen;
vector<pair<int, int>> table;   // { value, length }
vector<int> len;
stack<int> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N, { -INF, 0 });
    for (int i = 0; i < N; i++)
        cin >> table[i].first;

    len.push_back(-INF);
    for (pair<int, int>& p : table) {
        auto it = lower_bound(len.begin(), len.end(), p.first);
        int l = it - len.begin();

        if (len.size() == l)
            len.push_back(p.first);
        else
            len[l] = min(len[l], p.first);

        p.second = l;
    }
    mlen = len.size() - 1;

    cout << mlen << '\n';
    for (int i = table.size() - 1; i >= 0 && mlen > 0; i--) {
        pair<int, int> curr = table[i];

        if (curr.second == mlen) {
            stk.push(curr.first);
            mlen--;
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}