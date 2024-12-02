/**
 * @file 1305_KMP.cpp
 * @brief 00:25:01
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int L;
string line;
vector<int> failure;

inline vector<int> getFailure(string& pattern);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> line;
    failure = getFailure(line);
        
    cout << L - failure[L-1];

    return 0;
}

inline vector<int> getFailure(string& pattern) {
    vector<int> failure(L, 0);

    int i = 1, j = 0;
    while (i < L) {
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = failure[j-1];
        } else {
            i++;
        }
    }

    return failure;
}