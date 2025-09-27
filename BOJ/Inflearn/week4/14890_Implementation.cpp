/**
 * @file 14890_Implementation.cpp
 * @brief 01:07:20
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, L, cnt;
vector<vector<int>> rows;
vector<vector<int>> cols;

bool Available(vector<int> path);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    rows.resize(N, vector<int>(N));
    cols.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> rows[r][c];
            cols[c][r] = rows[r][c];
        }
    
    for (vector<int>& row : rows)
        cnt += Available(row);
    for (vector<int>& col : cols)
        cnt += Available(col);

    cout << cnt;

    return 0;
}

bool Available(vector<int> path) {
    vector<bool> visited(N, false);
    int p = 0;
    while (p < N - 1) {
        if (path[p] == path[p + 1]) {
            p++;
        }
        else if (path[p] + 1 == path[p + 1]) {
            if (p - L + 1 < 0) return false;

            int h = path[p];
            for (int i = p; i >= p - L + 1; i--) {
                if (visited[i] || h != path[i]) return false;
                visited[i] = true;
            }
            
            p++;
        }
        else if (path[p] - 1 == path[p + 1]) {
            if (p + L >= N) return false;

            int h = path[p + 1];
            for (int i = p + 1; i <= p + L; i++) {
                if (h != path[i]) return false;
                visited[i] = true;
            }

            p += L;
        }
        else return false;
    }

    return true;
}