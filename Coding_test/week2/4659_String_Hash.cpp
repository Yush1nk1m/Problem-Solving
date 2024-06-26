/**
 * @file 4659_String_Hash.cpp
 * @brief 00:13:20
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

string input;
map<char, int> vowelMap;

inline bool isVowel(char c);
inline bool CheckAcceptance(string input);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vowelMap['a'] = 0; vowelMap['e'] = 1; vowelMap['i'] = 2; vowelMap['o'] = 3; vowelMap['u'] = 4;

    while (cin >> input) {
        if (input == "end") break;

        if (CheckAcceptance(input))
            cout << "<" << input << "> is acceptable.\n";
        else
            cout << "<" << input << "> is not acceptable.\n";
    }
}

inline bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

inline bool CheckAcceptance(string input) {
    int vowelCount[5] = { 0, 0, 0, 0, 0 };
    int priorVowel = 0, priorConso = 0;
    char priorChar = '\0';

    for (char c : input) {
        if (isVowel(c)) {
            vowelCount[vowelMap[c]]++;
            priorVowel++;
            priorConso = 0;
        } else {
            priorVowel = 0;
            priorConso++;
        }

        if ((priorChar == c && (c != 'e' && c != 'o')) || priorVowel == 3 || priorConso == 3)
            return false;

        priorChar = c;
    }

    if (!accumulate(vowelCount, vowelCount + 5, 0))
        return false;

    return true;
}