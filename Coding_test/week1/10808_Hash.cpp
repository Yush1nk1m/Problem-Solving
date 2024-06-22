/**
 * @file 10808_Hash.cpp
 * @brief 00:02:32
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

map<char, int> characters;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (char c = 'a'; c <= 'z'; c++)
        characters[c] = 0;

    string input;
    cin >> input;

    for (char c : input)
        characters[c]++;

    for (char c = 'a'; c <= 'z'; c++)
        cout << characters[c] << ' ';

    return 0;
}