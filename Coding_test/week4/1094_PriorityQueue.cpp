/**
 * @file 1094_PriorityQueue.cpp
 * @brief 00:07:38
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int X;
int L = 64, cnt = 1;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X;

    pq.push(L);
    while (L > X) {
        int shortest = pq.top(), l1, l2;
        l1 = l2 = shortest / 2;

        pq.push(l1);
        if (L - l2 < X) {
            cnt++;
            pq.push(l2);
        } else {
            L -= l2;
        }
    }

    cout << cnt;

    return 0;
}