/**
 * @file 14620_Backtracking.cpp
 * @brief 00:13:07
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, minCost = INF;
vector<vector<int>> cost;
vector<vector<bool>> visited;
vector<pair<int, int>> places;

inline int GetCost(int r, int c);
inline bool isValidPoint(int r, int c);
void DFS(int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cost.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> cost[r][c];

    DFS(0);
    cout << minCost;

    return 0;
}

inline int GetCost(int r, int c) {
    return (cost[r][c] + cost[r+1][c] + cost[r-1][c] + cost[r][c+1] + cost[r][c-1]);
}

inline bool isValidPoint(int r, int c) {
    return (!visited[r][c] && !visited[r+1][c] && !visited[r-1][c] && !visited[r][c+1] && !visited[r][c-1]);
}

void DFS(int depth) {
    if (depth == 3) {
        int totalCost = 0;
        for (pair<int, int>& loc : places)
            totalCost += GetCost(loc.first, loc.second);
        minCost = min(minCost, totalCost);
        return;
    }

    for (int r = 1; r < N - 1; r++)
        for (int c = 1; c < N - 1; c++)
            if (isValidPoint(r, c)) {
                visited[r][c] = visited[r+1][c] = visited[r-1][c] = visited[r][c+1] = visited[r][c-1] = true;
                places.push_back({ r, c });
                DFS(depth + 1);
                places.pop_back();
                visited[r][c] = visited[r+1][c] = visited[r-1][c] = visited[r][c+1] = visited[r][c-1] = false;
            }
}