/**
 * @file 17071_BFS.cpp
 * @brief 00:35:37
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, K;
vector<int> visitedOdd(500001, INF);
vector<int> visitedEven(500001, INF);

inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }

    cout << BFS();

    return 0;
}

inline int BFS() {
    int t = 0;
    queue<int> q;

    visitedEven[N] = 0;
    q.push(N);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int nextp : { curr - 1, curr + 1, curr * 2 }) {
            if (0 <= nextp && nextp <= 500000) {
                if (visitedEven[curr] != INF && visitedOdd[nextp] == INF) {
                    visitedOdd[nextp] = visitedEven[curr] + 1;
                    q.push(nextp);
                }
                if (visitedOdd[curr] != INF && visitedEven[nextp] == INF) {
                    visitedEven[nextp] = visitedOdd[curr] + 1;
                    q.push(nextp);
                }
            }
        }
    }

    int p = K;
    int speed = 1;
    int time = 0;
    while (p <= 500000) {
        if (visitedOdd[p] <= time && (time - visitedOdd[p]) % 2 == 0)
            return time;
        else if (visitedEven[p] <= time && (time - visitedEven[p]) % 2 == 0)
            return time;
        time++;
        p += speed++;
    }

    return -1;
}