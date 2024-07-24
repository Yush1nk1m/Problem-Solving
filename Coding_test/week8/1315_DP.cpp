/**
 * @file 1315_DP.cpp
 * @brief 00:59:54
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define NONE    -1

class Quest {
    public:
        int STR;
        int INT;
        int PNT;
};

int N;
ll visited;
vector<Quest> quest;
vector<vector<int>> table(1001, vector<int>(1001, NONE));

int DFS(int STR, int INT);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    quest.resize(N);
    for (int i = 0; i < N; i++)
        cin >> quest[i].STR >> quest[i].INT >> quest[i].PNT;

    cout << DFS(1, 1);

    return 0;
}

int DFS(int STR, int INT) {
    if (table[STR][INT] != NONE)
        return table[STR][INT];

    ll temp = visited;
    int p = 0;
    int& ret = table[STR][INT];
    ret = 0;
    for (int i = 0; i < N; i++)
        if (STR >= quest[i].STR || INT >= quest[i].INT) {
            ret++;
            if (visited & (1LL << i)) continue;
            visited |= (1LL << i);
            p += quest[i].PNT;
        }
    
    for (int pnt = 0; pnt <= p; pnt++)
        ret = max(ret, DFS(min(1000, STR + pnt), min(1000, INT + (p - pnt))));

    visited = temp;

    return ret;
}