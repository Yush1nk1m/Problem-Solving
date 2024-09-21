/**
 * @file 10451_Graph.cpp
 * @brief 00:06:00
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N;

inline int Solve(int N);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        cout << Solve(N) << '\n';
    }

    return 0;
}

inline int Solve(int N) {
    int cnt = 0;
    vector<int> numbers(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; i++)
        cin >> numbers[i];

    for (int i = 1; i <= N; i++)
        if (!visited[i]) {
            cnt++;
            int node = i;
            while (!visited[node]) {
                visited[node] = true;
                node = numbers[node];
            }
        }

    return cnt;
}