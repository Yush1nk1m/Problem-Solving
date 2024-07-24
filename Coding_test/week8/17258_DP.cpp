/**
 * @file 17258_DP.cpp
 * @brief 00:28:24
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int N, M, K, T;
vector<int> people;
vector<vector<vector<int>>> table(301, vector<vector<int>>(301, vector<int>(301, NONE)));

int DFS(int curr, int friends, int remain);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> T;
    people.resize(N + 1, 0);
    for (int _ = 0; _ < M; _++) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++)
            people[i]++;
    }

    cout << DFS(1, 0, K);
    
    return 0;
}

int DFS(int curr, int friends, int remain) {
    if (curr > N)
        return 0;

    int& ret = table[curr][friends][remain];
    if (ret != NONE)
        return ret;

    if (people[curr] < T)
        for (int n = 0; n <= remain; n++) {
            if (people[curr] + friends + n >= T)
                ret = max(ret, DFS(curr + 1, friends + n, remain - n) + 1);
            else
                ret = max(ret, DFS(curr + 1, friends + n, remain - n));
        }
    else
        ret = DFS(curr + 1, 0, remain) + 1;

    return ret;
}