/**
 * @file 5557_DP.cpp
 * @brief 00:26:14
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

#define NONE    -1

int N;
vector<int> numbers;
vector<vector<ull>> table;      // [depth][curr]

ull DFS(int curr, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    table.resize(N, vector<ull>(21, NONE));
    table[N-1][numbers[N-1]] = 1;
    cout << DFS(numbers[0], 1);
    
    return 0;
}

ull DFS(int curr, int depth) {
    if (depth == N - 1) {
        if (curr == numbers[N - 1])
            return table[N-1][numbers[N-1]];
        else
            return 0;
    }

    if (table[depth][curr] != NONE)
        return table[depth][curr];

    ull& ret = table[depth][curr];
    ret = 0;
    int nxt = numbers[depth];
    if (0 <= curr + nxt && curr + nxt <= 20)
        ret += DFS(curr + nxt, depth + 1);
    if (0 <= curr - nxt && curr - nxt <= 20)
        ret += DFS(curr - nxt, depth + 1);

    return ret;
}