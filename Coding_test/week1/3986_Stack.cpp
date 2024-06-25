/**
 * @file 3986_Stack.cpp
 * @brief 00:43:22
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 문자열을 앞에서부터 뒤로 탐색하며 스택에 넣고, 뒤에서부터 앞으로 탐색하며 스택에 넣는다.
 * 이때 탐색 중 연이어 있는 두 개의 같은 글자는 제거한다. 이러면 대칭 여부만 검사할 수 있게 된다.
 * 이후 두 스택의 top에 있는 원소가 같지 않은지를 비교하여 대칭 여부만을 검사한다.
 * 중복되는 검사가 포함되므로 더 최적화할 수 있는 알고리즘이다.
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