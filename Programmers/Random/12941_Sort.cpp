/**
 * @file 12941_Sort.cpp
 * @brief 프로그래머스 "최솟값 만들기" 00:02:04
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for (int i = 0; i < A.size(); i++)
        answer += A[i] * B[i];

    return answer;
}