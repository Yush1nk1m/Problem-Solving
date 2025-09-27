/**
 * @file 12852_DP.cpp
 * @brief 00:10:00
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE -1

int N;
vector<int> cnt(1e6 + 1, NONE);
vector<int> parent(1e6 + 1);
queue<int> q;
stack<int> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 1e6; i++)
        parent[i] = i;

    cin >> N;
    cnt[N] = 0;
    q.push(N);
    while (cnt[1] == NONE) {
        int curr = q.front();
        q.pop();

        if (curr % 3 == 0 && cnt[curr / 3] == NONE) {
            parent[curr / 3] = curr;
            cnt[curr / 3] = cnt[curr] + 1;
            q.push(curr / 3);
        }

        if (curr % 2 == 0 && cnt[curr / 2] == NONE) {
            parent[curr / 2] = curr;
            cnt[curr / 2] = cnt[curr] + 1;
            q.push(curr / 2);
        }

        if (curr - 1 >= 0 && cnt[curr - 1] == NONE) {
            parent[curr - 1] = curr;
            cnt[curr - 1] = cnt[curr] + 1;
            q.push(curr - 1);
        }
    }

    int n = 1;
    stk.push(n);
    while (parent[n] != n) {
        n = parent[n];
        stk.push(n);
    }

    cout << cnt[1] << '\n';
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    
    return 0;
}