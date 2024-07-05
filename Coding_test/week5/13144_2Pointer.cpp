/**
 * @file 13144_2Pointer.cpp
 * @brief 00:15:03
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SIZE 100001

int N, l, r;
ll cnt;
bool visited[SIZE];
vector<int> seq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    
    while (r < seq.size()) {
        while (visited[seq[r]])
            visited[seq[l++]] = false;
        visited[seq[r++]] = true;
        cnt += (r - l);
    }

    cout << cnt;

    return 0;
}