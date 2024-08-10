/**
 * @file 70129_String_Bitmasking.cpp
 * @brief 프로그래머스 "이진 변환 반복하기" 00:13:44
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int zeroCnt, transformCnt;

inline int CountOnes(string& s) {
    int cnt = 0;
    for (char c : s)
        cnt += (c == '1');
    return cnt;
}

inline void Transform(string& s, int len) {
    string temp = "";
    for (int i = (int)log2(len); i >= 0; i--) {
        if (len & (1 << i))
            temp += "1";
        else
            temp += "0";
    }
    s = temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    while (s != "1") {
        int len = CountOnes(s);
        zeroCnt += (s.length() - len);
        Transform(s, len);
        transformCnt++;
    }
    
    answer = { transformCnt, zeroCnt };
    
    return answer;
}