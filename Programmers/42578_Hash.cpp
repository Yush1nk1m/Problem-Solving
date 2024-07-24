/**
 * @file 42578_Hash.cpp
 * @brief 프로그래머스 "의상"
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (vector<string> v : clothes) {
        if (m.find(v[1]) == m.end())
            m[v[1]] = 1;
        else
            m[v[1]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
        answer *= (it->second) + 1;
    answer--;
    return answer;
}