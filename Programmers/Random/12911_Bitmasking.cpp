/**
 * @file 12911_Bitmasking.cpp
 * @brief 프로그래머스 "다음 큰 숫자"
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

inline int CheckCount(int n) {
    int cnt = 0;
    for (int i = 0; i < 20; i++)
        if ((1 << i) & n)
            cnt++;
    return cnt;
}

int solution(int n) {
    int cnt = CheckCount(n++);
    while (CheckCount(n) != cnt)
        n++;
    return n;
}