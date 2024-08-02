/**
 * @file 43105_DP.cpp
 * @brief 프로그래머스 "정수 삼각형"
 * @date 2024-08-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int height;
vector<vector<int>> table;

int DFS(int depth, int idx, vector<vector<int>>& triangle);

int solution(vector<vector<int>> triangle) {
    height = triangle.size();
    table.resize(height);
    for (int i = 0; i < height; i++)
        table[i].resize(i + 1, NONE);
    
    return DFS(0, 0, triangle);
}

int DFS(int depth, int idx, vector<vector<int>>& triangle) {
    if (depth == height - 1) {
        return triangle[depth][idx];
    }
    
    int& ret = table[depth][idx];
    if (ret != NONE)
        return ret;

    return ret = max(
        DFS(depth + 1, idx, triangle) + triangle[depth][idx],
        DFS(depth + 1, idx + 1, triangle) + triangle[depth][idx]
    );
}