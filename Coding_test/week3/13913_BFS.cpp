/**
 * @file 13913_BFS.cpp
 * @brief 00:09:06
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K;
stack<int> stk;
vector<bool> visited(200001, false);
vector<int> parent(200001);

inline void BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i <= 200000; i++)
        parent[i] = i;

    BFS();
    while (parent[K] != K) {
        stk.push(K);
        K = parent[K];
    }
    stk.push(K);

    cout << stk.size() - 1 << '\n';
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}

inline void BFS() {
    queue<int> q;

    visited[N] = true;
    q.push(N);
    while (!q.empty() && !visited[K]) {
        int curr = q.front();
        q.pop();

        if (curr - 1 >= 0 && !visited[curr - 1]) {
            visited[curr - 1] = true;
            parent[curr - 1] = curr;
            q.push(curr - 1);
        }
        if (curr + 1 <= 100000 && !visited[curr + 1]) {
            visited[curr + 1] = true;
            parent[curr + 1] = curr;
            q.push(curr + 1);
        }
        if (curr * 2 <= 200000 && !visited[curr * 2]) {
            visited[curr * 2] = true;
            parent[curr * 2] = curr;
            q.push(curr * 2);
        }
    }
}