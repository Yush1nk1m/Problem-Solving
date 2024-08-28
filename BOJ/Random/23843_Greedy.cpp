/**
 * @file 23843_Greedy.cpp
 * @brief 00:09:30
 * @date 2024-08-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> t;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    t.resize(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];
    sort(t.rbegin(), t.rend());

    while (M--)
        pq.push(0);

    for (int len : t) {
        int curr = pq.top();
        pq.pop();
        curr += len;
        pq.push(curr);
    }

    while (pq.size() > 1)
        pq.pop();
    cout << pq.top();

    return 0;
}
