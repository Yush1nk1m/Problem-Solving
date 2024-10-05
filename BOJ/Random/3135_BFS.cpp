/**
 * @file 3135_BFS.cpp
 * @brief 00:13:14
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int A, B, N, cnt = 1;
vector<int> predefined;
vector<bool> visited;
queue<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> N;
    predefined.resize(N);
    visited.resize(1001, false);
    for (int i = 0; i < N; i++)
        cin >> predefined[i];

    if (A == B) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        visited[predefined[i]] = true;
        q.push(predefined[i]);
    }
    if (A - 1 > 0) {
        visited[A - 1] = true;
        q.push(A - 1);
    }
    if (A + 1 < 1000) {
        visited[A + 1] = true;
        q.push(A + 1);
    }

    while (!visited[B] && !q.empty()) {
        cnt++;
        int qsize = q.size();
        while (qsize--) {
            int curr = q.front();
            q.pop();

            if (curr - 1 > 0 && !visited[curr - 1]) {
                visited[curr - 1] = true;
                q.push(curr - 1);
            }

            if (curr + 1 < 1000 && !visited[curr + 1]) {
                visited[curr + 1] = true;
                q.push(curr + 1);
            }
        }
    }

    cout << cnt;

    return 0;
}