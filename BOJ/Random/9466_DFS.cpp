/**
 * @file 9466_DFS.cpp
 * @brief 01:29:29
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, n;

inline int solve(int n);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}

inline int solve(int n) {
    vector<int> neighbor(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<bool> grouped(n + 1, false);
    vector<bool> validating(n + 1, false);
    stack<int> stk;

    for (int i = 1; i <= n; i++)
        cin >> neighbor[i];

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        int curr = i;
        while (!visited[curr]) {
            visited[curr] = true;
            validating[curr] = true;
            stk.push(curr);
            curr = neighbor[curr];
        }
        
        // if curr is being validated, it is the begin point of cycle
        if (validating[curr]) {
            while (!stk.empty() && stk.top() != curr) {
                validating[stk.top()] = false;
                grouped[stk.top()] = true;
                stk.pop();
            }
            grouped[curr] = true;
        }

        while (!stk.empty()) {
            validating[stk.top()] = false;
            stk.pop();
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!grouped[i])
            cnt++;
    return cnt;
}