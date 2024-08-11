/**
 * @file 12924_TwoPointer.cpp
 * @brief 프로그래머스 "숫자의 표현" 00:31:46
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int sum = 0, cnt = 0;
    int l = 1, r = 1;
    
    while (l <= r && r <= n + 1) {
        if (sum < n)
            sum += r++;
        else if (sum > n)
            sum -= l++;
        else {
            cnt++;
            sum += r++;            
        }
    }
    
    return cnt;
}