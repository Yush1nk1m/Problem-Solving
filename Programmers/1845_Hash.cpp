/**
 * @file 1845_Hash.cpp
 * @brief 프로그래머스 "폰켓몬"
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int num : nums)
        s.insert(num);
    
    return min(nums.size() / 2, s.size());
}