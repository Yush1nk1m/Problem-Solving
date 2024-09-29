/**
 * @file 15658_Backtracking.cpp
 * @brief 00:14:54
 * @date 2024-09-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int N, minNumber = INF, maxNumber = -INF;
int operators[4];
vector<int> A;

void DFS(int idx, int curr);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];

    DFS(1, A[0]);

    cout << maxNumber << '\n';
    cout << minNumber << '\n';

    return 0;
}

void DFS(int idx, int curr) {
    if (idx == N) {
        minNumber = min(minNumber, curr);
        maxNumber = max(maxNumber, curr);
        return;
    }

    for (int i = 0; i < 4; i++)
        if (operators[i]) {
            operators[i]--;
            switch (i) {
                case ADD:
                    DFS(idx + 1, curr + A[idx]);
                    break;
                case SUB:
                    DFS(idx + 1, curr - A[idx]);
                    break;
                case MUL:
                    DFS(idx + 1, curr * A[idx]);
                    break;
                case DIV:
                    DFS(idx + 1, curr / A[idx]);
                    break;
            }
            operators[i]++;
        }
}