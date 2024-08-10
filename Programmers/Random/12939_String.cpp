/**
 * @file 12939_String.cpp
 * @brief 프로그래머스 "최댓값과 최솟값" 00:04:57
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> SplitAndParseInt(string input, char delim) {
    istringstream iss(input);
    string token;
    vector<int> parsedTokens;
    
    while (getline(iss, token, delim))
        parsedTokens.push_back(stoi(token));
    
    return parsedTokens;
}

string solution(string s) {
    string answer = "";
    vector<int> parsedStr = SplitAndParseInt(s, ' ');
    answer = to_string(*min_element(parsedStr.begin(), parsedStr.end())) + ' ' + to_string(*max_element(parsedStr.begin(), parsedStr.end()));
    return answer;
}