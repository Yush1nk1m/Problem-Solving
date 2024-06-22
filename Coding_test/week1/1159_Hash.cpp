/**
 * @file 1159_Hash.cpp
 * @brief 00:04:54
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

    int N;
    cin >> N;

    for (char c = 'a'; c <= 'z'; c++)
        characters[c] = 0;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        characters[name[0]]++;
    }

    bool isExist = false;
    for (char c = 'a'; c <= 'z'; c++)
        if (characters[c] >= 5) {
            cout << c;
            isExist = true;
        }

    if (!isExist)
        cout << "PREDAJA";

    return 0;
}