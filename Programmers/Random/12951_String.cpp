/**
 * @file 12951_String.cpp
 * @brief 프로그래머스 "JadenCase 문자열 만들기" 00:16:18
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

inline bool isUpper(char c) {
    return ('A' <= c && c <= 'Z');
}

inline void toUpper(char& c) {
    c -= 32;
}

inline bool isLower(char c) {
    return ('a' <= c && c <= 'z');
}

inline void toLower(char& c) {
    c += 32;
}

string solution(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isUpper(s[i]) && !(i == 0 || s[i-1] == ' '))
            toLower(s[i]);
        else if (isLower(s[i]) && (i == 0 || s[i-1] == ' '))
            toUpper(s[i]);
    }
    
    return s;
}