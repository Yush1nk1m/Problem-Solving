/**
 * @file 2109_GreedyOpt.cpp
 * @brief 00:45:02
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * O(NlogN) Greedy algorithm
 */
#include <bits/stdc++.h>
using namespace std;

class Schedule {
    public:
        int d;
        int p;
        bool operator<(const Schedule& s) {
            if (d == s.d)
                return (p < s.p);
            return (d < s.d);
        }
};

int n, pay;
vector<Schedule> schedules;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    schedules.resize(n);
    for (int i = 0; i < n; i++)
        cin >> schedules[i].p >> schedules[i].d;
    sort(schedules.begin(), schedules.end());

    for (Schedule& s : schedules) {
        if (s.d <= pq.size())
            pq.pop();
        pq.push(s.p);
    }

    while (pq.size()) {
        pay += pq.top();
        pq.pop();
    }

    cout << pay;

    return 0;
}