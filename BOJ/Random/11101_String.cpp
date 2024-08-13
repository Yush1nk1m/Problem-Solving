/**
 * @file 11101_String.cpp
 * @brief 00:13:02
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int T;
string condition, requirement;

inline vector<string> Split(string& input, char delim);
inline void Solve(string& condition, string& requirement);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> condition >> requirement;
        Solve(condition, requirement);
    }

    return 0;
}

inline vector<string> Split(string& input, char delim) {
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, delim))
        tokens.push_back(token);

    return tokens;
}

inline void Solve(string& condition, string& requirement) {
    map<string, int> m;

    vector<string> conditions = Split(condition, ',');
    for (string& info : conditions) {
        vector<string> v = Split(info, ':');
        m[v[0]] = stoi(v[1]);
    }

    vector<string> requirements = Split(requirement, '|');
    int minTime = INF;
    for (string& req : requirements) {
        int maxTime = 0;
        vector<string> chunks = Split(req, '&');
        for (string& chunk : chunks)
            maxTime = max(maxTime, m[chunk]);
        minTime = min(minTime, maxTime);
    }

    cout << minTime << '\n';
}