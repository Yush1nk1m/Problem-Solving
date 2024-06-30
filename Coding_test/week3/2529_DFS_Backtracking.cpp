/**
 * @file 2529_DFS_Backtracking.cpp
 * @brief 00:22:35
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int k;
string minResult = "9999999999", maxResult = "0000000000";
bool visited[10];
vector<char> symbols;
vector<int> answer;

inline bool Check(int n1, char op, int n2);
void DFS(int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    symbols.resize(k);
    for (int i = 0; i < k; i++)
        cin >> symbols[i];

    DFS(0);
    cout << maxResult << '\n' << minResult;

    return 0;
}

inline bool Check(int n1, char op, int n2) {
    switch (op) {
        case '<':
            return n1 < n2;
        case '>':
            return n1 > n2;
        default:
            return false;
    }
}

void DFS(int depth) {
    if (depth == k + 1) {
        string result = "";
        for (int number : answer)
            result += (number + '0');

        minResult = min(minResult, result);
        maxResult = max(maxResult, result);

        return;
    }

    for (int n = 0; n <= 9; n++) {
        if (!visited[n] && (depth == 0 || Check(answer[depth-1], symbols[depth-1], n))) {
            visited[n] = true;
            answer.push_back(n);
            DFS(depth + 1);
            answer.pop_back();
            visited[n] = false;
        }
    }
}