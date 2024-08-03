/**
 * @file 42898_DP.cpp
 * @brief 프로그래머스 "등굣길"
 * @date 2024-08-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NONE    -1
#define MOD     1000000007

int N, M;
vector<vector<ll>> table;

ll DFS(int r, int c) {
    if (r == N - 1 && c == M - 1)
        return 1;
    else if (r == N || c == M)
        return 0;
    
    ll& ret = table[r][c];
    if (ret != NONE)
        return ret;
    
    ret = 0;
    ret += DFS(r + 1, c);
    ret %= MOD;
    ret += DFS(r, c + 1);
    ret %= MOD;
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {  
    N = n; M = m;
    table.resize(n, vector<ll>(m, NONE));
    for (vector<int>& puddle : puddles)
            table[puddle[1]-1][puddle[0]-1] = 0;
    
    return DFS(0, 0);
}