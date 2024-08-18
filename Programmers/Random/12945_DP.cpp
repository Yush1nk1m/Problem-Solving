/**
 * @file 12945_DP.cpp
 * @brief 프로그래머스 "피보나치 수" 00:02:08
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1234567

vector<ll> fibo;

int solution(int n) {
    if (n <= 1)
        return n;
    
    fibo.resize(n + 1, 0);
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
        fibo[i] = ((fibo[i-1] % MOD) + (fibo[i-2] % MOD)) % MOD;
    
    return fibo[n];
}