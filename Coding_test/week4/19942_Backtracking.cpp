/**
 * @file 19942_Backtracking.cpp
 * @brief 00:39:21
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

typedef struct {
    int p;
    int f;
    int s;
    int v;
    int cost;
} Nut;

int N, mp, mf, ms, mv, cp, cf, cs, cv, cost;
int minCost = INF;
vector<int> temp;
vector<int> minAnswer;
vector<Nut> nuts;

void DFS(int start);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nuts.resize(N);
    
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++)
        cin >> nuts[i].p >> nuts[i].f >> nuts[i].s >> nuts[i].v >> nuts[i].cost;

    DFS(0);

    if (minCost == INF) {
        cout << -1;
    } else {
        cout << minCost << '\n';
        for (int number : minAnswer)
            cout << number << ' ';
    }

    return 0;
}

void DFS(int start) {
    if (mp <= cp && mf <= cf && ms <= cs && mv <= cv && cost < minCost) {
        minCost = cost;
        minAnswer = temp;
        return;
    } else if (mp <= cp && mf <= cf && ms <= cs && mv <= cv && cost > minCost) {
        return;
    }

    for (int i = start; i < N; i++) {
        cp += nuts[i].p;
        cf += nuts[i].f;
        cs += nuts[i].s;
        cv += nuts[i].v;
        cost += nuts[i].cost;
        temp.push_back(i + 1);
        DFS(i + 1);
        temp.pop_back();
        cp -= nuts[i].p;
        cf -= nuts[i].f;
        cs -= nuts[i].s;
        cv -= nuts[i].v;
        cost -= nuts[i].cost;
    }
}