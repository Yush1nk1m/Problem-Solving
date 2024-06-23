/**
 * @file 1620_Hash_String.cpp
 * @brief 00:09:10
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, string> names;
map<string, int> ids;

inline bool isNumeric(string& input) {
    for (char c : input)
        if (!isdigit(c))
            return false;
    return true;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        names[i] = name;
        ids[name] = i;
    }

    for (int _ = 0; _ < M; _++) {
        string input;
        cin >> input;

        if (isNumeric(input))
            cout << names[stoi(input)] << '\n';
        else
            cout << ids[input] << '\n';
    }

    return 0;
}