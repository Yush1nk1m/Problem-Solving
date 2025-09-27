/**
 * @file 9935_Stack.cpp
 * @brief 00:19:31
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE -1

string str, pat;
int pi;
stack<pair<char, int>> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str >> pat;
    pi = pat.length() - 1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (pat[pi] == str[i]) {
            stk.push({ str[i], pi-- });
            if (pi == NONE) {
                for (int _ = 0; _ < pat.length(); _++)
                    stk.pop();
                
                if (!stk.empty() && stk.top().second != NONE)
                    pi = stk.top().second - 1;
                else
                    pi = pat.length() - 1;
            }
        } else {
            pi = pat.length() - 1;
            if (pat[pi] == str[i])
                stk.push({ str[i], pi-- });
            else
                stk.push({ str[i], NONE });
        }
    }
    
    if (stk.empty())
        cout << "FRULA";
    else
        while (!stk.empty()) {
            cout << stk.top().first;
            stk.pop();
        }

    return 0;
}