/**
 * @file 10988_String.cpp
 * @brief 00:02:24
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    string input;
    cin >> input;

    int size = input.size();
    for (int i = 0; i < size / 2; i++)
        if (input[i] != input[size - 1 - i]) {
            cout << 0;
            return 0;
        }

    cout << 1;
    return 0;
}