/**
 * @file 9204_BFS.cpp
 * @brief 01:02:00
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define IDX(c)  (c - 'A' + 1)

int T;
bool visited[9][9];
pair<char, int> s, e;
int dr[4] = { -1, 1, -1, 1 };
int dc[4] = { -1, -1, 1, 1 };

inline bool isValidPoint(pair<char, int>& point);
inline void solve();
void dfs(pair<char, int> point);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> s.first >> s.second >> e.first >> e.second;
        solve();   
    }
}

inline bool isValidPoint(pair<char, int>& point) {
    return ('A' <= point.first && point.first <= 'H' && 1 <= point.second && point.second <= 8);
}

inline void solve() {
    memset(visited, 0, sizeof(visited));
    queue<pair<char, int>> q;
    map<pair<char, int>, pair<char, int>> parent;

    if (s.first == e.first && s.second == e.second) {
        cout << "0 " << e.first << ' ' << e.second << '\n';
        return;
    } else if ((abs(s.first - e.first) + abs(s.second - e.second)) % 2 != 0) {
        cout << "Impossible\n";
        return;
    }

    visited[IDX(s.first)][s.second] = true;
    q.push(s);
    int seq = 0;
    while (!q.empty() && seq < 4 && !visited[IDX(e.first)][e.second]) {
        seq++;
        int qsize = q.size();
        while (qsize--) {
            pair<char, int> curr = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
                for (int jmp = 1; jmp <= 8; jmp++) {
                    pair<char, int> nextp = { curr.first + jmp * dr[d], curr.second + jmp * dc[d] };
                    if (!isValidPoint(nextp) || visited[IDX(nextp.first)][nextp.second])
                        continue;
                    
                    parent[nextp] = curr;
                    visited[IDX(nextp.first)][nextp.second] = true;
                    q.push(nextp);
                }
        }
    }

    stack<pair<char, int>> stk;
    while (e.first != s.first && e.second != s.second) {
        stk.push(e);
        e = parent[e];
    }
    stk.push(s);

    cout << stk.size() - 1 << ' ';
    while (!stk.empty()) {
        cout << stk.top().first << ' ' << stk.top().second << ' ';
        stk.pop();
    }
    cout << '\n';
}