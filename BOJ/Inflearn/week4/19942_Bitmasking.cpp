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

int N, mp, mf, ms, mv;
int bound = 1;
int minCost = INF;
vector<vector<int>> minMasks;
vector<Nut> nuts;

inline void Combination();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nuts.resize(N);
    for (int s = 0; s < N; s++)
        bound += (1 << s);
    
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++)
        cin >> nuts[i].p >> nuts[i].f >> nuts[i].s >> nuts[i].v >> nuts[i].cost;

    Combination();

    if (minCost == INF) {
        cout << -1;
    } else {
        cout << minCost << '\n';
        sort(minMasks.begin(), minMasks.end());
        for (int number : minMasks[0])
            cout << number << ' ';
    }

    return 0;
}

inline void Combination() {
    int mask = 1;
    while ((mask & bound) != bound) {
        vector<int> maskv;
        int cp, cf, cs, cv, cost;
        cp = cf = cs = cv = cost = 0;
        for (int shift = 0; shift < N; shift++)
            if (mask & (1 << shift)) {
                cp += nuts[shift].p;
                cf += nuts[shift].f;
                cs += nuts[shift].s;
                cv += nuts[shift].v;
                cost += nuts[shift].cost;
                maskv.push_back(shift + 1);
            }
        if (mp <= cp && mf <= cf && ms <= cs && mv <= cv) {
            if (cost < minCost) {
                minCost = cost;
                minMasks.clear();
                minMasks.push_back(maskv);
            } else if (cost == minCost) {
                minMasks.push_back(maskv);
            }
        }
        mask++;
    }
}