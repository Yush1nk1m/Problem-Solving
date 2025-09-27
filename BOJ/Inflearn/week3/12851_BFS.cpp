/**
 * @file 12851_BFS.cpp
 * @brief 00:37:52
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, K, cnt;
int t[200001];

inline void BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    BFS();
    cout << t[K] << '\n' << cnt;

    return 0;
}

inline void BFS() {
    fill(t, t + 200001, INF);
    queue<int> q;
    
    t[N] = 0;
    q.push(N);
    while (!q.empty() && t[K] == INF) {
        int qsize = q.size();
        for (int _ = 0; _ < qsize; _++) {
            int curr = q.front();
            int tnext = t[curr] + 1;
            q.pop();

            if (curr - 1 >= 0 && tnext <= t[curr - 1]) {
                t[curr - 1] = tnext;
                q.push(curr - 1);
                if (curr - 1 == K) cnt++;
            }
            if (curr + 1 <= 100000 && tnext <= t[curr + 1]) {
                t[curr + 1] = tnext;
                q.push(curr + 1);
                if (curr + 1 == K) cnt++;
            }
            if (curr * 2 <= 200000 && tnext <= t[curr * 2]) {
                t[curr * 2] = tnext;
                q.push(curr * 2);
                if (curr * 2 == K) cnt++;
            }
        }
    }
    if (N == K) cnt++;
}