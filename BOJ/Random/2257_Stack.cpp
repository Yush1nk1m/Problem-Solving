/**
 * @file 2257_Stack.cpp
 * @brief 00:32:10
 * @date 2024-10-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

string input;
stack<int> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for (char c : input) {
        if (c == 'H')
            stk.push(1);
        else if (c == 'C')
            stk.push(12);
        else if (c == 'O')
            stk.push(16);
        else if (c == '(')
            stk.push(-1);
        else if ('2' <= c && c <= '9') {
            int t = stk.top();
            stk.pop();
            stk.push(t * (c - '0'));
        }
        else if (c == ')') {
            int sum = 0;
            while (stk.top() != -1) {
                sum += stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(sum);
        }
    }

    int sum = 0;
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }

    cout << sum;

    return 0;
}