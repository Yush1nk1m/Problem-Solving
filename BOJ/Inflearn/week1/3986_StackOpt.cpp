/**
 * @file 3986_StackOpt.cpp
 * @brief 
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 스택 상단에 있는 문자와 새로 삽입할 문자를 비교한다.
 * 일치할 경우엔 겹치는 선분 없이 페어가 형성된 것이므로 스택에서 원소를 제거한다.
 * 이런 식으로 반복한 이후 스택에 원소가 남아 있으면 겹치는 선분이 있다는 의미이다.
 */
#include <bits/stdc++.h>
using namespace std;

int N, cnt;

inline bool CheckGoodWord(string word) {
    int len = word.length();
    if (len % 2 != 0) return false;

    stack<char> stk;
    for (char c : word) {
        if (!stk.empty() && stk.top() == c) stk.pop();
        else stk.push(c);
    }

    return (stk.empty());
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        string word;
        cin >> word;

        cnt += CheckGoodWord(word);
    }

    cout << cnt;

    return 0;
}