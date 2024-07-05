/**
 * @file 1700_Greedy.cpp
 * @brief 00:46:48
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
vector<int> seq;
vector<bool> plug;
vector<queue<int>> nextidx;

inline int FindCandidate();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    seq.resize(K);
    plug.resize(K + 1, false);
    nextidx.resize(K + 1);
    
    for (int i = 0; i < K; i++) {
        cin >> seq[i];
        nextidx[seq[i]].push(i);
    }

    int i = 0;
    while (N > 0 && i < K) {
        if (!plug[seq[i]]) {
            plug[seq[i]] = true;
            N--;
        }
        nextidx[seq[i]].pop();
        i++;
    }

    while (i < K) {
        nextidx[seq[i]].pop();
        if (!plug[seq[i]]) {
            cnt++;
            int victim = FindCandidate();
            plug[victim] = false;
            plug[seq[i]] = true;
        }
        i++;
    }

    cout << cnt;

    return 0;
}

inline int FindCandidate() {
    int maxv = 0, victim = -1;
    for (int i = 1; i <= K; i++)
        if (plug[i]) {
            if (!nextidx[i].size())
                return i;

            if (maxv < nextidx[i].front()) {
                maxv = nextidx[i].front();
                victim = i;
            }
        }

    return victim;
}