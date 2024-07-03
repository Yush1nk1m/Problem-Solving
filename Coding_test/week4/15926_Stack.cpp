/**
 * @file 15926_Stack.cpp
 * @brief 00:57:53
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, len, maxLen;
string pstr;
vector<bool> p;
stack<int> istk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> pstr;

    p.resize(N, false);
    for (int i = 0; i < N; i++) {
        if (pstr[i] == '(')
            istk.push(i);
        else if (!istk.empty()) {
            p[i] = p[istk.top()] = true;
            istk.pop();
        }
    }

    for (bool isPstr : p) {
        if (isPstr) {
            len++;
        } else {
            maxLen = max(maxLen, len);
            len = 0;
        }
    }
    maxLen = max(maxLen, len);

    cout << maxLen;

    return 0;
}