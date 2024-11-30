/**
 * @file 1786_KMP.cpp
 * @brief 01:01:19
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

string line, pattern;
vector<int> failure, indices;

inline vector<int> getFailure();
inline int match();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, line);
    getline(cin, pattern);

    failure = getFailure();

    cout << match() << '\n';
    for (int idx : indices)
        cout << idx << ' ';

    return 0;
}

inline vector<int> getFailure() {
    vector<int> failure(pattern.length());

    failure[0] = 0;
    int i = 1, j = 0;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = failure[j-1];
        } else {
            failure[j] = 0;
            i++;
        }
    }

    return failure;
}

inline int match() {
    int cnt = 0;
    int i = 0, j = 0;

    while (i < line.length()) {
        if (line[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.length()) {
                cnt++;
                indices.push_back(i - j + 1);
                j = failure[j-1];
            }
        } else if (j > 0) {
            j = failure[j-1];
        } else {
            i++;
        }
    }

    return cnt;
}
