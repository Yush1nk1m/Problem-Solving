/**
 * @file 18428_Implementation.cpp
 * @brief 00:19:28
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY   'X'
#define STUDENT 'S'
#define TEACHER 'T'
#define WALL    'O'

int N;
bool escapable;
vector<vector<char>> hall;
vector<pair<int, int>> candidates, teachers;

void DFS(int depth, int maxi);
inline bool checkEscapable();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    hall.resize(N, vector<char>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> hall[r][c];
            if (hall[r][c] == TEACHER)
                teachers.push_back({ r, c });
            else if (hall[r][c] == EMPTY)
                candidates.push_back({ r, c });
        }

    DFS(0, -1);

    if (escapable)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

void DFS(int depth, int maxi) {
    if (escapable)
        return;
    else if (depth == 3) {
        escapable = checkEscapable();
        return;
    }

    for (int i = maxi + 1; i < candidates.size(); i++) {
        int r, c;
        tie(r, c) = candidates[i];
        hall[r][c] = WALL;
        DFS(depth + 1, i);
        hall[r][c] = EMPTY;
    }
}

inline bool checkEscapable() {
    for (pair<int, int>& p : teachers) {
        // up
        for (int r = p.first; r >= 0 && hall[r][p.second] != WALL; r--)
            if (hall[r][p.second] == STUDENT)
                return false;
        
        // down
        for (int r = p.first; r < N && hall[r][p.second] != WALL; r++)
            if (hall[r][p.second] == STUDENT)
                return false;

        // left
        for (int c = p.second; c >= 0 && hall[p.first][c] != WALL; c--)
            if (hall[p.first][c] == STUDENT)
                return false;
        
        // right
        for (int c = p.second; c < N && hall[p.first][c] != WALL; c++)
            if (hall[p.first][c] == STUDENT)
                return false;
    }

    return true;
}