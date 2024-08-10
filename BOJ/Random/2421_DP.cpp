/**
 * @file 2421_DP.cpp
 * @brief 00:29:32
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF     100000000
#define SIZE    1000000
#define NONE    -1

int N;
vector<bool> sieve(SIZE, true);
vector<vector<int>> table;

inline void InitializeSieve();
inline bool IsPrime(int first, int second);
int DFS(int first, int second);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    InitializeSieve();

    cin >> N;
    table.resize(N + 1, vector<int>(N + 1, NONE));

    cout << DFS(1, 1) - 1;

    return 0;
}

inline void InitializeSieve() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < SIZE; i++)
        if (sieve[i])
            for (int mul = i * 2; mul < SIZE; mul += i)
                sieve[mul] = false;
}

inline bool IsPrime(int first, int second) {
    first *= pow(10, (int)log10(second) + 1);
    first += second;
    return sieve[first];
}

int DFS(int first, int second) {
    if (first > N || second > N)
        return -INF;
    int prime = IsPrime(first, second);
    if (first == N && second == N)
        return prime;

    int& ret = table[first][second];
    if (ret != NONE)
        return ret;

    return (ret = max(DFS(first + 1, second) + prime, DFS(first, second + 1) + prime));
}