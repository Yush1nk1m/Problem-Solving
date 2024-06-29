/**
 * @file 12869.cpp
 * @brief 01:32:56
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int scv[3];
bool visited[61][61][61];

inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> scv[i];
    
    cout << BFS();

    return 0;
}

inline int BFS() {
    int attack = 0;
    queue<tuple<int, int, int>> q;

    q.push(make_tuple(scv[0], scv[1], scv[2]));
    visited[scv[0]][scv[1]][scv[2]] = true;

    while (!q.empty()) {
        attack++;
        int qsize = q.size();
        for (int _ = 0; _ < qsize; _++) {
            tuple<int, int, int> curr = q.front();
            q.pop();

            vector<int> power = { 9, 3, 1 };
            do {
                int hp1 = get<0>(curr), hp2 = get<1>(curr), hp3 = get<2>(curr);
                hp1 = max(0, hp1 - power[0]);
                hp2 = max(0, hp2 - power[1]);
                hp3 = max(0, hp3 - power[2]);

                if (!visited[hp1][hp2][hp3]) {
                    visited[hp1][hp2][hp3] = true;
                    q.push(make_tuple(hp1, hp2, hp3));
                }
            } while (next_permutation(power.rbegin(), power.rend()));
        }

        if (visited[0][0][0]) return attack;
    }

    return -1;
}