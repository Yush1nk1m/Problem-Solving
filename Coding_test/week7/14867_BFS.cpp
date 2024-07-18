/**
 * @file 14867_BFS.cpp
 * @brief 00:47:18
 * @date 2024-07-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int a, b, c, d;
map<pair<int, int>, int> visited;
queue<pair<int, int>> q;

inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d;

    cout << BFS();

    return 0;
}

inline int BFS() {
    visited[{ 0, 0 }] = 0;
    q.push({ 0, 0 });

    while (!q.empty() && visited.find({ c, d }) == visited.end()) {
        int ca, cb;
        tie(ca, cb) = q.front();
        q.pop();

        // F(A)
        if (visited.find({ a, cb }) == visited.end()) {
            visited[{ a, cb }] = visited[{ ca, cb }] + 1;
            q.push({ a, cb });
        }

        // F(B)
        if (visited.find({ ca, b }) == visited.end()) {
            visited[{ ca, b }] = visited[{ ca, cb }] + 1;
            q.push({ ca, b });
        }

        // E(A)
        if (visited.find({ 0, cb }) == visited.end()) {
            visited[{ 0, cb }] = visited[{ ca, cb }] + 1;
            q.push({ 0, cb });
        }

        // E(B)
        if (visited.find({ ca, 0 }) == visited.end()) {
            visited[{ ca, 0 }] = visited[{ ca, cb }] + 1;
            q.push({ ca, 0 });
        }

        // M(ca, cb)
        int f = min(ca, b - cb);
        if (visited.find({ ca-f, cb+f }) == visited.end()) {
            visited[{ ca-f, cb+f }] = visited[{ ca, cb }] + 1;
            q.push({ ca-f, cb+f });
        }

        // M(cb, ca)
        f = min(cb, a - ca);
        if (visited.find({ ca+f, cb-f }) == visited.end()) {
            visited[{ ca+f, cb-f }] = visited[{ ca, cb }] + 1;
            q.push({ ca+f, cb-f });
        }
    }

    if (visited.find({ c, d }) != visited.end())
        return visited[{ c, d }];
    else
        return -1;
}