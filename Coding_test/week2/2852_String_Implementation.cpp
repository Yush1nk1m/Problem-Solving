/**
 * @file 2852_String_Implementation.cpp
 * @brief 00:49:27
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int scores[3], minutes[3], seconds[3];
string prevT = "00:00";
vector<pair<string, int>> records;

inline vector<string> split(string input, char delim);
inline pair<int, int> CalcDiff(string t1, string t2);
inline void PrintTime(int minute, int second);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        string tstr;
        int team;
        cin >> team >> tstr;
        records.push_back({ tstr, team });
    }
    sort(records.begin(), records.end());

    for (pair<string, int>& record : records) {
        string currT = record.first;
        int team = record.second;
        pair<int, int> diff = CalcDiff(prevT, currT);

        if (scores[1] > scores[2]) {
            minutes[1] += diff.first;
            seconds[1] += diff.second;
        } else if (scores[1] < scores[2]) {
            minutes[2] += diff.first;
            seconds[2] += diff.second;
        }

        scores[team]++;
        prevT = currT;
    }

    pair<int, int> diff = CalcDiff(prevT, "48:00");

    if (scores[1] > scores[2]) {
        minutes[1] += diff.first;
        seconds[1] += diff.second;
    } else if (scores[1] < scores[2]) {
        minutes[2] += diff.first;
        seconds[2] += diff.second;
    }

    minutes[1] += seconds[1] / 60;
    seconds[1] %= 60;
    minutes[2] += seconds[2] / 60;
    seconds[2] %= 60;

    PrintTime(minutes[1], seconds[1]);
    PrintTime(minutes[2], seconds[2]);

    return 0;
}

inline vector<string> split(string input, char delim) {
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, delim))
        tokens.push_back(token);

    return tokens;
}

inline pair<int, int> CalcDiff(string t1, string t2) {
    if (t1 > t2) {
        string temp = t1;
        t1 = t2;
        t2 = temp;
    }

    vector<string> res1 = split(t1, ':');
    vector<string> res2 = split(t2, ':');

    int m1 = stoi(res1[0]), s1 = stoi(res1[1]);
    int m2 = stoi(res2[0]), s2 = stoi(res2[1]);

    pair<int, int> result = { 0, 0 };
    result.first = m2 - m1;
    
    if (s1 > s2) {
        result.first--;
        result.second = 60 - s1 + s2;
    } else result.second = s2 - s1;

    return result;
}

inline void PrintTime(int minute, int second) {
    if (minute < 10) cout << '0';
    cout << minute << ':';
    if (second < 10) cout << '0';
    cout << second << '\n';
}