/**
 * @file 14469_Greedy.cpp
 * @brief 00:05:17
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, t;
vector<pair<int, int>> schedule;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    schedule.resize(N);
    for (int i = 0; i < N; i++)
        cin >> schedule[i].first >> schedule[i].second;
    sort(schedule.begin(), schedule.end());

    for (pair<int, int> s : schedule) {
        int arrive = s.first, need = s.second;
        if (t < arrive)
            t = arrive;
        t += need;
    }

    cout << t;

    return 0;
}