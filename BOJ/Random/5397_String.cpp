/**
 * @file 5397_String.cpp
 * @brief 00:21:15
 * @date 2024-08-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define SIZE    1000000

int T;
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int i = 0;
        stack<char> stk;
        string command;
        string password(SIZE, '\0');

        cin >> command;

        for (char c : command) {
            if (c == '<') {
                if (i > 0) {
                    stk.push(password[--i]);
                }
            } else if (c == '>') {
                if (!stk.empty()) {
                    password[i++] = stk.top();
                    stk.pop();
                }
            } else if (c == '-') {
                i = max(0, i - 1);
            } else {
                password[i++] = c;
            }
        }
        while (!stk.empty()) {
            password[i++] = stk.top();
            stk.pop();
        }

        cout << password.substr(0, i) << '\n';
    }
    
    return 0;
}