/**
 * @file 1701_String_KMP.cpp
 * @brief 01:05:14
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

string input;

inline int solve(string input);
inline bool kmpSearch(string input, string pattern);
inline vector<int> getFailure(string pattern);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    cout << solve(input);

    return 0;
}

inline int solve(string input) {
    int result = 0;

    for (int i = 0; i < input.length() - 1; i++) {
        vector<int> failure = getFailure(input.substr(i));
        result = max(result, *max_element(failure.begin(), failure.end()) + 1);
    }

    return result;
}

inline vector<int> getFailure(string pattern) {
    vector<int> failure(pattern.length(), -1);

    int i, j;
    for (int i = 1; i < pattern.length(); i++) {
        j = failure[i - 1];

        while ((pattern[i] != pattern[j + 1]) && (j >= 0))
            j = failure[j];

        if (pattern[i] == pattern[j + 1])
            failure[i] = j + 1;
        else
            failure[i] = -1;
    }

    return failure;
}