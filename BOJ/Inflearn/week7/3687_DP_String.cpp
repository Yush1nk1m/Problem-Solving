/**
 * @file 3687_DP_String.cpp
 * @brief 00:33:01
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF "11111111111111111111111111111111111111111111111112"

int T, m;
int match[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
vector<string> minTable(101, ""), maxTable(101, "");

inline string Min(string& s1, string& s2);
inline string Max(string& s1, string& s2);
string MinDFS(int m);
string MaxDFS(int m);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> m;
        cout << MinDFS(m) << ' ' << MaxDFS(m) << '\n';
    }

    return 0;
}

inline string Min(string s1, string s2) {
    if (s1.length() < s2.length())
        return s1;
    else if (s1.length() > s2.length())
        return s2;
    else {
        if (s1 <= s2)
            return s1;
        else
            return s2;
    }
}

inline string Max(string s1, string s2) {
    if (s1.length() > s2.length())
        return s1;
    else if (s1.length() < s2.length())
        return s2;
    else {
        if (s1 >= s2)
            return s1;
        else
            return s2;
    }
}

string MinDFS(int m) {
    if (m == 0)
        return "";

    if (minTable[m] != "")
        return minTable[m];

    string prev;
    string& ret = minTable[m];
    ret = INF;

    if (m >= match[0] && m - match[0] != 1) {
        prev = MinDFS(m - match[0]);
        if (prev.length() > 0 && prev[0] != '0')
            ret = Min(ret, prev + "0");
    }
    for (int n = 1; n <= 9; n++)
        if (m >= match[n] && m - match[n] != 1) {
            prev = MinDFS(m - match[n]);
            ret = Min(ret, prev + to_string(n));
        }
    return ret;
}

string MaxDFS(int m) {
    if (m == 0)
        return "";

    if (maxTable[m] != "")
        return maxTable[m];

    string prev;
    string& ret = maxTable[m];

    if (m >= match[0] && m - match[0] != 1) {
        prev = MaxDFS(m - match[0]);
        if (prev.length() > 0 && prev[0] != '0')
            ret = Max(ret, prev + "0");
    }
    for (int n = 1; n <= 9; n++)
        if (m >= match[n] && m - match[n] != 1) {
            prev = MaxDFS(m - match[n]);
            ret = Max(ret, prev + to_string(n));
        }

    return ret;
}