#include <bits/stdc++.h>
using namespace std;

int N, M, rmid, cmid, dist;
vector<int> r, c;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    r.resize(M);
    c.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> r[i];
        cin >> c[i];
    }

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    rmid = r[M / 2];
    cmid = c[M / 2];

    for (int i = 0; i < M; i++)
        dist += abs(rmid - r[i]) + abs(cmid - c[i]);

    cout << dist;

    return 0;
}