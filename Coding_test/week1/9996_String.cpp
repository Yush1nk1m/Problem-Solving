/**
 * @file 9996_String.cpp
 * @brief 00:49:43
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;
string input;

inline vector<string> split(string input, char delim) {
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, delim))
        tokens.push_back(token);

    return tokens;
}

inline bool ExaminePattern(string input, vector<string> patterns) {
    int fPos, rPos;
    string frontPat = patterns[0], rearPat = patterns[1];

    fPos = input.find(frontPat);
    rPos = input.rfind(rearPat);

    return (fPos != string::npos && rPos != string::npos &&
            fPos == 0 && fPos + frontPat.length() <= rPos && rPos + rearPat.length() == input.length());
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> pattern;
    vector<string> patterns = split(pattern, '*');

    for (int _ = 0; _ < N; _++) {
        cin >> input;
        if (ExaminePattern(input, patterns))
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}