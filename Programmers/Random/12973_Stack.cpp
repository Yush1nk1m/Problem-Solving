/**
 * @file 12973_Stack.cpp
 * @brief 프로그래머스 "짝지어 제거하기" 00:02:49
 * @date 2024-08-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

stack<char> stk;

int solution(string s)
{
    for (char c : s)
        if (!stk.empty() && stk.top() == c)
            stk.pop();
        else
            stk.push(c);
    
    return (stk.empty());
}