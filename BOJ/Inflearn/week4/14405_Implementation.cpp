/**
 * @file 14405_Implementation.cpp
 * @brief 00:08:38
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int i, len;
string S;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    len = S.length();
    while (i < len) {
        if (i + 1 < len) {
            string sub = S.substr(i, 2);
            if (sub == "pi") {
                i += 2;
                continue;
            }
            else if (sub == "ka") {
                i += 2;
                continue;
            }
        }

        if (i + 2 < len) {
            string sub = S.substr(i, 3);
            if (sub == "chu") {
                i += 3;
                continue;
            }
        }
        
        break;
    }

    if (i >= S.length())
        cout << "YES";
    else
        cout << "NO";
}