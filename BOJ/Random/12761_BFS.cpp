/**
 * @file 12761_BFS.cpp
 * @brief 00:09:08
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int A, B, N, M, step = 0;
vector<bool> visited(100001, false);
queue<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> N >> M;
    
    visited[N] = true;
    q.push(N);
    while (!visited[M]) {
        step++;
        int qsize = q.size();
        while (qsize--) {
            int curr = q.front();
            q.pop();

            if (curr - 1 >= 0 && !visited[curr - 1]) {
                visited[curr - 1] = true;
                q.push(curr - 1);
            }
            if (curr + 1 <= 100000 && !visited[curr + 1]) {
                visited[curr + 1] = true;
                q.push(curr + 1);
            }
            if (curr - A >= 0 && !visited[curr - A]) {
                visited[curr - A] = true;
                q.push(curr - A);
            }
            if (curr + A <= 100000 && !visited[curr + A]) {
                visited[curr + A] = true;
                q.push(curr + A);
            }
            if (curr * A <= 100000 && !visited[curr * A]) {
                visited[curr * A] = true;
                q.push(curr * A);
            }
            if (curr - B >= 0 && !visited[curr - B]) {
                visited[curr - B] = true;
                q.push(curr - B);
            }
            if (curr + B <= 100000 && !visited[curr + B]) {
                visited[curr + B] = true;
                q.push(curr + B);
            }
            if (curr * B <= 100000 && !visited[curr * B]) {
                visited[curr * B] = true;
                q.push(curr * B);
            }
        }
    }

    cout << step;

    return 0;
}