/**
 * @file 42577_Hash.cpp
 * @brief 프로그래머스 "전화번호 목록"
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

inline bool match(string& s1, string& s2) {
    // assumption: s1.length() <= s2.length()
    for (int i = 0; i < s1.length(); i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++)
        if (phone_book[i].length() <= phone_book[i+1].length() && match(phone_book[i], phone_book[i+1]))
            return false;
    
    return true;
}