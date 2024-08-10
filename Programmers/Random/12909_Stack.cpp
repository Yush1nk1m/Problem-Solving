/**
 * @file 12909_Stack.cpp
 * @brief 프로그래머스 "올바른 괄호" 00:02:11
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int pcnt = 0;
    for (char paren : s) {
        if (paren == '(')
            pcnt++;
        else
            pcnt--;
        
        if (pcnt < 0)
            return false;
    }
    if (pcnt > 0)
        return false;
    return true;
}