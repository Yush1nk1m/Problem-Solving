/**
 * @file 1063_Implementation.cpp
 * @brief 00:21:29
 * @date 2024-09-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int dr[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string loc;
pair<char, char> king, rock;
map<string, int> m;

inline void move(string& loc);
inline bool isValidPoint(pair<char, char>& loc);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    m["R"] = 0;
    m["L"] = 1;
    m["B"] = 2;
    m["T"] = 3;
    m["RT"] = 4;
    m["LT"] = 5;
    m["RB"] = 6;
    m["LB"] = 7;

    cin >> loc;
    king = { 8 - loc[1] + '0', loc[0] - 'A' };
    cin >> loc;
    rock = { 8 - loc[1] + '0', loc[0] - 'A' };

    cin >> N;
    while (N--) {
        cin >> loc;
        move(loc);
    }

    cout << (char)(king.second + 'A') << (char)(8 - king.first + '0') << '\n';
    cout << (char)(rock.second + 'A') << (char)(8 - rock.first + '0');

    return 0;
}

inline void move(string& loc) {
    int idx = m[loc];
    pair<char, char> nking = { king.first + dr[idx], king.second + dc[idx] };
    if (!isValidPoint(nking))
        return;

    pair<char, char> nrock = rock;
    if (nking.first == rock.first && nking.second == rock.second) {
        nrock = { nrock.first + dr[idx], nrock.second + dc[idx] };
        if (!isValidPoint(nrock))
            return;
    }

    king = nking;
    rock = nrock;
}

inline bool isValidPoint(pair<char, char>& loc) {
    return (0 <= loc.first && loc.first < 8 && 0 <= loc.second && loc.second < 8);
}