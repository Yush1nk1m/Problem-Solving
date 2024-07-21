#include <bits/stdc++.h>
using namespace std;

int N, M, C;
vector<int> jewel;
vector<vector<vector<int>>> table;      // [bag][curr weight][selected]

int DFS(int b, int w, int selected);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;
    
    jewel.resize(N);
    for (int i = 0; i < N; i++)
        cin >> jewel[i];

    table.resize(M, vector<vector<int>>(C + 1, vector<int>(1 << N, 0)));
    cout << DFS(0, C, 0);

    return 0;
}

int DFS(int b, int w, int selected) {
    if (b == M)
        return 0;

    if (table[b][w][selected])
        return table[b][w][selected];

    int& ret = table[b][w][selected];
    ret = max(ret, DFS(b + 1, C, selected));
    for (int i = 0; i < N; i++)
        if (!(selected & (1 << i)) && w - jewel[i] >= 0)
            ret = max(ret, DFS(b, w - jewel[i], selected | (1 << i)) + 1);

    return ret;
}