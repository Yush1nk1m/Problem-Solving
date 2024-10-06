/**
 * @file 4358_Hash.cpp
 * @brief 00:05:22
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int total;
map<string, int> m;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    while (getline(cin, name)) {
        if (m.find(name) != m.end()) {
            m[name]++;
        } else {
            m[name] = 1;
        }
        total++;
    }

    for (auto it : m) {
        cout << it.first << ' ';
        cout << fixed << setprecision(4) << (double)it.second * 100 / total << '\n';
    }

    return 0;
}