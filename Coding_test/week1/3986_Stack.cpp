/**
 * @file 3986_Stack.cpp
 * @brief 00:43:22
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define A 'A'
#define B 'B'

int N, cnt;
vector<string> words;

inline bool CheckGoodWord(string word) {
    int len = word.length();
    if (len % 2 != 0) return false;
    stack<char> forwardStk, backwardStk;

    for (int i = 0; i < len; i++) {
        if (!forwardStk.empty() && forwardStk.top() == word[i])
            forwardStk.pop();
        else
            forwardStk.push(word[i]);
    }

    for (int i = len - 1; i >= 0; i--) {
        if (!backwardStk.empty() && backwardStk.top() == word[i])
            backwardStk.pop();
        else
            backwardStk.push(word[i]);
    }

    while (!forwardStk.empty() && !backwardStk.empty()) {
        if (forwardStk.top() == backwardStk.top()) {
            forwardStk.pop();
            backwardStk.pop();
        } else return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    words.resize(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];

    for (string word : words)
        cnt += CheckGoodWord(word);

    cout << cnt;

    return 0;
}