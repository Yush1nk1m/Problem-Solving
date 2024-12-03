#include <bits/stdc++.h>
using namespace std;

string S, K;
vector<int> failure;

inline vector<int> getFailure(string& pattern);
inline bool search(string& target, string& pattern);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> K;
    cout << search(S, K);

    return 0;
}

inline vector<int> getFailure(string& pattern) {
    vector<int> failure(pattern.length(), 0);
    int i = 1, j = 0;
    while (i < pattern.length()) {
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

inline bool search(string& target, string& pattern) {
    vector<int> failure = getFailure(pattern);
    int i = 0, j = 0;
    while (i < target.length()) {
        if (target[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.length())
                return true;
        } else if ('0' <= target[i] && target[i] <= '9') {
            i++;
        } else if (j > 0) {
            j = failure[j-1];
        } else {
            i++;
        }
    }
    return false;
}