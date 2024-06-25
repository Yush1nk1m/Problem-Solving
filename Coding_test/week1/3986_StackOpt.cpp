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