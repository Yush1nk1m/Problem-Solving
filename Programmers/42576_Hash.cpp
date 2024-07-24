/**
 * @file 42576_Hash.cpp
 * @brief 프로그래머스 "완주하지 못한 선수"
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<bool> completions;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++)
        if (participant[i] != completion[i])
            return participant[i];
    return participant[participant.size() - 1];
}