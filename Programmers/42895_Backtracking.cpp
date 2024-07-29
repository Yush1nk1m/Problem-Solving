/**
 * @file 42895_Backtracking.cpp
 * @brief 프로그래머스 "N으로 만들기"
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int target;
int numarr[9];

int DFS(int total, int depth);

int solution(int N, int number) {
    target = number;
    int answer = INF;
    
    int temp = N;
    for (int i = 1; i <= 8; i++) {
        numarr[i] = temp;
        temp *= 10;
        temp += N;
    }
    
    for (int i = 1; i <= 8; i++)
        answer = min(answer, DFS(numarr[i], i));
    
    if (answer == INF)
        return -1;
    else
        return answer;
}


int DFS(int total, int depth) {
    if (total < 1 || depth > 8)
        return INF;
    if (total == target)
        return depth;
    
    int ret = INF;
    for (int i = 1; i <= 8; i++) {
        ret = min(ret, DFS(total + numarr[i], depth + i));
        ret = min(ret, DFS(total - numarr[i], depth + i));
        ret = min(ret, DFS(numarr[i] - total, depth + i));
        ret = min(ret, DFS(total * numarr[i], depth + i));
        ret = min(ret, DFS(total / numarr[i], depth + i));
        ret = min(ret, DFS(numarr[i] / total, depth + i));
    }
    return ret;
}