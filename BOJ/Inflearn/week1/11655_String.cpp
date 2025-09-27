/**
 * @file 11655_String.cpp
 * @brief 00:09:59
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

inline bool isLower(char c) {
    return ('a' <= c && c <= 'z');
}

inline bool isUpper(char c) {
    return ('A' <= c && c <= 'Z');
}

int main(int argc, char* argv[]) {
    string input;
    getline(cin, input);

    for (char c : input) {
        if (isLower(c))
            cout << (char)('a' + ((c + 13) % 'a' % 26));
        else if (isUpper(c))
            cout << (char)('A' + ((c + 13) % 'A' % 26));
        else
            cout << c;
    }

    return 0;
}