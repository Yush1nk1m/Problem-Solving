/**
 * @file 15353_String.cpp
 * @brief 00:11:23
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

bool carry;
int len1, len2;
string n1, n2;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n1 >> n2;
    if (n1.length() < n2.length()) {
        string temp = n1;
        n1 = n2;
        n2 = temp;
    }
    len1 = n1.length();
    len2 = n2.length();

    while (len1 != len2) {
        n2 = "0" + n2;
        len2++;
    }

    string res = "";
    for (int i = len1 - 1; i >= 0; i--) {
        char digit = '0' + (((n1[i] - '0') + (n2[i] - '0') + carry) % 10);
        res = digit + res;
        if ((n1[i] - '0') + (n2[i] - '0') + carry >= 10)
            carry = 1;
        else
            carry = 0;
    }

    if (carry)
        res = "1" + res;

    cout << res;

    return 0;
}