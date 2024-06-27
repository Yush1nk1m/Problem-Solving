/**
 * @file 9012_Stack.cpp
 * @brief 00:04:19
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T;
string input;

inline bool CheckVPS(string input);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> input;
        if (CheckVPS(input)) cout << "YES\n";
        else cout << "NO\n";
    }
}

inline bool CheckVPS(string input) {
    stack<char> stk;
    
    for (char c : input) {
        if (c == '(')
            stk.push(c);
        else if (!stk.empty() && stk.top() == '(')
            stk.pop();
        else return false;
    }

    return (stk.empty());
}