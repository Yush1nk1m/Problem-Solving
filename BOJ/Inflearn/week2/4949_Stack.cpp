/**
 * @file 4949_Stack.cpp
 * @brief 00:08:34
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

string line;

inline bool CheckBalance(string line);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (getline(cin, line)) {
        if (line == ".") break;
        if (CheckBalance(line)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

inline bool CheckBalance(string line) {
    stack<char> stk;

    for (char c : line) {
        if (c == '(' || c == '[')
            stk.push(c);
        else if (c == ')') {
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
            else return false;
        }
        else if (c == ']') {
            if (!stk.empty() && stk.top() == '[')
                stk.pop();
            else return false;
        }
    }

    return (stk.empty());
}