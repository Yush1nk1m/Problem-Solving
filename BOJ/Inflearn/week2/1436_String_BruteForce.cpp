/**
 * @file 1436_String_BruteForce.cpp
 * @brief 00:18:39
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int cnt, number = 666, N;

inline bool Check666(int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (; cnt < N; number++)
        if (Check666(number)) cnt++;
        
    cout << --number;

    return 0;
}

inline bool Check666(int number) {
    string numstr = to_string(number);
    return (numstr.find("666") != string::npos);
}